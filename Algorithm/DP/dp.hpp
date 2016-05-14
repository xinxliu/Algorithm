#ifndef _DP_HPP_X_
#define _DP_HPP_X_
#include<cmath>
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

const auto maximum = -INFINITY;
const auto minimum = -INFINITY;

/**
*@brief an implement of the problem CUT-ROD
*@author xinxliu
*/
int cut_rod(int* p, int n);

//Fibonacci sequence
int fib(int n);

int lookup_table(int n, int *f);

int memoized_dp_fib(int n);

int bt_dp_fib(int n);

#endif