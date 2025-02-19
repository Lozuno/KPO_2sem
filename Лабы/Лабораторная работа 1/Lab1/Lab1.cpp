#include <iostream>
#include <string>
using namespace std;

static const int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

struct Date {
	int day;
	int month;
	int year;
};

bool isVisokos(int year) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}
int findNomerOfDay(int day,int month,int year) {
	int ans = day;
	month--;//не учитываем текущий месяц
	for (int i = 0; i < month; i++) {
		ans += month;
		if (month == 1 && isVisokos(year)) {
			ans += 1;
		}
	}
	return ans;
}
bool validateDate(string s,int a[3]) {
	int k = 0;
	string buf = "";
	for (int i = 0; i < s.length(); i++) {
		if (i == 2 || i == 4) {
			a[k]=stoi(buf);
			k++;
			buf = "";
		}
		if (isdigit(s[i])) {
			buf += s[i];
		}
		else {
			return false;
		}
	}
	a[2] = stoi(buf);
	if (a[1] > 12 || a[1] < 1) {
		return false;
	}
	a[1]--;//массив начинается с 0
	if (months[a[1]] < a[0]) {
		if (a[0] - months[a[1]] == 1 && isVisokos(a[2]) && a[1] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return true;
}
int findNearBirthday(Date birthday, Date maindate) {

}
int main() {
	setlocale(LC_ALL, "rus");
	cout << "Выберите вариант исполнения(0-Определить является ли год високосным,1-Вычислить порядковый номер дня,2-вычислить сколько дней осталось до дня рождения\n";
	int choice;
	cin >> choice;
	string date;
	int validdate[3];
	cout << "Введите дату в формате ДДММГГГГ:";
	cin >> date;
	if (validateDate(date, validdate)) {
		cout << "Некорректная дата";
		return 0;
	}
	Date maindate = { validdate[0],validdate[1] ,validdate[2] };
	switch (choice) {
	case 0: {
		if (isVisokos(maindate.year)) {
			cout << "Год " << maindate.year << " високосный";
		}
		else {
			cout << "Год " << maindate.year << " невисокосный";
		}
		return 0;
	}
	case 1: {
		int nomer = findNomerOfDay(maindate.day,maindate.month,maindate.year);
		cout << "Порядковый номер дня:" << nomer;
		return 0;
	}
	case 2: {
		cout << "Введите дату рождения:";
		string birthday;
		cin >> birthday;
		int validbirthday[3];
		if (validateDate(birthday, validbirthday)) {
			cout << "Некорректная дата";
			return 0;
		}
		Date birthday = {validbirthday[0],validbirthday[1],validbirthday[2] };


	}
	}
	
	return 0;
}