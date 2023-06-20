#include <assert.h>
#include <iostream>

#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stdexcept>

class Bundesliga
{
private:
    static int comp(std::pair<std::string, std::vector<int>> first, std::pair<std::string, std::vector<int>> second)
    {
        if(first.second.size() != 7 || second.second.size() != 7)
        {
            throw std::invalid_argument("size of compared vectors is not 7");
        }
        if(first.second[5] > second.second[5])
        {
            return 1;
        }
        else if(second.second[5] > first.second[5])
        {
            return 0;
        }
        else
        {
            int gd1(first.second[3] - first.second[4]);
            int gd2(second.second[3] - second.second[4]);
            if(gd1 > gd2)
            {
                return 1;
            }
            else if(gd2 > gd1)
            {
                return 0;
            }
            else
            {
                if(first.second[3] > second.second[3])
                {
                    return 1;
                }
                else if(second.second[3] > first.second[3]){
                    return 0;
                }
                else
                {
                    int n(std::min(first.first.size(), second.first.size()));
                    for(int i(0); i < n; i++)
                    {
                        if(tolower(first.first[i]) == tolower(second.first[i]))continue;
                            return tolower(first.first[i]) < tolower(second.first[i]);
                    }
                    return 0;
                }
            }
        }
    }

    static int posComp(std::pair<std::string, std::vector<int>> first, std::pair<std::string, std::vector<int>> second)
    {
        if(first.second.size() != 7 || second.second.size() != 7)
        {
            throw std::invalid_argument("size of compared vectors is not 7");
        }
        if(first.second[5] > second.second[5])
        {
            return 1;
        }
        else if(second.second[5] > first.second[5])
        {
            return 0;
        }
        else
        {
            int gd1(first.second[3] - first.second[4]);
            int gd2(second.second[3] - second.second[4]);
            if(gd1 > gd2)
            {
                return 1;
            }
            else if(gd2 > gd1)
            {
                return 0;
            }
            else
            {
                if(first.second[3] > second.second[3])
                {
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }

public:
    std::string table(std::vector<std::string> results)
    {
        // vec
        // 0 - matches won
        // 1 - matches drawn
        // 2 - matches lost
        // 3 - goals scored
        // 4 - goals conceded
        // 5 - points
        // 6 - matches played
        std::map<std::string, std::vector<int>> table_mp;
        for(std::string str: results)
        {
            // 6:0 FC Bayern München - Werder Bremen
            int one(0);
            int two(0);
            
            if(isdigit(str[0]))
            {
                one = stoi(str.substr(0, 1));
            }
            if(isdigit(str[2]))
            {
                two = stoi(str.substr(2, 1));
            }

            std::string first(str.substr(4, str.find_first_of('-', 4) - 5));
            std::string second(str.substr(str.find_first_of('-', 4) + 2));

            if(!table_mp.count(first))
            {
                table_mp[first] = std::vector<int>(7, 0);
            }
            if(!table_mp.count(second))
            {
                table_mp[second] = std::vector<int>(7, 0);
            }

            if(isdigit(str[0]))
            {
                table_mp[first][6]++;
                table_mp[second][6]++;
                table_mp[first][3] += one;
                table_mp[second][3] += two;
                table_mp[first][4] += two;
                table_mp[second][4] += one;

                if(one > two)
                {
                    table_mp[first][0]++;
                    table_mp[second][2]++;
                    table_mp[first][5] += 3;

                }
                else if(two > one)
                {
                    table_mp[second][0]++;
                    table_mp[first][2]++;
                    table_mp[second][5] += 3;
                }
                else
                {
                    table_mp[first][1]++;
                    table_mp[second][1]++;
                    table_mp[first][5]++;
                    table_mp[second][5]++;
                }
            }
        }

        std::stringstream ss;
        std::vector<std::pair<std::string, std::vector<int>>> table(table_mp.begin(), table_mp.end());
        sort(table.begin(), table.end(), comp);

        int pos(1);
        int bef(1);

        for(int i(0); i < table.size(); i++)
        {
            if(i > 0 && posComp(table[i - 1], table[i]))
            {
                pos = bef;
            }
            if(i > 0)
                ss << '\n';
            ss << std::right << std::setw(2) << pos << '.';
            ss << ' ';
            ss << std::left << std::setw(30) << table[i].first;
            ss << table[i].second[6] << "  ";
            ss << table[i].second[0] << "  ";
            ss << table[i].second[1] << "  ";
            ss << table[i].second[2] << "  ";
            ss << table[i].second[3] << ":";
            ss << table[i].second[4] << "  ";
            ss << table[i].second[5];
            bef++;
        }
        return ss.str();
    }
};

void fridayEveningTest()
{
    std::vector<std::string> results =
    {
        "6:0 FC Bayern Muenchen - Werder Bremen",
        "-:- Eintracht Frankfurt - Schalke 04",
        "-:- FC Augsburg - VfL Wolfsburg",
        "-:- Hamburger SV - FC Ingolstadt",
        "-:- 1. FC Koeln - SV Darmstadt",
        "-:- Borussia Dortmund - FSV Mainz 05",
        "-:- Borussia Moenchengladbach - Bayer Leverkusen",
        "-:- Hertha BSC Berlin - SC Freiburg",
        "-:- TSG 1899 Hoffenheim - RasenBall Leipzig"
    };
    
    std::string expected = 
        " 1. FC Bayern Muenchen            1  1  0  0  6:0  3\n"
        " 2. 1. FC Koeln                   0  0  0  0  0:0  0\n"
        " 2. Bayer Leverkusen              0  0  0  0  0:0  0\n"
        " 2. Borussia Dortmund             0  0  0  0  0:0  0\n"
        " 2. Borussia Moenchengladbach     0  0  0  0  0:0  0\n"
        " 2. Eintracht Frankfurt           0  0  0  0  0:0  0\n"
        " 2. FC Augsburg                   0  0  0  0  0:0  0\n"
        " 2. FC Ingolstadt                 0  0  0  0  0:0  0\n"
        " 2. FSV Mainz 05                  0  0  0  0  0:0  0\n"
        " 2. Hamburger SV                  0  0  0  0  0:0  0\n"
        " 2. Hertha BSC Berlin             0  0  0  0  0:0  0\n"
        " 2. RasenBall Leipzig             0  0  0  0  0:0  0\n"
        " 2. SC Freiburg                   0  0  0  0  0:0  0\n"
        " 2. Schalke 04                    0  0  0  0  0:0  0\n"
        " 2. SV Darmstadt                  0  0  0  0  0:0  0\n"
        " 2. TSG 1899 Hoffenheim           0  0  0  0  0:0  0\n"
        " 2. VfL Wolfsburg                 0  0  0  0  0:0  0\n"
        "18. Werder Bremen                 1  0  0  1  0:6  0";
    
    Bundesliga bundesLiga;
    
    std::string actual = bundesLiga.table(results);

    assert("\n" + actual == ("\n" + expected));
}

void saturdayEveningTest()
{
    std::vector<std::string> results =
    {
        "6:0 FC Bayern Muenchen - Werder Bremen",
        "1:0 Eintracht Frankfurt - Schalke 04",
        "0:2 FC Augsburg - VfL Wolfsburg",
        "1:1 Hamburger SV - FC Ingolstadt",
        "2:0 1. FC Koeln - SV Darmstadt",
        "2:1 Borussia Dortmund - FSV Mainz 05",
        "2:1 Borussia Moenchengladbach - Bayer Leverkusen",
        "-:- Hertha BSC Berlin - SC Freiburg",
        "-:- TSG 1899 Hoffenheim - RasenBall Leipzig"
    };
    
    std::string expected = 
        " 1. FC Bayern Muenchen            1  1  0  0  6:0  3\n" 
        " 2. 1. FC Koeln                   1  1  0  0  2:0  3\n"
        " 2. VfL Wolfsburg                 1  1  0  0  2:0  3\n"
        " 4. Borussia Dortmund             1  1  0  0  2:1  3\n"
        " 4. Borussia Moenchengladbach     1  1  0  0  2:1  3\n"
        " 6. Eintracht Frankfurt           1  1  0  0  1:0  3\n"
        " 7. FC Ingolstadt                 1  0  1  0  1:1  1\n"
        " 7. Hamburger SV                  1  0  1  0  1:1  1\n"
        " 9. Hertha BSC Berlin             0  0  0  0  0:0  0\n"
        " 9. RasenBall Leipzig             0  0  0  0  0:0  0\n"
        " 9. SC Freiburg                   0  0  0  0  0:0  0\n"
        " 9. TSG 1899 Hoffenheim           0  0  0  0  0:0  0\n"
        "13. Bayer Leverkusen              1  0  0  1  1:2  0\n"
        "13. FSV Mainz 05                  1  0  0  1  1:2  0\n"
        "15. Schalke 04                    1  0  0  1  0:1  0\n"
        "16. FC Augsburg                   1  0  0  1  0:2  0\n"
        "16. SV Darmstadt                  1  0  0  1  0:2  0\n"
        "18. Werder Bremen                 1  0  0  1  0:6  0";
    
    Bundesliga bundesLiga;
    
    std::string actual = bundesLiga.table(results);

    assert("\n" + actual == ("\n" + expected));
}

void sundayEveningTest()
{
    std::vector<std::string> results =
    {
        "6:0 FC Bayern Muenchen - Werder Bremen",
        "1:0 Eintracht Frankfurt - Schalke 04",
        "0:2 FC Augsburg - VfL Wolfsburg",
        "1:1 Hamburger SV - FC Ingolstadt",
        "2:0 1. FC Koeln - SV Darmstadt",
        "2:1 Borussia Dortmund - FSV Mainz 05",
        "2:1 Borussia Moenchengladbach - Bayer Leverkusen",
        "2:1 Hertha BSC Berlin - SC Freiburg",
        "2:2 TSG 1899 Hoffenheim - RasenBall Leipzig"
    };
    
    std::string expected = 
        " 1. FC Bayern Muenchen            1  1  0  0  6:0  3\n"
        " 2. 1. FC Koeln                   1  1  0  0  2:0  3\n"
        " 2. VfL Wolfsburg                 1  1  0  0  2:0  3\n"
        " 4. Borussia Dortmund             1  1  0  0  2:1  3\n"
        " 4. Borussia Moenchengladbach     1  1  0  0  2:1  3\n"
        " 4. Hertha BSC Berlin             1  1  0  0  2:1  3\n"
        " 7. Eintracht Frankfurt           1  1  0  0  1:0  3\n"
        " 8. RasenBall Leipzig             1  0  1  0  2:2  1\n"
        " 8. TSG 1899 Hoffenheim           1  0  1  0  2:2  1\n"
        "10. FC Ingolstadt                 1  0  1  0  1:1  1\n"
        "10. Hamburger SV                  1  0  1  0  1:1  1\n"
        "12. Bayer Leverkusen              1  0  0  1  1:2  0\n"
        "12. FSV Mainz 05                  1  0  0  1  1:2  0\n"
        "12. SC Freiburg                   1  0  0  1  1:2  0\n"
        "15. Schalke 04                    1  0  0  1  0:1  0\n"
        "16. FC Augsburg                   1  0  0  1  0:2  0\n"
        "16. SV Darmstadt                  1  0  0  1  0:2  0\n"
        "18. Werder Bremen                 1  0  0  1  0:6  0";
    
    Bundesliga bundesLiga;
    
    std::string actual = bundesLiga.table(results);

    assert("\n" + actual == ("\n" + expected));
}


int main()
{
    fridayEveningTest();
    saturdayEveningTest();
    sundayEveningTest();
    return 0;
}