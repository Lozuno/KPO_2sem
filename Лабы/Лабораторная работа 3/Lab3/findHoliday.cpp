#include "stdafx.h"
#include "findHoliday.h"
void findHoliday(int nomerDay, bool visokos) {
	if (visokos && nomerDay > 61) {
		nomerDay--;
	}
	switch (nomerDay) {
	case 256: {
		cout << "� ��� ������������\n";
		break;
	}
	case 73: {
		cout << "� ��� ����� pi\n";
		break;
	}
	case 67: {
		cout << "� ������������� ������� ���\n";
		break;
	}
	case 54: {
		cout << "� ��� ��������� ���������\n";
		break;
	}
	default: {
		cout << "� ���� ���� �������� �� �����\n";
		break;
	}
	}
	return;
}