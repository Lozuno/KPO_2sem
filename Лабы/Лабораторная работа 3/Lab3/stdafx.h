#pragma once
#include <iostream>
#include "findNearBirthday.h"
#include "validateDate.h"
#include "findNomerOfDay.h"
#include "isVisokos.h"
#include "findNameOfMonth.h"
using namespace std;
static char namesOfMonths[12][10] = { "Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь" };
static int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };