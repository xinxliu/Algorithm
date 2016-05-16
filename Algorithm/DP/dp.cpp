#include "dp.hpp"

int cut_rod(int * p, int n)
{
	return 0;
}

int fib(int n) {
	if (n > 0) {
		if (n == 1 || n == 2) {
			return 1;
		}
		else {
			return fib(n - 1) + fib(n - 2);
		}
	}
	cerr << "n should be positive" << endl;
}


int fib_lookup_table(int n, int *f) {
	if (n > 0) {

		//initilize the mem
		if (f[n] > 0) {
			return f[n];
		}
		if (n == 1) {
			f[1] = 1;
			return f[1];
		}
		if (n == 2) {
			f[2] = 1;
			return f[2];
		}
		f[n] = fib_lookup_table(n - 1, f) + fib_lookup_table(n - 2, f);
		return f[n];
	}
}

int memoized_dp_fib(int n) {
	const int size_ = 100;
	int f[size_];
	memset(f, 0, 100 * sizeof(int));
	return fib_lookup_table(n, f);
}

int bt_dp_fib(int n) {
	const int size_ = 100;
	int f[size_];
	memset(f, 0, 100 * sizeof(int));
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			f[1] = 1;
		}
		else if (i == 2) {
			f[2] = 1;
		}
		else if (f[i] == 0) {
			f[i] = f[i - 1] + f[i - 2];
		}
		else {
			cerr << "lookup table is wrong" << endl;
		}
	}
	return f[n];
}
/********************************************************************/
/*Dynamic Time Wrapping*/

//common utility
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