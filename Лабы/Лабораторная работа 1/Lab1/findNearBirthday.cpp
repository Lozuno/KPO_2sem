#include "stdafx.h"

int findNearBirthday(int birthday[4], int mainDate[4]) {
    int birthNomer = findNomerOfDay(birthday);
    int dateNomer = findNomerOfDay(mainDate);
    int res = 0;

    if (mainDate[2] >= birthday[2]) {

        if (birthday[0] == 29 && birthday[1] == 1) {

            if (mainDate[3] && dateNomer < birthNomer) {
                return birthNomer - dateNomer;
            }
            else {
                res += 365 + mainDate[3] - dateNomer + birthNomer;
                mainDate[2]++;
                while (!isVisokos(mainDate[2])) {
                    mainDate[2]++;
                    res += 365;
                }
                return res;
            }

        }
        else {
            if (dateNomer < birthNomer) {
                return birthNomer - dateNomer;
            }
            else {
                return 365 + mainDate[3] - dateNomer + birthNomer;
            }
        }
    }
    // др через несколько лет
    if (mainDate[2] < birthday[2]) {
        res = 365 + mainDate[3] - findNomerOfDay(mainDate);
        res += findNomerOfDay(birthday);
        for (int i = mainDate[2] + 1; i < birthday[2]; i++) {
            res += 365;
            res += isVisokos(i);
        }
        return res;
    }
    return 0;
}
