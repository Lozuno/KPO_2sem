#include <iostream>
using namespace std;
int defaultparam(int p1, int p2, int p3, int p4, int p5, int p6 = 2, int p7 = 3) {
    return (p1 + p2 + p3 + p4 + p5 + p6 + p7) / 7;
}

int main()  {
    setlocale(LC_ALL, "rus");
    defaultparam(2, 7, 6, 5, 1);
    defaultparam(2, 7, 6, 5, 1, 11, 0);
    return 0;
}