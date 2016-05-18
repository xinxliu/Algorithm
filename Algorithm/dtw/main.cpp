#include "dtw.hpp"

int main() {
	char a[] = "university";
	char b[] = "unverstiy";
	int distance1 = dtw(sizeof(a) - 1, sizeof(b) - 1, a, b);
	cout << distance1 << endl;
	int distance2 = btu_dtw(sizeof(a) - 1, sizeof(b) - 1, a, b);
	cout << distance2 << endl;
	getchar();
	return 0;
}