#include "stdafx.h"
#include "findNomerOfDay.h"
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
