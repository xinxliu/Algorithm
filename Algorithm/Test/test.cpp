#include "test.hpp"

int min(int a, int b) {
	return a < b ? a : b;
}

int abs(int a){
	return a >= 0 ? a : -a;
}

int AreaTriangle_(int x1, int y1, int x2, int y2, int x3, int y3){
	int a = x2 - x1;
	int b = x3 - x1;
	int c = y2 - y1;
	int d = y3 - y1;
	return abs(a*d - b*c);
}

int LC(int A[], int n) {
	int index;
	vector<int> B(n + 1);
	for (int i = 0; i < n; ++i) {
		B[i + 1] = A[i];
	}
	int longest = 1;
	for (int i = 1; i <= n; ++i) {
		int index = i;
		int longestchain = 1;
		while (B[index] != 0) {
			++longestchain;
			index = B[index];
			if (index == i) {
				break;
			}
		}
		longest = longest > longestchain ? longest : longestchain;
	}
	return longest;
}

int distance(char a[], char b[], int m, int n) {
	vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i) {
		table[i][0] = i;
	}
	for (int j = 0; j <= n; ++j) {
		table[0][j] = j;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i - 1] == b[j - 1]) {
				table[i][j] = table[i - 1][j - 1];
			}
			else {
				int mn = min(table[i - 1][j], table[i][j - 1]);
				table[i][j] = 1 + min(mn, table[i - 1][j - 1]);
			}
		}
	}
	return table[m][n];
}

int Area(int n){
	vector<int> x(n,0);
	vector<int> y(n,0);
	int i = 0;
	int Area = 0;
	while (cin >> x[i] >> y[i]) {
		++i;
	}
	if (n < 3) {
		return 0;
	}
	for (int i = 2; i < n; ++i) {
		Area += AreaTriangle_(x[0], y[0], x[1], y[1], x[2], y[2]);
	}
	return Area;
}

int LA(vector<int> A){
	int n = A.size();
	int la = 0;
	for (int i = 0; i < n; ++i) {
		int area_i = A[i];
		for (int j = i + 1; j < n; ++j) {
			if (A[j] < A[i]) break;
			else {
				area_i += A[i];
			}
		}
		la = area_i > la ? area_i : la;
	}
	for (int i = n - 1; i >= 0; ++i) {
		int area_i = A[i];
		for (int j = i - 1; j >= 0; ++j) {
			if (A[j] < A[i]) break;
			else {
				area_i += A[i];
			}
		}
		la = area_i > la ? area_i : la;
	}
	return la;
}
