#include <iostream>
#include <assert.h>

#include <sstream>
#include <string>
#include <vector>
#include <regex>

class SalesmanTravel
{
public:
    static std::string travel(const std::string& orgr, std::string zipcode);
};

std::string SalesmanTravel::travel(const std::string &orgr, std::string zipcode){
    if (zipcode == "")
        return ":/";
    std::string house_numbers;
    std::string streets;

    std::stringstream ss (orgr);
    std::string line;

    // std::regex address_rgx("([0-9]+) (.*) ([A-Z]{2} [0-9]{5})");
    // std::smatch match;
// 
    // while(getline(ss, line, ',')){
        // if(line.find(zipcode) != std::string::npos){
            // std::regex_search(line, match, address_rgx);
            // streets += match[2];
            // streets += ",";
            // house_numbers += match[1];
            // house_numbers += ",";
        // }
    // }

    while (getline(ss, line, ','))
    {
        if(line.find(zipcode) != std::string::npos && line.find(zipcode) + zipcode.size() == line.end() - line.begin()){
            house_numbers += std::string(line.begin(), line.begin() + line.find_first_not_of("0123456789"));
            house_numbers += ",";
            streets += std::string(line.begin() + line.find_first_not_of("0123456789")  + 1, line.end() - zipcode.length() - 1);
            streets += ',';
        }
    }
    
    if(streets.size() > 0)
        streets.pop_back();
    if(house_numbers.size() > 0)
        house_numbers.pop_back();
    return zipcode + ":" + streets + "/" + house_numbers;
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
int main(){
    std::string ad = "123 Main Street St. Louisville OH 43071,432 Main Long Road St. Louisville OH 43071,786 High Street Pollocksville NY 56432,"
        "54 Holy Grail Street Niagara Town ZP 32908,3200 Main Rd. Bern AE 56210,1 Gordon St. Atlanta RE 13000,"
        "10 Pussy Cat Rd. Chicago EX 34342,10 Gordon St. Atlanta RE 13000,58 Gordon Road Atlanta RE 13000,"
        "22 Tokyo Av. Tedmondville SW 43098,674 Paris bd. Abbeville AA 45521,10 Surta Alley Goodtown GG 30654,"
        "45 Holy Grail Al. Niagara Town ZP 32908,320 Main Al. Bern AE 56210,14 Gordon Park Atlanta RE 13000,"
        "100 Pussy Cat Rd. Chicago EX 34342,2 Gordon St. Atlanta RE 13000,5 Gordon Road Atlanta RE 13000,"
        "2200 Tokyo Av. Tedmondville SW 43098,67 Paris St. Abbeville AA 45521,11 Surta Avenue Goodtown GG 30654,"
        "45 Holy Grail Al. Niagara Town ZP 32918,320 Main Al. Bern AE 56215,14 Gordon Park Atlanta RE 13200,"
        "100 Pussy Cat Rd. Chicago EX 34345,2 Gordon St. Atlanta RE 13222,5 Gordon Road Atlanta RE 13001,"
        "2200 Tokyo Av. Tedmondville SW 43198,67 Paris St. Abbeville AA 45522,11 Surta Avenue Goodville GG 30655,"
        "2222 Tokyo Av. Tedmondville SW 43198,670 Paris St. Abbeville AA 45522,114 Surta Avenue Goodville GG 30655,"
        "2 Holy Grail Street Niagara Town ZP 32908,3 Main Rd. Bern AE 56210,77 Gordon St. Atlanta RE 13000";

    testequal(SalesmanTravel::travel(ad, "AA 45522"), "AA 45522:Paris St. Abbeville,Paris St. Abbeville/67,670");
    testequal(SalesmanTravel::travel(ad, "EX 34342"), "EX 34342:Pussy Cat Rd. Chicago,Pussy Cat Rd. Chicago/10,100");
    testequal(SalesmanTravel::travel(ad, "EX 34345"), "EX 34345:Pussy Cat Rd. Chicago/100");
    testequal(SalesmanTravel::travel(ad, "AA 45521"), "AA 45521:Paris bd. Abbeville,Paris St. Abbeville/674,67");
    testequal(SalesmanTravel::travel(ad, "AE 56215"), "AE 56215:Main Al. Bern/320");
    return 0;
}
