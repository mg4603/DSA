#include <assert.h>
#include <iostream>

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#define ull unsigned long long

class Stat{
    public:
        static std::string stat(const std::string &str);
        static std::string createTimestamp(ull);
};

std::string Stat::createTimestamp(ull time){
    int s = time % 60;
    time /= 60;
    int m = time % 60;
    time /= 60;
    int h = time;
    std::string timestamp;
    if(h < 10)
    {
        timestamp += '0';
        timestamp += h + '0';
    }
    else
    {
        timestamp += std::to_string(h);
    }

    timestamp += '|';
    if ( m < 10)
    {
        timestamp += '0';
        timestamp += m + '0';
    }
    else
    {
        timestamp += std::to_string(m);
    }
    
    timestamp += '|';
    if (s < 10)
    {
        timestamp += '0';
        timestamp += s + '0';
    }
    else
    {
        timestamp += std::to_string(s);
    }
    return timestamp;
}

std::string Stat::stat(const std::string &str){
    std::stringstream ss(str);
    std::string timestamp;
    std::vector<ull> times;

    while(getline(ss, timestamp, ',')){
        int h(std::stoi(timestamp));
        timestamp.erase(0, timestamp.find('|') + 1);
        int m(std::stoi(timestamp));
        timestamp.erase(0, timestamp.find('|') + 1);
        int s(std::stoi(timestamp));
        times.push_back(h * 60 * 60 + m * 60 + s);
    }
    
    std::sort(times.begin(), times.end());

    int range(times.at(times.size() - 1) - times.at(0));
    int average(std::accumulate(times.begin(), times.end(), 0, [](ull a, ull b){return a + b;})/ times.size());
    int median(0);
    if(times.size() % 2 == 0){
        median = (times.at(times.size() / 2) + times.at(times.size() /2 - 1)) / 2;
    }else{
        median = times.at(times.size() / 2);
    }
    
    return "Range: " + createTimestamp(range) + " Average: " + createTimestamp(average) + " Median: " + createTimestamp(median);
}

void testequal(std::string ans, std::string sol) {
    assert(ans== sol);
}
static void dotest(const std::string &lst, std::string &expected)
{
    testequal(Stat::stat(lst), expected);
}

int main(){
    std::string l = "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17";
    std::string sol = "Range: 01|01|18 Average: 01|38|05 Median: 01|32|34";
    dotest(l, sol);
    l = "02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|17|17, 2|22|00, 2|31|41";
    sol = "Range: 00|31|17 Average: 02|26|18 Median: 02|22|00";
    dotest(l, sol);
    return 0;
}


