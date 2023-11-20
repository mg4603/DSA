#include <iostream>
#include <assert.h>

class Solution { 
public:
    int compareVersion(std::string version1, std::string version2) 
    {
        int i = 0;
        int j = 0;

        int v1_size = version1.size();
        int v2_size = version2.size();

        while(i < v1_size || j < v2_size)
        {

            long long num1 = 0;
            long long num2 = 0;

            while(i < v1_size && version1[i] != '.')
            {
                num1 *= 10;
                num1 += (version1[i++] - '0');
            }

            while(j < v2_size && version2[j] != '.')
            {
                num2 *= 10;
                num2 += (version2[j++] - '0');
            }
            if(num1 > num2)
            {
                return 1;
            }
            else if(num2 > num1)
            {
                return -1;
            }

            i++;
            j++;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::string version1 = "1.01";
        std::string version2 = "1.001";
        int res = 0;

        assert(sol.compareVersion(version1, version2) == res);
    }
    {
        std::string version1 = "1.0";
        std::string version2 = "1.0.0";
        int res = 0;

        assert(sol.compareVersion(version1, version2) == res);
    }
    {
        std::string version1 = "0.1";
        std::string version2 = "1.1";
        int res = -1;

        assert(sol.compareVersion(version1, version2) == res);
    }
    return 0;
}