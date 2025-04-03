#include "stdafx.h"
#include "isVisokos.h"
bool isVisokos(int year) {
    return ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0));
}