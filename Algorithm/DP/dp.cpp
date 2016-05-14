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


int lookup_table(int n, int *f) {
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
		f[n] = lookup_table(n - 1, f) + lookup_table(n - 2, f);
		return f[n];
	}
}

int memoized_dp_fib(int n) {
	const int size_ = 100;
	int f[size_];
	memset(f, 0, 100 * sizeof(int));
	return lookup_table(n, f);
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
	return f[10];
}