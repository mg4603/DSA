#include <assert.h>
#include <iostream>

#include <string>
#include <set>

std::string kaCokadekaMe(std::string word)
{
    std::string res("ka");
    std::set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    for(size_t i(0); i < word.size() - 1; i++)
    {
        if(vowels.find(tolower(word[i])) != vowels.end() && vowels.find(tolower(word[i + 1])) == vowels.end())
        {
            res += word[i];
            res += "ka";
        }
        else
        {
            res += word[i];
        }
    }
    res += word.back();
    return res;
}

static void test(std::string expectedResult , std::string result, std::string source) {
       std::cout << '\n' << "Testing for: " << source << '\n' << 
      "Expected result: " << expectedResult << '\n' <<
      "Result: " << result << std::endl ;
       assert(result == expectedResult);   
}

int main()
{
    test("kaka" , kaCokadekaMe("ka"),"ka");    
    test("kaaa" , kaCokadekaMe("aa"),"aa");  
    test("kaka" , kaCokadekaMe("ka"), "ka");    
    test("kaa" , kaCokadekaMe("a"),"a"); 
    test("kaz" , kaCokadekaMe("z"), "z");    
    test("kaAkabbaa" , kaCokadekaMe("Abbaa"),"Abbaa"); 
    test("kamaikantekanakance" , kaCokadekaMe("maintenance"), "maintenance");    
    test("kaWookadie" , kaCokadekaMe("Woodie"), "Woodie");        
    test("kaIkancokamprekahekansikabikalikatiekas" , kaCokadekaMe("Incomprehensibilities"),"Incomprehensibilities");         
    return 0;
}