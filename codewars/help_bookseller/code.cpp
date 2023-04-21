#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class StockList
{
public:
  static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);
};

std::string StockList::stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> & categories){
    if(lstOfArt.size() == 0 || categories.size() == 0)return "";
    std::map<std::string, int> categories_map;
    for(auto category: categories){
        categories_map[category] = 0;
    }
    for(auto book: lstOfArt){
        if(categories_map.count(book.substr(0, 1))){
            categories_map[book.substr(0, 1)] += std::stoi(book.substr(book.find_first_of(' ') + 1));
        }
    }
    std::string res;
    for(auto category: categories){
        res += "(";
        res += category;
        res += " : ";
        res += std::to_string(categories_map[category]);
        res += ") - ";
    }
    if(res.size()){
        res.pop_back();
        res.pop_back();
        res.pop_back();
    }
    return res;
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
static void dotest(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories, std::string expected)
{
    testequal(StockList::stockSummary(lstOfArt, categories), expected);
}

int main(){
    std::vector<std::string> art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd = {"A", "B"};
    dotest(art, cd, "(A : 200) - (B : 1140)");
    art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    cd = {"A", "B", "C", "D"};
    dotest(art, cd, "(A : 0) - (B : 1290) - (C : 515) - (D : 600)");
    return 0;
}

