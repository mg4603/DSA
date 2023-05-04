#include <iostream>
#include <assert.h>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

class Rank
{
public:
    static std::string nthRank(const std::string &st, std::vector<int> &we, int n);
};

std::string Rank::nthRank(const std::string &st, std::vector<int> &we, int n){
    if(st == ""){
        return "No participants";
    }
    
    std::stringstream ss(st);
    std::string token;
    std::vector<std::pair<std::string, int>> firstNames;
    int i(0);
    while(getline(ss, token, ',')){
        firstNames.push_back(
            make_pair(
                token,
                we.at(i) * (token.length() +
                 std::accumulate(
                    token.begin(), token.end(), 0, 
                    [](int a, char b){
                        return a + (tolower(b) - 'a') + 1;
                    }
                ))
            ));
        i++;
    }
    if(n > static_cast<int>(firstNames.size())){
        return "Not enough participants";
    }
    sort(firstNames.begin(), firstNames.end(), [](auto elem1, auto elem2){
        if(elem1.second == elem2.second){
            return elem1.first.compare(elem2.first) < 0;
        }
        return elem1.second > elem2.second;
    });
    std::cout<<firstNames.at(n - 1).first<<std::endl;
    return firstNames.at(n - 1).first;
    
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void dotest(const std::string &st, std::vector<int> &we, int n, std::string expected)
{
    testequal(Rank::nthRank(st, we, n), expected);
}

int main()
{
    std::string st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
    std::vector<int> we = {4, 2, 1, 4, 3, 1, 2};
    std::string sol = "Benjamin";
    dotest(st, we, 4, sol);

    st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
    we = {1, 3, 5, 5, 3, 6};
    sol = "Matthew";
    dotest(st, we, 2, sol);
    return 0;
}
