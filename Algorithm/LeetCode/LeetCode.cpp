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

int LIS_1(int A[], int n){
	vector<int> maxlength(n, 0);
	maxlength[0] = 1;
	int maxLength = maxlength[0];
	for (int i = 1; i < n; ++i) {
		int max = 0;
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i]&& maxlength[j] > max) {
				max = maxlength[j];
				
			}
		}
		maxlength[i] = max + 1;
		maxLength = maxlength[i] > maxLength ? maxlength[i] : maxLength;
	}
	return maxLength;
}
