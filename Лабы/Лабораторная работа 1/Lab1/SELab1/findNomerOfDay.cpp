#include "stdafx.h"
static int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int findNomerOfDay(int date[4]) {
    int ans = date[0]; // day
    for (int i = 0; i < date[1]; i++) { // мес€ц
        ans += months[i];
        if (i == 1 && date[3]) { // visokos
            ans += 1;
        }
    }
    return ans;
}
