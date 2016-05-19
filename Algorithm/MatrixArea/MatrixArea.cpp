#include "MatrixArea.hpp"

Matr_ MatrixArea::establishTable(Matr_ A) {
	int width = A.size();
	int height = A[0].size();

	vector<vector<int>> table(width + 1, vector<int>(height + 1, -1));
	//inilialize
	table[0][0] = 0;
	for (int j = 1; j <= height; ++j) {
		table[0][j] = A[0][j - 1] + table[0][j - 1];
	}
	for (int i = 1; i <= width; ++i) {
		table[i][0] = table[i - 1][0] + A[i - 1][0];
		for (int j = 1; j <= height; ++j) {
			table[i][j] = table[i][j - 1] + table[i - 1][j] - table[i - 1][j - 1] + A[i - 1][j - 1];
		}
	}
	return table;
}

int MatrixArea::Area(int x1, int y1, int x2, int y2){
	return Area_(x1, y1, x2, y2);
}

int MatrixArea::Area(Matr_& A, int x1, int y1, int x2, int y2) {
	Table_ = establishTable(A);
	return Area_(x1, y1, x2, y2);

}

int MatrixArea::Area_(int x1, int y1, int x2, int y2) {
	return Table_[x2 + 1][y2 + 1] + Table_[x1][y1] - Table_[x2 + 1][y1] - Table_[x1][y2 + 1];
}
