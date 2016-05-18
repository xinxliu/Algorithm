#include "dtw.hpp"
int minx(int a, int b, int c) {
	int min = a < b ? a : b;
	min = min < c ? min : c;
	return min;
}

int dist(int m, int n, char* a, char* b) {
	if (a[m] != b[n]) {
		return 1;
	}
	return 0;
}

int dtw_lookup_table(M_type& d, int m, int n, char* a, char* b) {
	if (d[m][n] < INT_MAX) {
		return d[m][n];
	}
	return dist(m, n, a, b) + minx(dtw_lookup_table(d, m - 1, n - 1, a, b),
		dtw_lookup_table(d, m - 1, n, a, b), dtw_lookup_table(d, m, n - 1, a, b));
}

int dtw(int m, int n, char * a, char * b) {
	vector<vector<int>> d(m, vector<int>(n, INT_MAX));
	d[0][0] = dist(0, 0, a, b);
	for (int i = 1; i < m; ++i) {
		d[i][0] = dist(i, 0, a, b) + d[i - 1][0];
	}
	for (int i = 1; i < n; ++i) {
		d[0][i] = dist(0, i, a, b) + d[0][i - 1];
	}
	return dtw_lookup_table(d, m - 1, n - 1, a, b);
}

//from bottom to up
int btu_dtw(int m, int n, char *a, char *b) {
	vector<vector<int>> d(m, vector<int>(n, INT_MAX));
	d[0][0] = dist(0, 0, a, b);
	for (int i = 1; i < m; ++i) {
		d[i][0] = dist(i, 0, a, b) + d[i - 1][0];
	}
	for (int i = 1; i < n; ++i) {
		d[0][i] = dist(0, i, a, b) + d[0][i - 1];
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			d[i][j] = dist(i, j, a, b) + minx(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]);
		}
	}
	return d[m - 1][n - 1];
}

