#include <assert.h>
#include <iostream>

#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

double posAverage(const std::string &s)
{
    std::vector<std::string> num_strings;

    std::string s_copy(s);
    size_t idx(s_copy.find(','));

    while(idx != std::string::npos){
        std::string token(s_copy.substr(0, idx));
        s_copy = s_copy.substr(s_copy.find_first_of("1234567890", idx));

        num_strings.push_back(token);
        idx = s_copy.find(',');
    }

    num_strings.push_back(s_copy);
    int number_of_substrings(num_strings.size());

    double common_pos(0);
    for(size_t i(0); i < number_of_substrings; i++){
        for(size_t j(i+1); j < number_of_substrings; j++){
            for(size_t k(0); k < num_strings[i].length(); k++){
                if(num_strings[i][k] == num_strings[j][k])
                {
                    common_pos++;
                }
            }
        }
    }

    double total_pos(number_of_substrings * (number_of_substrings - 1) / 2 * num_strings[1].length());
    return common_pos / total_pos * 100;

}


void assertFuzzy(const std::string &s, double expect)
{
    std::cout << std::setprecision(10);
    std::cout << std::scientific;
    double merr = 1e-9;
    std::cout << "Testing: " << s <<std::endl;
    double actual = posAverage(s);
    std::cout << "Actual: " << actual <<std::endl;
    std::cout << "Expect: " << expect <<std::endl;
    bool inrange = std::abs(actual - expect) <= merr;
    if (inrange == false)
        std::cout << "Expected: " << expect << ", got " << actual << std::endl;
    std::cout << inrange << std::endl;
    assert(true == inrange);
}

void tests()
{
    assertFuzzy("466960, 069060, 494940, 060069, 060090, 640009, 496464, 606900, 004000, 944096", 26.6666666667);
    assertFuzzy("444996, 699990, 666690, 096904, 600644, 640646, 606469, 409694, 666094, 606490", 29.2592592593);
    assertFuzzy("4444444, 4444444, 4444444, 4444444, 4444444, 4444444, 4444444, 4444444", 100);
}

int main()
{
    tests();
    return 0;
}