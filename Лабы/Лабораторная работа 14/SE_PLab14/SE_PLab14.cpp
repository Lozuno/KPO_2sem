#include "stdafx.h"
#include <tchar.h>
#include <iostream>
#include <locale>
#include <cwchar>
#include "Error.h" // обработка ошибок
#include "Parm.h"// обработка параметров 
#include "Log.h" // работа с протоколом
#include "In.h"// ввод исходного файла
using namespace std;
int _tmain(int argc, TCHAR* argv[]) {

	setlocale(LC_ALL, "rus");
	cout << "---- Тест Error::geterror ---" << endl << endl;
	try { throw ERROR_THROW(100); }
	catch (Error::ERROR e)
	{
		cout << "Oшибка " << e.id << ":" << e.message << endl << endl;
	};

	cout << "---- Тест Error::geterrorin ---" << endl << endl;
	try { throw ERROR_THROW_IN(111, 7, 7); }
	catch (Error::ERROR e)
	{
		cout << "Oшибка " << e.id << ": " << e.message << ", строка " << e.inext.line << ", позиция" << e.inext.col << endl << endl;
	};
	
	cout << "---- Tест Parm::getparm ---" << endl << endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in: " << parm.in << ", -out:" << parm.out << ", -log: " << parm.log << endl << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Oшибка " << e.id << ": " << e.message << endl << endl;
	};

	
	cout << "---- Tест In::getin ---"<<endl<<endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in=In::getin(parm.in);
		cout << in.text << endl;
		cout << "Bсего символов: " << in.size << endl;
		cout << "Bсeгo строк: " << in.lines << endl;
		cout << "Пропушено: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Oшибка " << e.id << ":" << e.message << endl << endl;
		cout << "cтрока " << e.inext.line << " позиция " << e.inext.col << endl << endl;
	};

	cout << "---- Tecт In::getin ---"<< endl << endl;
	try
	{
		Parm::PARM parm=Parm::getparm(argc, argv);
		In::IN in=In::getin(parm.in);
		cout << in.text << endl;
		cout << "Bceго символов: " << in.size << endl;
		cout << "Bceгo cтрок: " << in.lines << endl;
		cout << "Пpопущено: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl;
		cout << "cтрока " << e.inext.line << " позиция " << e.inext.col << endl << endl;
	};
	cout << "---- Tecт Log ---" << endl << endl;
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест", (char*)" без ошибок \n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест", (wchar_t*)L" без ошибок \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};
	system("pause");
	return 0;
};