#include <iostream>
#include <assert.h>

#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> escape(const std::vector<std::vector<int>> &carpark)
{
    std::vector<std::string> res;

    int i(0);
    while(find(carpark[i].begin(), carpark[i].end(), 2) == carpark[i].end())i++;

    int posS(find(carpark[i].begin(), carpark[i].end(), 2) - carpark[i].begin());
    int posN(find(carpark[i].begin(), carpark[i].end(), 1) - carpark[i].begin());

    int down(0);
    while(i < carpark.size())
    {
        if(posN > posS)
        {
            if(down > 0)
            {
                res.push_back("D" + std::to_string(down));
            }
            if(posN == carpark[i].size())
            {
                if(carpark[i].size() - posS - 1 != 0)
                    res.push_back("R" + std::to_string(carpark[i].size() - posS - 1));
                break;
            }
            res.push_back("R" + std::to_string(posN - posS));
            posS = posN;
            down = 0;
        }
        else if(posS > posN)
        {
            if(down > 0)
            {
                res.push_back("D" + std::to_string(down));
            }
            res.push_back("L" + std::to_string(posS - posN));
            posS = posN;
            down = 0;
        }
        else
        {
            down++;
            i++;
            if(i < carpark.size())
                posN = find(carpark[i].begin(), carpark[i].end(), 1) - carpark[i].begin();
        }
    }
    return res;
}

int main()
{
    assert(escape({{1, 0, 0, 0, 2},
                    {0, 0, 0, 0, 0}}) ==
                        (std::vector<std::string>{"L4", "D1", "R4"}));
    
    assert(escape({{2, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 0}}) ==
                        (std::vector<std::string>{"R3", "D2", "R1"}));

    assert(escape({{0, 2, 0, 0, 1},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0}}) == 
                        (std::vector<std::string>{"R3", "D3"}));

    assert(escape({{1, 0, 0, 0, 2},
                    {0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}}) == 
                        (std::vector<std::string>{"L4", "D1", "R4", "D1", "L4", "D1", "R4"}));

    assert(escape({{0, 0, 0, 0, 2}}) ==
                    (std::vector<std::string>{}));
    return 0;
}