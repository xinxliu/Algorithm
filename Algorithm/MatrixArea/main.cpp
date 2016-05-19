#include "MatrixArea.hpp"

int main() {
	Matr_ A(5, vector<int>({ 1,2,3,4,5 }));
	MatrixArea Area_A = MatrixArea(A);
	int area = Area_A.Area(1, 1, 4, 4);
	cout << area << endl;
	getchar();
	return 0;
}