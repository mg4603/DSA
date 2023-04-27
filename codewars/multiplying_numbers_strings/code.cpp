#include <assert.h>
#include <iostream>

#include <vector>
#include <string>

std::string multiply(std::string a, std::string b){
    std::vector<std::string> intermediate_prods;
    int res_length(a.size() + b.size());
    for(size_t i(b.size()); i > 0; i--){
        int place_prod(0);
        std::string intermediate_prod(b.size() - i, '0');
        
        for(size_t j(a.size()); j > 0; j--){
            
            place_prod += (b.at(i - 1) - '0') * (a.at(j - 1) - '0');            
            intermediate_prod = std::to_string(place_prod % 10) + intermediate_prod;
            place_prod /= 10;
        }
        intermediate_prod = std::to_string(place_prod) + intermediate_prod;
        while (intermediate_prod.size() < res_length)
        {
            intermediate_prod = '0' + intermediate_prod;
        }
        
        intermediate_prods.push_back(intermediate_prod);
    }
    std::string res;
    int place_sum(0);
    for(size_t i(res_length); i > 0; i--){
        for(size_t j(0); j < intermediate_prods.size(); j++){
            place_sum += (intermediate_prods.at(j).at(i - 1) - '0'); 
        }
        res = std::to_string(place_sum % 10) + res;
        place_sum /= 10;
    }
    if( res.find_first_not_of('0') == std::string::npos)
        return "0";

    return res.substr(res.find_first_not_of('0'));
}

int main(){
    assert(multiply("2", "3") == "6");
    assert(multiply("30", "69") == "2070");
    assert(multiply("11", "85") == "935");
    assert(multiply("2", "0") == "0");
    assert(multiply("0", "30") == "0");
    assert(multiply("0000001", "3") == "3");
    assert(multiply("1009", "03") == "3027");
    assert(multiply("98765", "56894") == "5619135910");
    assert(multiply("1020303004875647366210", "2774537626200857473632627613") == "2830869077153280552556547081187254342445169156730");
    assert(multiply("58608473622772837728372827", "7586374672263726736374") == "444625839871840560024489175424316205566214109298");
    assert(multiply("9007199254740991", "9007199254740991") == "81129638414606663681390495662081");
    return 0;
}