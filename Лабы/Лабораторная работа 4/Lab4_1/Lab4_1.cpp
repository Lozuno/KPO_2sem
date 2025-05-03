#include <iostream>
#include <cstring>
using namespace std;

struct MobileOperator {
    struct PhoneNumber {
        int country_code;
        int provider;
        unsigned long long number;
    };

    PhoneNumber phone_number;
    char owner[100];
    char tariff_plan[50];
    bool unlimited_internet;
    int call_minutes;
};

int operator-(MobileOperator& a, int minutes) {
    if (a.call_minutes >= minutes) {
        a.call_minutes -= minutes;
        return a.call_minutes;
    }
    return -1;
}

bool operator==(MobileOperator a, MobileOperator b) {
    return (a.phone_number.country_code == b.phone_number.country_code &&
        a.phone_number.provider == b.phone_number.provider &&
        a.phone_number.number == b.phone_number.number &&
        strcmp(a.owner, b.owner) == 0 &&
        strcmp(a.tariff_plan, b.tariff_plan) == 0 &&
        a.unlimited_internet == b.unlimited_internet &&
        a.call_minutes == b.call_minutes);
}
void getOper(MobileOperator &op1) {
    
    cout << "Код страны: ";
    cin >> op1.phone_number.country_code;
    cout << "Провайдер: ";
    cin >> op1.phone_number.provider;
    cout << "Номер телефона: ";
    cin >> op1.phone_number.number;
    cin.ignore();
    cout << "Владелец: ";
    cin.getline(op1.owner, 100);
    cout << "Тарифный план: ";
    cin.getline(op1.tariff_plan, 50);
    cout << "Безлимитный интернет (1/0): ";
    cin >> op1.unlimited_internet;
    cout << "Минуты на звонки: ";
    cin >> op1.call_minutes;
}
void putOper(MobileOperator op) {
    cout << "Телефон: +" << op.phone_number.country_code<< "-(" << op.phone_number.provider<< ")-" << op.phone_number.number << "\n"<< "Владелец: " << op.owner << "\n"<< "Тариф: " << op.tariff_plan << "\n"<< "Безлимит: " << (op.unlimited_internet ? "Да" : "Нет") << "\n"<< "Минуты: " << op.call_minutes << "\n";
}
int main() {
    setlocale(LC_ALL,"rus");
    MobileOperator op1, op2;
    cout << "Введите данные первого оператора:\n";
    getOper(op1);
    cout << "Введите данные второго оператора:\n";
    getOper(op2);

    int diff;
    cout << "Введите количество минут: ";
    cin >> diff;

    if (diff != -1)
        cout << "Остаток минут у op1: " << diff << "\n";
    else
        cout << "Недостаточно минут у op1!\n";

    diff = op1 - diff;


    cout << "\nСравнение операторов:\n";
    if (op1 == op2)
        cout << "Операторы идентичны\n";
    else
        cout << "Операторы разные\n";
    cout << "\nДанные первого оператора:\n";
    putOper(op1);
    cout << "\nДанные второго оператора:\n";
    putOper(op2);

}