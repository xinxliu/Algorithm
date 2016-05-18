#include "LeetCode.hpp"

int RemoveDuplicates(int A[], int n, int OCCUR){
	int index = 0, count = 0;
	if (n <= OCCUR) {
		return n;
	}
	for (int i = 1; i < n; ++i) {
		if (A[index] != A[i]) {
			A[++index] = A[i];
			count = 0;
		}
		else if (count < OCCUR - 1) {
			++count;
			A[++index] = A[i];
		}
	}
	return index + 1;
}
