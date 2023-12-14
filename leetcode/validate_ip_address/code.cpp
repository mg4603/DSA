#include <iostream>
#include <assert.h>

#include <vector>
#include <sstream>

class Solution {
public:
    std::string validIPAddress(std::string queryIP) 
    {
        std::vector<std::string> vec;

        std::stringstream ss(queryIP);
        std::string temp;

        if(queryIP.find('.') != std::string::npos)
        {
            if(queryIP.back() == '.')
            {
                return "Neither";
            }
            while(getline(ss, temp, '.'))
            {
                vec.push_back(temp);
            }
        }

        if(vec.size() == 0 && queryIP.find(':') != 
            std::string::npos)
        {
            if(queryIP.back() == ':')
            {
                return "Neither";
            }
            while(getline(ss, temp, ':'))
            {
                vec.push_back(temp);
            }
        }

        if(vec.size() == 4 || vec.size() == 8)
        {
            if(vec.size() == 4)
            {   
                for(int i = 0; i < 4; i++)
                {

                    int temp = 0;
                    try
                    {
                        temp = std::stoi(vec[i]);
                    }
                    catch(...)
                    {
                        return "Neither";
                    }
                    if(temp > 255 || temp < 0 || 
                        (vec[i][0] == '0' && temp != 0) || 
                        (temp == 0 && vec[i].length() > 1))
                    {
                        return "Neither";
                    }
                    for(int j = 0; j < vec[i].length(); j++)
                    {
                        if(vec[i][j] < '0' || vec[i][j] > '9')
                        {
                            return "Neither";
                        }
                    }
                }
                return "IPv4";
            }
            else
            {
                std::string symbols = "01234567890abcdefABCDEF";
                for(int i = 0; i < 8; i++)
                {
                    int n = vec[i].length();
                    if(n < 1 || n > 4)
                    {
                        return "Neither";
                    }
                    for(int j = 0; j < n; j++)
                    {
                        if(symbols.find(vec[i][j]) == 
                            std::string::npos)
                        {
                            return "Neither";
                        }
                    }
                }
                return "IPv6";

            }
        }
        return "Neither";
    }
};

int main()
{
    Solution sol;
    {
        std::string queryIP = "172.16.254.1";
        std::string res = "IPv4";
        assert(sol.validIPAddress(queryIP) == res);
    }
    {
        std::string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
        std::string res = "IPv6";
        assert(sol.validIPAddress(queryIP) == res);
    }
    {
        std::string queryIP = "256.256.256.256";
        std::string res = "Neither";
        assert(sol.validIPAddress(queryIP) == res);
    }
    return 0;
}