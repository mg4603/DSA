#include <vector>
#include<assert.h>
#include<algorithm>
#include<cmath>

class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
        if(a.size() != b.size()){
            return false;
        }
        std::sort(a.begin(), a.end(), [](int a, int b){return std::abs(a) < std::abs(b);});
        std::sort(b.begin(), b.end());
      
        for(size_t i(0); i < a.size(); i++){
            if(std::pow(a.at(i), 2) != b.at(i)){
                return false;
            }
        }
        return true;
    }
};


void dotest(std::vector<int> a, std::vector<int> b, bool sol)
{
    bool ans = Same::comp(a, b);
    assert(ans == sol);
}

int main()
{
    
    std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    dotest(a, b, true);
    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
    dotest(a, b, false);
          
};