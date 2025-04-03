#include "stdafx.h"
#include "validateDate.h"

bool validateDate(char dateStr[], int& day, int& month, int& year, bool& visokos) {
    if (strlen(dateStr) != 8) {
        return false;
    }
    for (int i = 0; i < 8; i++) {
        if (!isdigit(dateStr[i])) {
            return false;
        }
    }

    char dayStr[3], monthStr[3], yearStr[5];
    strncpy_s(dayStr, dateStr, 2);
    dayStr[2] = '\0';
    strncpy_s(monthStr, dateStr + 2, 2);
    monthStr[2] = '\0';
    strncpy_s(yearStr, dateStr + 4, 4);
    yearStr[4] = '\0';

    day = atoi(dayStr);
    month = atoi(monthStr);
    year = atoi(yearStr);
    visokos = isVisokos(year);

    if (month > 12 || month < 1) {
        return false;
    }
    month--;
    if (months[month] < day) {
        if (day - months[month] == 1 && visokos && month == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}