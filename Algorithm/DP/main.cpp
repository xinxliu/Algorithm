#include "dp.hpp"

int main() {
//init the price table
	int p[11] = { 0,1,5,8,9,10,17,17,20,24,30 };
	/*for (int i = 0; i < 11; i++) {
		cout << p[i] << ",";
	}*/
	cout << memoized_dp_fib(10) << endl;
	cout << fib(10) << endl;
	cout << bt_dp_fib(10);

	char a[] = "university";
	char b[] = "unverstiy";
	int distance1 = dtw(sizeof(a) - 1, sizeof(b) - 1, a, b);
	cout << distance1 << endl;
	int distance2 = btu_dtw(sizeof(a) - 1, sizeof(b) - 1, a, b);
	cout << distance2 << endl;
	
	getchar();
	return 0;
}