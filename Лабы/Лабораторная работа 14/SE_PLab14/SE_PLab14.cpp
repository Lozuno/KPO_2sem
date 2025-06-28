#include "stdafx.h"
#include <tchar.h>
#include <iostream>
#include <locale>
#include <cwchar>
#include "Error.h" // обработка ошибок
#include "Parm.h"// обработка параметров 
#include "Log.h" // работа с протоколом
#include "In.h"// ввод исходного файла
int _tmain(int argc, TCHAR* argv[]) {

	setlocale(LC_ALL, "rus"); std::cout << "---- тест Error::geterror ---" << std::endl << std::endl;
	try { throw ERROR_THROW(100); }
	catch (Error::ERROR e)
	{
		std::cout << "Oшибка " << e.id << ":" << e.message << std::endl << std::endl;
	};

	std::cout << "---- тест Error::geterrorin ---" << std::endl << std::endl;
	try { throw ERROR_THROW_IN(111, 7, 7); }
	catch (Error::ERROR e)
	{
		std::cout << "Owибка " << e.id << ": " << e.message
			<< ", строка " << e.inext.line
			<< ", позиция" << e.inext.col << std::endl << std::endl;
	};

	std::cout << "---- TеCT Parm::getparm ---" << std::endl << std::endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::wcout << "-in: " << parm.in << ", -out:" << parm.out << ", -log: " << parm.log << std::endl << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "Ownбка " << e.id << ": " << e.message << std::endl << std::endl;
	};


	std::cout << "---- TECT In::getin ---"<<std::endl<<std::endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in=In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "Bсего символов: " << in.size << std::endl;
		std::cout << "Bсeгo строк: " << in.lines << std::endl;
		std::cout << "Пропушено: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "Owибка " << e.id << ":" << e.message << std::endl << std::endl;
	};
ч

	std::cout << "---- Tecт In::getin ---"<< std::endl << std::endl;
		try
	{
		Parm::PARM parm
		Parm::getparm(argc, argv);
		In::IN in In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "Bceго символов: " << < in.size << std::endl; std::cout << "Bceгo cтрOK: " << < in.lines << std::endl; std::cout << "Пpопушено: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "Owибка " << e.id << ": " << e.message << std::endl; std::cout << "Cтрока " << e.inext.line << < позичия "<<e.inext.col <<std::endl<<std::endl;;"
	};
	"
	system("pause");
	return 0;
};