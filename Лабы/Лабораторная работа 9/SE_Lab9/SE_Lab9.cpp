#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main() {
	ivaparm(0);
	ivaparm(1,1);
	ivaparm(2, 1, 2);
	ivaparm(6, 1, 2, 3, 4, 5, 6);

	short n = 0;
	svarparm(n);
	n = 1;
	svarparm(n, 1);
	n = 2;
	svarparm(n, 1, 2);
	n = 6;
	svarparm(n, 1, 2, 3, 4, 5, 6);

	fvarparm(FLT_MAX);
	fvarparm(2.0f, FLT_MAX);
	fvarparm(2.0f, 2.0f,FLT_MAX);
	fvarparm(2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, FLT_MAX);

	dvarparm(DBL_MAX);
	dvarparm(2.0, DBL_MAX);
	dvarparm(2.0, 2.0, DBL_MAX);
	dvarparm(2.0, 2.0, 2.0, 2.0, 2.0, 2.0, DBL_MAX);

	return 0;
}