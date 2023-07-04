#include <assert.h>
#include <iostream>

#include <vector>

std::vector<std::string> splitMessage(std::string message, int count)
{
    if(count <= 0)return std::vector<std::string>();
    if(message.size() == 0)
    {
        return std::vector<std::string>(count, "");
    }
    std::vector<std::string> res(count, std::string(message.size(), '-'));

    for(int i(0); i < message.size(); i += count)
    {
        for(int j(0); j + i < message.size() && j < count; j++)
        {
            res[j][i+j] = message[i + j];
        }    
    }
    return res;
}

int main()
{
    std::vector<std::string> expected =
    {
        "I--h--k--o--a-- --l--e--",
        "- --i-- --u--r--a-- --x-",
        "--t--n--y-- --e--l--s--y"
    };
    
    std::vector<std::string> actual = splitMessage("I think you are all sexy", 3);

    assert(actual == expected);
}