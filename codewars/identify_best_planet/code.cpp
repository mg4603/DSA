#include <assert.h>
#include <iostream>

#include <vector>
#include <algorithm>
static const std::vector<std::string> RQUIRED_ELEMENTS { "H", "C", "N", "O", "P", "Ca" };

bool has_required_elements(std::vector<std::string> elements)
{
    for(auto elem: RQUIRED_ELEMENTS)
    {
        if(std::find(elements.begin(), elements.end(), elem) == elements.end())
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> get_elements(std::string planet)
{
    std::vector<std::string> elements;
    int idx(0);
    std::string temp;
    while(idx < static_cast<int>(planet.size()))
    {
        if(isupper(planet[idx]) || planet[idx]  == '_')
        {
            if(temp != "")
            {
                elements.push_back(temp);
            }
            temp = "";
        }
        temp += planet[idx];
        idx++;
    }
    return elements;
}

std::string bestPlanet(const std::vector<std::string>& solarSystem, int maxSize)
{
    std::pair<std::string, int> res(std::make_pair("", 0));
    for(auto planet: solarSystem)
    {
        if(has_required_elements(get_elements(planet)))
        {
            int size(std::stoi(planet.substr(planet.find('_') + 1)));
            if(size <= maxSize && size > res.second)
            {
                res = std::make_pair(planet, size);
            }
        }
    }
    return res.first;
}

int main()
{
    std::vector<std::string> result {"OHNCCaP_100", "OHC_200", "OCa_50", 
            "OHCCaP_400", "OHNCCaP_225"};
    assert(bestPlanet(result, 250) == "OHNCCaP_225");
    result = {"OHNCCaP_225", "OHC_200", "OCa_50", "OHCCaP_400", "OUNCCaP_250"};
    assert(bestPlanet(result, 250) == "OHNCCaP_225");
    result = {"OHNCCaP_225", "OHC_200", "OCa_350", "OHCCaP_400", "OHUNCCaP_225"};
    assert(bestPlanet(result, 50) == "");
    result = {"OHNCCaP_225", "OHC_200", "OCa_50", "OHCCaP_400", "OUNCCaP_250"};
    assert(bestPlanet(result, 50) == "");
    return 0;
}