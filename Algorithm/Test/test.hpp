#ifndef _X_TEST_HPP_
#define _X_TEST_HPP_

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//utilities
int min(int a, int b);
int abs(int a);
int AreaTriangle_(int x1, int y1, int x2, int y2, int x3, int y3);

//longest chain
//Time Complexity:O(n^2),Space Complexity:O(n)
int LC(int A[], int n);

//distance between two string
//the following operations on string can be one step:
//add, replace, delete
//Time Complexity:O(m*n), space Complexity:O(m*n)
int distance(char a[], char b[], int m, int n);

//Area of a polygon. Coordinates are input in clockwise
//Time Complexity:O(n), Space Complexity:O(1)
int Area(int n);

//the largest area
//Time Complexity:O(n^2), Time Space Complexity:O(1)
int LA(vector<int> A);
#endif
