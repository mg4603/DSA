#include<string>
#include<assert.h>
#include<cmath>
#include<iostream>

std::string seriesSum(int);

int main(){

    std::string actual = seriesSum(0);
    assert(("\n0.00") == ("\n" + actual));
    
    actual = seriesSum(9);
    assert(("\n1.77") == ("\n" + actual));
}

std::string seriesSum(int n){
    double res(0.0);
    for(int i(0); i < n; i++){
        res += (1/ (1 + static_cast<double>(i*3)));
    }
    /*
    std::stringstream ss;
    ss<<fixed<<std::setprecision(2)<<res;
    return ss.str();
    */
    res *= 100;
    res = std::round(res);
    res /= 100;

    std::string res_str =  std::to_string(res);
    return res_str.substr(0, res_str.find('.')+ 3);
}