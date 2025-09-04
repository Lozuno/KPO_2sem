#include "stdafx.h"

namespace Log {
	LOG getlog(wchar_t logfile[]) {
		LOG newlog;
		newlog.stream = new ofstream;
		newlog.stream->open(logfile);
		if (!newlog.stream->is_open()) {
			throw ERROR_THROW(112);

		}
		wcscpy_s(newlog.logfile, logfile);
		return newlog;
	}
	void WriteLine(LOG log, char* c, ...) {
		char** ch = &c;
		while (*ch != "") {
			*log.stream << *ch;
			ch++;	
		}
		*log.stream << '\n';
		return;
	}
	void WriteLine(LOG log, wchar_t* c, ...) {
		wchar_t** ch = &c;
		while (*ch != L"") {
			char buf[256] = "";
			wcstombs_s(0, buf, *ch, sizeof(buf));
			*log.stream << buf;
			ch++;
		}
		*log.stream << '\n';
		return;
	}	
	void WriteLog(LOG log) {
		char date[256];
		auto curtime = time(0);
		tm loctime;
		localtime_s(&loctime, &curtime);
		strftime(date, sizeof(date), "%d.%m.%Y %T", &loctime);
		WriteLine(log, (char*)("------ Протокол ------ "), date, (char*)(" ------------"),"");
		return;
	}
	void WriteParm(LOG log, Parm::PARM parm) {
		WriteLine(log, (wchar_t*)(L"------ Параметры ------"), L"");
		WriteLine(log, (wchar_t*)(L"-log: "),parm.log, L"");
		WriteLine(log, (wchar_t*)(L"-out: "), parm.out, L"");
		WriteLine(log, (wchar_t*)(L"-in: "), parm.in, L"");
	}
	void WriteIn(LOG log, In::IN in) {
		*log.stream << "------ Исходные данные ------\n";
		*log.stream << "Количество символов: " << in.size << endl;
		*log.stream << "Проигнорировано    : " << in.ignor << endl;
		*log.stream << "Количество строк   : " << in.lines << endl;
	}
	void WriteError(LOG log, Error::ERROR error) {
		if (log.stream!=NULL) {
			*log.stream << "Ошибка " << error.id << ": " << error.message;
			if (error.inext.col != -1) {
				*log.stream << ", строка " << error.inext.line << ", позиция " << error.inext.col;
			}
			*log.stream << endl;
		}
		else {
			cout << "Ошибка " << error.id << ": " << error.message;
			if (error.inext.col != -1) {
				cout << ", строка " << error.inext.line << ", позиция " << error.inext.col;
			}
			cout << endl;
		}
	}
	void Close(LOG log) {
		log.stream->close();
		delete log.stream;
	}
}