#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) 
    {
        if(num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int n1_len = num1.length();
        int n2_len = num2.length();

        std::vector<std::string> res_temp;

        int i = n1_len - 1;
        int j = n2_len - 1;
        int cnt = 0;
        while(j >= 0)
        {
            std::string temp;
            int carry = 0;
            while(i >= 0)
            {
                int prod = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = prod / 10;
                prod %= 10;
                temp = std::to_string(prod) + temp;
                i--;
            }
            if(carry > 0)
            {
                temp = std::to_string(carry) + temp;
            }
            if(cnt > 0)
            {
                temp += std::string(cnt, '0');
            }
            res_temp.push_back(temp);
            
            i = n1_len - 1;
            cnt++;
            j--;
            
        }
        
        std::string res;
        int longest_temp_len = res_temp.back().length();

        int carry = 0;
        for(int i = 1; i <= longest_temp_len; i++)
        {
            int place = carry;
            for(int j = 0; j < res_temp.size(); j++)
            {
                if(res_temp[j].size() < i)continue;
                place += res_temp[j][res_temp[j].size() - i] - '0';
            }
            carry = place / 10;
            place %= 10;
            res = std::to_string(place) + res;
        }
        if(carry > 0)
        {
            res = std::to_string(carry) + res;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string num1 = "2";
        std::string num2 = "3";
        std::string res = "6";;
        assert(sol.multiply(num1, num2) == res);
    }
    {
        std::string num1 = "123";
        std::string num2 = "456";
        std::string res = "56088";;
        assert(sol.multiply(num1, num2) == res);
    }
    return 0;
}