#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main() {
	ivaparm(0);
	ivaparm(1,6);
	ivaparm(2, 5, 12);
	ivaparm(6, 12, 8, 23, 7, -5, 0);

	short n = 0;
	svarparm(n);
	n = 1;
	svarparm(n, 8);
	n = 2;
	svarparm(n, 34, 5);
	n = 6;
	svarparm(n, 33, 2, 8, 56, 12, -55);

	fvarparm(FLT_MAX);
	fvarparm(1.3, FLT_MAX);
	fvarparm(2.3,-4.3,FLT_MAX);
	fvarparm(2.4, 11.2, 34.1, -2.4, 11.3, 5.6, FLT_MAX);

	dvarparm(DBL_MAX);
	dvarparm(1.3, DBL_MAX);
	dvarparm(2.3, -4.3, DBL_MAX);
	dvarparm(2.4, 11.2, 34.1, -2.4, 11.3, 5.6, DBL_MAX);

	return 0;
}