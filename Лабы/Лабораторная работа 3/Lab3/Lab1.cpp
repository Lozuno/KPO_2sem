#include "stdafx.h"

int main() {
    setlocale(LC_ALL, "rus");
    bool flag = true;
    while (flag) {
        char date[9];
        cout << "Введите дату в формате ДДММГГГГ(или 0 для выхода):";
        cin >> date;
        if (strcmp(date, "0")==0) {
            break;
        }
        int day, month, year;
        bool visokos;
        if (!validateDate(date, day, month, year, visokos)) {
            cout << "Некорректная дата\n";
            continue;
        }
        cout << "Год " << year << (visokos ? " високосный" : " невисокосный")<<'\n';
        cout << "Порядковый номер дня:" << findNomerOfDay(day, month, year, visokos)<<'\n';
        char name[13];
        cout << day <<' '<< findNameOfMonth(month) << ' '<<year<<'\n';
        cout << "Введите дату рождения в формате ДДММГГГГ:";
        char birthdayStr[9];
        cin >> birthdayStr;
        int birthDay, birthMonth, birthYear;
        bool birthVisokos;
        if (!validateDate(birthdayStr, birthDay, birthMonth, birthYear, birthVisokos)) {
            cout << "Некорректная дата";
            return 0;
        }
        cout << "Количество дней до ближайшего дня рождения: " << findNearBirthday(birthDay, birthMonth, birthYear, birthVisokos, day, month, year, visokos) << '\n';
    }
    return 0;
}
