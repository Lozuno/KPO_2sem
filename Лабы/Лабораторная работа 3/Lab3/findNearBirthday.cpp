#include "stdafx.h"
#include "findNearBirthday.h"
int findNearBirthday(int birthDay, int birthMonth, int birthYear, bool birthVisokos, int mainDay, int mainMonth, int mainYear, bool mainVisokos) {
    int birthNomer = findNomerOfDay(birthDay, birthMonth, birthYear, birthVisokos);
    int dateNomer = findNomerOfDay(mainDay, mainMonth, mainYear, mainVisokos);
    int res = 0;

    if (mainYear >= birthYear) {
        if (birthDay == 29 && birthMonth == 1) {
            if (mainVisokos && dateNomer < birthNomer) {
                return birthNomer - dateNomer;
            }
            else {
                res += 365 + int(mainVisokos) - dateNomer + birthNomer;
                mainYear++;
                while (!isVisokos(mainYear)) {
                    mainYear++;
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
                return 365 + int(mainVisokos) - dateNomer + birthNomer;
            }
        }
    }
    if (mainYear < birthYear) {
        res = 365 + int(mainVisokos) - findNomerOfDay(mainDay, mainMonth, mainYear, mainVisokos);
        res += findNomerOfDay(birthDay, birthMonth, birthYear, birthVisokos);
        for (int i = mainYear + 1; i < birthYear; i++) {
            res += 365;
            res += int(isVisokos(i));
        }
        return res;
    }
    return 0;
}