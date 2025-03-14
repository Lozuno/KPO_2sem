#include "stdafx.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    bool flag = true;
    while (flag) {
       
        char date[9];
        cout << "Введите дату в формате ДДММГГГГ:";
        cin >> date;

        int mainDate[4]; // [0]-день, [1]-месяц, [2]-год, [3]-високосный
        if (!validateDate(date, mainDate)) {
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
            if (mainDate[3]) {
                cout << "Год " << mainDate[2] << " високосный";
            }
            else {
                cout << "Год " << mainDate[2] << " невисокосный";
            }
            break;
        }
        case 2: {
            int nomer = findNomerOfDay(mainDate);
            cout << "Порядковый номер дня:" << nomer;
            break;
        }
        case 3: {
            cout << "Введите дату рождения в формате ДДММГГГГ:";
            char birthdayStr[9];
            cin >> birthdayStr;
            int birthday[4];
            if (!validateDate(birthdayStr, birthday)) {
                cout << "Некорректная дата";
                return 0;
            }
            cout << "Количество дней дaо ближайщего дня рождения: " << findNearBirthday(birthday, mainDate);
            break;
        }
        case 0: {
            flag = false;
            break;
        }
        default: {
            cout << "Неверный вариант использования\n";
            break;
        }
        }
    }
    return 0;
}