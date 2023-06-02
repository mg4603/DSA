#include <assert.h>
#include <iostream>

#include <string>
#include <algorithm>
#include <random>
#include <set>
using uint = unsigned int;

class PhotoManager
{
    private:
        std::set<std::string> names;
    public:
        PhotoManager()
        {}
        bool nameWasUnique(std::string name);
};

bool PhotoManager::nameWasUnique(std::string name)
{
    if(names.find(name) != names.end())
    {
        return false;
    }
    return true;
}

std::string generateName()
{
    PhotoManager *photoManager = new PhotoManager();
    std::string chs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string res;
    while(true)
    {
        std::string temp;
        std::sample(chs.begin(), chs.end(), std::back_inserter(temp),
                6, std::mt19937{std::random_device{}()});
        if(photoManager->nameWasUnique(temp))
        {
            res = temp;
            break;
        }
    }
    return res;
}

int main()
{
    PhotoManager *photoManager = new PhotoManager();
    for(uint i = 0; i < 10; i++)
    {
        std::string name = generateName();
        assert(photoManager->nameWasUnique(name) == true);
        assert(name.length() == 6);
    }
    return 0;
}
