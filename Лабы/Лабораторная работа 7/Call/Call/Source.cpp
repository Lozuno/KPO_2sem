#include <iostream>
#include "Call.h"

int main() {
    
    int result_cdecl = Call::cdeñl(1, 2, 3);
    std::cout << "cdecl: " << result_cdecl << std::endl; 

    
    int a = 2;
    int result_cstd = Call::cstd(a, 3, 4);
    std::cout << "cstd: " << result_cstd << std::endl; 

    
    int result_cfast = Call::cfst(1, 2, 3, 4);
    std::cout << "fastcall: " << result_cfast << std::endl; 

    return 0;
}