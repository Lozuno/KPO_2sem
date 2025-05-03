#include <iostream>
#include "Call.h"

int main() {
    // Тестирование cdecl
    int result_cdecl = Call::cdeсl(1, 2, 3);
    std::cout << "cdecl: " << result_cdecl << std::endl; // 6

    // Тестирование cstd
    int a = 2;
    int result_cstd = Call::cstd(a, 3, 4);
    std::cout << "cstd: " << result_cstd << std::endl; // 24

    // Тестирование cfst
    int result_cfast = Call::cfst(1, 2, 3, 4);
    std::cout << "fastcall: " << result_cfast << std::endl; // 10

    return 0;
}