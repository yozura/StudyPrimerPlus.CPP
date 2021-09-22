#pragma once
#include <iostream>

using namespace std;

const int ArSize = 8;
const int Max = 5;

int sum_arr(int arr[], int n);
int sum_arr(const int* begin, const int* end);
int fill_array(double* ar, int limit);
void show_array(const double* ar, int n);
void revalue(double r, double* ar, int n);