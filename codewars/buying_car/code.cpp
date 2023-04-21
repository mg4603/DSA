#include <assert.h>
#include <vector>
#include <cmath>
using namespace std;

class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

std::vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth){
    if(startPriceOld > startPriceNew)return {0, startPriceOld - startPriceNew};
    int months(0);
    int savings(0);
    double priceNew(startPriceNew);
    double priceOld(startPriceOld);

    while(priceNew > (priceOld + savings)){
        months ++;
        savings += savingperMonth;

        priceNew -= (priceNew * percentLossByMonth / 100);
        priceOld -= (priceOld * percentLossByMonth / 100);
         
        if(months % 2){
            percentLossByMonth += 0.5;
        }
    }
    return {months, static_cast<int>(std::round(((priceOld + savings) - priceNew)))};
}


int main(){
    
    static const int r1[] = { 6, 766 };
    vector<int> s (r1, r1 + sizeof(r1) / sizeof(r1[0]));
    vector<int> ans1 = BuyCar::nbMonths(2000, 8000, 1000, 1.5);
    assert(ans1 == s);

    static const int r2[] = { 0, 4000 };
    vector<int> s1(r2, r2 + sizeof(r2) / sizeof(r2[0]));
    ans1 = BuyCar::nbMonths(12000, 8000, 1000, 1.5);
    assert(ans1 == s1);
    
};
