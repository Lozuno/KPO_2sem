#include "stdafx.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    bool flag = true;
    while (flag) {
        char date[9];
        cout << "Введите дату в формате ДДММГГГГ:";
        cin >> date;

        int day, month, year;
        bool visokos;
        if (!validateDate(date, day, month, year, visokos)) {
            cout << "Некорректная дата\n";
            continue;
        }

        cout << "\nВыберите вариант исполнения\n(1-Определить является ли год високосным,2-Вычислить порядковый номер дня,3-вычислить сколько дней осталось до дня рождения, 0-выход)\n";
        char choice;
        cin >> choice;
        if (!isdigit(choice)) {
            cout << "Некорректный ввод\n";
            continue;
        }
        int var = choice - '0';

        switch (var) {
        case 1: {
            cout << "Год " << year << (visokos ? " високосный" : " невисокосный");
            break;
        }
        case 2: {
            cout << "Порядковый номер дня:" << findNomerOfDay(day, month, year, visokos);
            break;
        }
        case 3: {
            cout << "Введите дату рождения в формате ДДММГГГГ:";
            char birthdayStr[9];
            cin >> birthdayStr;
            int birthDay, birthMonth, birthYear;
            bool birthVisokos;
            if (!validateDate(birthdayStr, birthDay, birthMonth, birthYear, birthVisokos)) {
                cout << "Некорректная дата";
                return 0;
            }
            cout << "Количество дней до ближайшего дня рождения: " << findNearBirthday(birthDay, birthMonth, birthYear, birthVisokos, day, month, year, visokos);
            break;
        }
        case 0:
            flag = false;
            break;
        default:
            cout << "Неверный вариант использования\n";
            break;
        }
        cout << '\n';
    }
    return 0;
}
