#include "stdafx.h"
#include "findHoliday.h"
void findHoliday(int nomerDay, bool visokos) {
	if (visokos && nomerDay > 61) {
		nomerDay--;
	}
	switch (nomerDay) {
	case 256: {
		cout << "С Днём программиста\n";
		break;
	}
	case 73: {
		cout << "С днём числа pi\n";
		break;
	}
	case 67: {
		cout << "С международным женским днём\n";
		break;
	}
	case 54: {
		cout << "С днём защитника Отечества\n";
		break;
	}
	default: {
		cout << "В этот день праздник не задан\n";
		break;
	}
	}
	return;
}