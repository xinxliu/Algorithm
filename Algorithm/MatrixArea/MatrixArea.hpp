#ifndef _X_MATRIX_AREA_HPP_
#define _X_MATRIX_AREA_HPP_

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef vector<vector<int>> Matr_;
class MatrixArea {
public:
	MatrixArea() {}
	MatrixArea(Matr_ &A) {
		Table_ = establishTable(A);
	}
	int Area(int x1, int y1, int x2, int y2);
	int Area(Matr_& A, int x1, int y1, int x2, int y2);
private:
	Matr_ Table_;
	Matr_ establishTable(Matr_ A);
	int Area_(int x1, int y1, int x2, int y2);


};

#endif 