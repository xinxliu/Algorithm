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
	getchar();
	return 0;
}