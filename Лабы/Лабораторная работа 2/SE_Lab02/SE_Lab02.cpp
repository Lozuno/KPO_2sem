#include <iostream>
#include <limits>
#include <iomanip>
#include <locale>

using namespace std;

int add(int a, int b) {
    return a + b; // Сложение двух чисел
}

int main() {
    setlocale(LC_ALL, "Ru");
    // 2. 
    int n = 10;//
    short X = 9 + n; // X = 19 
    short Y = 10 + n; // Y = 20
    long Z = 11 + n; // Z = 21 
    float S = 1.0 + n; // S = 11.0

    // 4. Объявляем переменные типа bool
    bool flagFalse = false;//0x004FFAD3
    bool flagTrue = true;//0x004FFAC7

    // 5. Переменная типа char (второй символ фамилии на английском)
    char secondCharEng = 'a';//0x004FFABB

    // 6. Переменная типа char (второй символ фамилии на русском)
    char secondCharRus = 'а';//0x004FFAAF

    // 7. Переменная типа wchar_t (первый символ фамилии на английском)
    wchar_t firstCharEng = L'S';//0x004FFAA0

    // 8. Переменная типа wchar_t (первый символ фамилии на русском)
    wchar_t firstCharRus = L'С';//0x004FFA94

    // 9. Две переменные типа short
    short shortX = X; // X = 19 //0013 //0x004FFA88
    short shortNegX = -X; // -X = -19 //ffed //0x004FFA7C

    // 10. Записываем максимальные и минимальные значения для short
    short maxShort = 0x7FFF; // 32 767 
    short minShort = 0x8000; // -32 768 

    // 11. Записываем максимальные и минимальные значения для  unsigned short
    unsigned short maxUnsignedShort = 0xFFFF; // 65535 
    unsigned short minUnsignedShort = 0x0000; // 0 

    // 12. Аналогично для Y
    int intY = Y; // Y = 20 //00000014 //0x004FFA40
    int intNegY = -Y; // -Y = -20 //ffffffec //0x004FFA34

    // 13. Максимальные и минимальные значения для int
    int maxInt = 0x7FFFFFFF; // 2 147 483 647 
    int minInt = 0x80000000; // -2 147 483 648 

    // 14. Максимальные и минимальные значения для unsigned int
    int maxUnsignedInt = 0xFFFFFFFF; // 4 294 967 295 
    int minUnsignedInt = 0x00000000; // 0

    // 15. Объявляем две переменные типа long
    long longZ = Z; // Z = 21 //00000015 //0x004FF9F8
    long longNegZ = -Z; // -Z = -21 //ffffffeb //0x004FF9EC

    // 16. Максимальные и минимальные значения для long
    long maxLong = 0x7FFFFFFF; // 2 147 483 647 
    long minLong = 0x80000000; // −2 147 483 648 

    // 17. Максимальные и минимальные значения для unsigned long
    unsigned long maxUnsignedLong = 0xFFFFFFFF; // 4 294 967 295 //ffffffff
    unsigned long minUnsignedLong = 0x00000000; // 0 //00000000

    // 18. Переменные типа float
    float floatS = S; // S = 11.0 //41300000 //0x004FF9B0
    float floatNegS = -S; // -S = -11.0 //c1300000 //0x004FF9A4

    // 19. Выполняем операции с INF и IND
    //float inf = 3.0 / 0.0; // 1.#INF
    //float negInf = -3.0 / 0.0; // -1.#INF
    //float ind = 0.0 / 0.0; // -1.#IND

    // 20. Указатели на различные типы
    char c = 'd';//64
    wchar_t wc = L'В';//0412
    short s = 1;//0001
    int i = 1;//00000001
    float f = 1.0;//3f800000
    double d = 1.0;//3ff0000000000000

    char* pChar = &c;   
    wchar_t* pWChar = &wc;
    short* pShort = &s;
    int* pInt = &i;
    float* pFloat = &f;
    double* pDouble = &d;

    // Увеличиваем указатели на 3
    pChar += 3;
    pWChar += 3;
    pShort += 3;
    pInt += 3;
    pFloat += 3;
    pDouble += 3;

    // 21. Указатели на функции;
    int (*funcPtr)(int, int);
    funcPtr = add;
    int answer = funcPtr(3, 5);

    system("Pause");
    return 0;
}