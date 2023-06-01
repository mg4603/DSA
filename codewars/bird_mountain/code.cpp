#include <iostream>
#include <assert.h>

#include <string>
#include <vector>

int peak_height(std::vector<std::string>& mountain) {

    int height(0);
    std::vector<std::vector<int>> m;
    for(std::string &s: mountain)
    {
        std::vector<int> line;
        for(char &c: s)
        {
            if(c == '^')
            {
                line.push_back(1);
                height = 1;
            }
            else
            {
                line.push_back(0);
            }
        }
        m.push_back(line);
    }

    bool flag(true);
    
    while(flag){
        flag = false;
        for(size_t i(1); i < m.size() - 1; i++)
        {
            for(size_t j(1); j < m[i].size() - 1; j++)
            {
                if(m[i][j] > 0 && (m[i][j - 1]) >= m[i][j] && m[i][j + 1] >= m[i][j] && m[i + 1][j] >= m[i][j] && m[i - 1][j] >= m[i][j])
                {
                    m[i][j] += 1;
                    height = std::max(height, m[i][j]);
                    flag = true;
                }
            }
        }
    }
    
    return height;
}

std::vector<std::string>& show(std::vector<std::string> &mountain)
{
    for(std::string s: mountain)
    {
        std::cout<<s<<std::endl;
    }
    return mountain;
}

void test1()
{
    std::vector<std::string> mountain = {
        "^^^^^^        ",
        " ^^^^^^^^     ",
        "  ^^^^^^^     ",
        "  ^^^^^       ",
        "  ^^^^^^^^^^^ ",
        "  ^^^^^^      ",
        "  ^^^^        "
    };
    assert(peak_height(show(mountain)) == 3);

}

void test2()
{
    std::vector<std::string> mountain = {
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^",
        "^^^^^^^^^^^^^^^^^^^^^"
    };
    assert(peak_height(show(mountain)) == 11);
}

int main()
{
    test1();
    test2();
    return 0;
}