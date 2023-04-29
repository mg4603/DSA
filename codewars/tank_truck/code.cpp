#include <assert.h>
#include <iostream>

#include <cmath>

class VolTank{
    public:
        static int tankVol(int h, int d, int vt);
};

int VolTank::tankVol(int h, int d, int vt){
    double rc = d / 2.0;
    double crossArea = 2 * acos(0.0) * rc * rc;
    double hc = vt / crossArea;
    if(rc >= h){
        double alpha = 2 * acos((rc-h) / rc);
        return int((alpha / 6.28318531 * vt ) - (hc * (rc - h) *  sqrtf(2 * rc *h - h * h)));
    }else{
        double alpha = 4 * acos(0.0) - 2 * acos((h - rc) / rc) ;
        return int(alpha / (4 * acos(0.0)) * vt + (hc * (h - rc) *  sqrtf(2 * rc *h - h * h)));
    }
}

void testequal(int ans, int sol) {
    assert(ans == sol);
}
void dotest(int h, int d, int vt, int expected)
{
    testequal(VolTank::tankVol(h, d, vt), expected);
}

int main()
{
    dotest(2, 7, 3848, 907);
    dotest(5, 7, 3848, 2940);
    dotest(2, 8, 5026, 982);
    dotest(4, 9, 6361, 2731);
    return 0;
}
