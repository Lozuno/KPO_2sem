#pragma once
#include <iostream>
#include "findNearBirthday.h"
#include "validateDate.h"
#include "findNomerOfDay.h"
#include "isVisikos.h"

int findNearBirthday(int birthday[4], int mainDate[4]);
bool validateDate(char dateStr[], int date[4]);
int findNomerOfDay(int date[4]);
bool isVisokos(int year);