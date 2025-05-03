#include "Call.h"
int _cdecl Call::cdeсl(int a, int b, int c) {
	return (a + b + c);
}
int _stdcall Call::cstd(int& a, int b, int c) {
	return (a * b * c);
}
int _fastcall Call::cfst(int a, int b, int c, int d) {
	return (a + b + c + d);
}