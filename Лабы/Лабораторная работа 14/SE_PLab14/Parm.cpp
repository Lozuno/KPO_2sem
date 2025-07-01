#include "Parm.h"
#include "Error.h"
#include <iostream>
namespace Parm {
	PARM getparm(int argc, TCHAR* argv[]) {
		PARM res;
		if (argc < 2) {
			throw ERROR_THROW(100);
		}
		wchar_t buf[256];
		wcscpy_s(buf, argv[1]);
		auto flag = wcsstr(buf, PARM_IN);
		if (flag != buf || flag == NULL) {
			throw ERROR_THROW(100);
		}
		wcscpy_s(res.in, (buf + (wcslen(PARM_IN))));

		if (argc >= 3) {
			wcscpy_s(buf, argv[2]);
			flag = wcsstr(buf, PARM_OUT);
			if (flag == buf) {
				wcscpy_s(res.out, (buf + wcslen(PARM_OUT)));
			}
			else {
				wcscpy_s(res.out, res.in);
				wcscat_s(res.out, PARM_OUT_DEFAULT_EXT);
			}
		}
		else {
			wcscpy_s(res.out, res.in);
			wcscat_s(res.out, PARM_OUT_DEFAULT_EXT);
		}

		if (argc >= 4) {
			wcscpy_s(buf, argv[3]);
			flag = wcsstr(buf, PARM_LOG);
			if (flag == buf) {
				wcscpy_s(res.log, (buf + wcslen(PARM_LOG)));
			}
			else {
				wcscpy_s(res.log, res.in);
				wcscat_s(res.log, PARM_LOG_DEFAULT_EXT);
			}
		}
		else {
			wcscpy_s(res.log, res.in);
			wcscat_s(res.log, PARM_LOG_DEFAULT_EXT);
		}

		return res;
	}
}