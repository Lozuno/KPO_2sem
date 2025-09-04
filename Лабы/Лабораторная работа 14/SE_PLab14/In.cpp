#include "stdafx.h"
#include "In.h"
#include "Error.h"

using namespace std;

namespace In {
	IN getin(wchar_t infile[]) {
		IN in;
		in.size = 0; in.lines = 0; in.ignor = 0;
		in.text = new unsigned char[IN_MAX_LEN_TEXT];
		int col = 0;
		ifstream fin(infile);
		if (!fin.is_open()) {
			throw ERROR_THROW(110);
		}
		while (in.size<IN_MAX_LEN_TEXT-1) {
			unsigned char ch;
			ch = char(fin.get());
			if (fin.eof()) {
				break;
			}
			switch (in.code[ch]) {
			case in.T: {
				in.text[in.size] = ch;
				in.size++;
				col++;
				break;
			}
			case in.F: {
				throw ERROR_THROW_IN(111, in.lines, col);
				break;
			}
			case in.I: {
				in.ignor++;
				col++;
				break;
			}
			}
			if (ch == IN_CODE_ENDL) {
				in.lines++;
				col = 0;
			}
			}
		in.text[in.size] = '\0';
		return in;
	}
}