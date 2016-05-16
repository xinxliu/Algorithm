#ifndef _DP_HPP_X_
#define _DP_HPP_X_
#include<cmath>
#include <iostream>
#include <vector>
#include <limits.h>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

const auto maximum = -INFINITY;
const auto minimum = -INFINITY;

/**
*@brief an implement of the problem CUT-ROD
*@author xinxliu
*/
int cut_rod(int* p, int n);

//Fibonacci sequence
int fib(int n);

int fib_lookup_table(int n, int *f);

int memoized_dp_fib(int n);

int bt_dp_fib(int n);

/********************************************************************/
/*Dynamic Time Wrapping*/

//common utility
typedef vector<vector<int>> M_type;

int minx(int a, int b, int c);

int dist(int m, int n, char* a, char* b);

int dtw_lookup_table(M_type& d, int m, int n, char* a, char* b);

int dtw(int m, int n, char* a, char* b);

int btu_dtw(int m, int n, char *a, char *b);
#endif