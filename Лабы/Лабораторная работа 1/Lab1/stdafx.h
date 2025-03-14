#pragma once
#include <iostream>
#include "findNearBirthday.h"
#include "validateDate.h"
#include "findNomerOfDay.h"
#include "isVisokos.h"
static int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int findNearBirthday(int birthday[4], int mainDate[4]);
bool validateDate(char dateStr[], int date[4]);
int findNomerOfDay(int date[4]);
bool isVisokos(int year);