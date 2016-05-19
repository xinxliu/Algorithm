#include "LeetCode.hpp"

int main() {
	//RemoveDuplicates
	int A[15] = { 1,1,1,1,2,2,3,3,4,5,5,5,5,6,7 };
	int length1 = RemoveDuplicates(A, 15, 3);
	cout << "length1 = " << length1 << endl;


	int B[6] = { 1,4,5,3,7,2 };
	int maxlength1 = LIS_1(B, 6);
	cout << maxlength1;


	getchar();
	return 0;
}