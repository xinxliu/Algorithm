#ifndef _DTW_HPP_X_
#define _DTW_HPP_X_
#include <iostream>
#include <vector>
#include <limits.h>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

//Dynamic Time Wrapping
//common utility

typedef vector<vector<int>> M_type;

int minx(int a, int b, int c);

int dist(int m, int n, char* a, char* b);

int dtw_lookup_table(M_type& d, int m, int n, char* a, char* b);

int dtw(int m, int n, char* a, char* b);

int btu_dtw(int m, int n, char *a, char *b);

#endif