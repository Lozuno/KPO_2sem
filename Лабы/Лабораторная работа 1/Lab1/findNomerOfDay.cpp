#include "stdafx.h"
#include "findNomerOfDay.h"
int findNomerOfDay(int day, int month, int year, bool visokos) {
    int ans = day;
    for (int i = 0; i < month; i++) {
        ans += months[i];
        if (i == 1 && visokos) {
            ans += 1;
        }
    }
    return ans;
}