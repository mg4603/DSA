#include <iostream>
#include <assert.h>

#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class OrdersSummary
{
private:
    static std::string genResString(double buy, double sell, std::vector<std::string> wrongOrders);
    static double stringMul(std::string a, std::string b);
    static bool checkInt(std::string str);    
    static bool checkDouble(std::string str);
    static bool checkStatus(std::string str);
public:
    static std::string balanceStatements(const std::string &lst);
};

bool OrdersSummary::checkStatus(std::string str)
{
    if(str == "B" || str == "S")
    {
        return true;
    }
    return false;
}

bool OrdersSummary::checkInt(std::string str)
{
    for(char c: str)
    {
        if(!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool OrdersSummary::checkDouble(std::string str)
{
    if(str.find('.') == std::string::npos)
    {
        return false;
    }
    for(char c: str)
    {
        if(!(isdigit(c) || c == '.'))
        {
            return false;
        }
    }
    return true;
}

double OrdersSummary::stringMul(std::string a, std::string b)
{
    return std::stod(a) * std::stod(b);
}

std::string OrdersSummary::genResString(double buy, double sell, std::vector<std::string> wrongOrders)
{
    std::string res;
    res += "Buy: ";
    res += std::to_string(static_cast<int>(round(buy)));
    res += " Sell: ";
    res += std::to_string(static_cast<int>(round(sell)));
    if(wrongOrders.size() == 0)
    {
        return res;
    }
    res += "; Badly formed " + std::to_string(wrongOrders.size()) + ": ";
    for(std::string wrongOrder: wrongOrders)
    {
        res += wrongOrder;
        res += " ;";
    }
    return res;
}

std::string OrdersSummary::balanceStatements(const std::string &lst)
{
    std::string simple_order;
    std::stringstream ss(lst);

    std::vector<std::string> wrongOrders;

    double buy(0);
    double sell(0);

    while(getline(ss, simple_order, ','))
    {
        std::vector<std::string> elems;
        std::string temp;
        std::stringstream ss1(simple_order);
        while(ss1 >> temp)
        {
            elems.push_back(temp);
        }
        if(elems.size() < 4 || !checkInt(elems.at(1)) || !checkDouble(elems.at(2)) || !checkStatus(elems.at(3)))
        {
            wrongOrders.push_back(simple_order.substr(simple_order.find_first_not_of(' '), simple_order.find_last_not_of(' ') - simple_order.find_first_not_of(' ') + 1));
            continue;
        }
        if(elems.at(3) == "B")
        {
            buy += stringMul(elems.at(1), elems.at(2));
        }
        else
        {
            sell += stringMul(elems.at(1), elems.at(2));
        }
    }
    return genResString(buy, sell, wrongOrders);
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
static void dotest(const std::string &lst, std::string &expected)
{
    testequal(OrdersSummary::balanceStatements(lst), expected);
}

int main()
{
    std::string l = "GOOG 300 542.0 B, AAPL 50 145.0 B, CSCO 250.0 29 B, GOOG 200 580.0 S";
    std::string sol = "Buy: 169850 Sell: 116000; Badly formed 1: CSCO 250.0 29 B ;";
    dotest(l, sol);
    
    l = "GOOG 90 160.45 B, JPMC 67 12.8 S, MYSPACE 24.0 210 B, CITI 50 450 B, CSCO 100 55.5 S";
    sol = "Buy: 14440 Sell: 6408; Badly formed 2: MYSPACE 24.0 210 B ;CITI 50 450 B ;";
    dotest(l, sol);
    
    l = "ZNGA 1300 2.66 B, CLH15.NYM 50 56.32 B, OWW 1000 11.623 B, OGG 20 580.1 B";
    sol = "Buy: 29499 Sell: 0";
    dotest(l, sol);
    return 0;
};