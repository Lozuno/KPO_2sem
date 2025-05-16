#include "Varparm.h"
int Varparm::ivaparm(int n, ...) {
	int* a = &n + 1;
	if (n == 0) return -1;
	int proiz = 1;
	for (int i = 0; i < n; i++) {
		proiz *= *(a+i);
	}
	return proiz;
}
int Varparm::svarparm(short n, ...) {
	int* a = (int*)(&n)+1;
	if (n == 0) return -1;
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}
double Varparm::fvarparm(float a, ...) {
	double sum = 0;
	if (a == FLT_MAX) {
		return sum;
	}
	sum += a;
	double* cur = (double*)(&a+1);
	while (*cur !=FLT_MAX) {
		sum += *cur;
		cur++;
	}
	return sum;
}
double Varparm::dvarparm(double a, ...) {
	double* cur = &a;
	double sum = 0;
	while (*cur != DBL_MAX) {
		sum += *cur;
		cur++;
	}
	return sum;
}