#include "stdafx.h"

int main() {
    setlocale(LC_ALL, "rus");
    bool flag = true;
    while (flag) {

        char date[9];
        cout << "Введите дату в формате ДДММГГГГ(или 0 для выхода):";
        cin >> date;
        if (strcmp(date, "0") == 0) {
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

        cout << day << ' ' << findNameOfMonth(month) << ' ' << year << '\n';

        int nomerDay;
        cout << "Введите номер дня для проверки на праздник(год считается из даты выше):";
        cin >> nomerDay;
        while (nomerDay + int(visokos) > 366 || nomerDay<1) {
            cout << "Неверный ввод\n";
            cin >> nomerDay;
        }
        findHoliday(nomerDay, visokos);

        cout << "Введите дату рождения в формате ДДММГГГГ:";
        char birthdayStr[9];
        cin >> birthdayStr;
        int birthDay, birthMonth, birthYear;
        bool birthVisokos;
        while (!validateDate(birthdayStr, birthDay, birthMonth, birthYear, birthVisokos)) {
            cout << "Некорректная дата\n";
            cin >> birthdayStr;
        }
        cout << birthDay << ' ' << findNameOfMonth(birthMonth) << ' ' << birthYear << '\n';
        cout << "Количество дней до ближайшего дня рождения: " << findNearBirthday(birthDay, birthMonth, birthYear, birthVisokos, day, month, year, visokos) << '\n';

    }
    return 0;
}
