#include "stdafx.h"

static int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
bool validateDate(char dateStr[], int date[4]) {
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

    date[0] = atoi(dayStr);     // день
    date[1] = atoi(monthStr);   // мес€ц
    date[2] = atoi(yearStr);    // год
    date[3] = isVisokos(date[2]); // високосный год

    if (date[1] > 12 || date[1] < 1) {
        return false;
    }
    date[1]--; // ”меньшаем мес€ц дл€ соответстви€ индексам массива months
    if (months[date[1]] < date[0]) {
        if (date[0] - months[date[1]] == 1 && date[3] && date[1] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}