#include <assert.h>
#include <iostream>


#include <array>
#include <vector>
#include <algorithm>

unsigned fruit(const std::array<std::vector<std::string>, 3> &reels, 
                    const std::array<unsigned, 3> &spins)
{
    unsigned res(0);
    std::string first = reels[0][spins[0]];
    std::string second = reels[1][spins[1]];
    std::string third = reels[2][spins[2]];
    std::vector<std::string> order = {
        "Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar",
        "King", "Queen", "Jack"
    };
    if(first == second && second == third){
      return 100 - (std::find(order.begin(), order.end(), first) - order.begin()) * 10;  
    }
    else if(first == second || second == third || first == third ){
        if(first == "Wild" || second == "Wild" || third == "Wild")
        {
            if((first == "Wild" && second == "Wild") ||
                (first == "Wild" && third == "Wild") ||
                (second == "Wild" && third == "Wild"))
            {
                return 10;
            }
            else
            {
                if(first == second || second == third){
                    return 2 * (10 - (std::find(order.begin(), order.end(), second) - order.begin()));
                }
                else
                {
                    return 2 * (10 - (std::find(order.begin(), order.end(), first) - order.begin()));
                }
            }
        }
        else
        {
            if(first == second || second == third)
            {
                return 10 - (std::find(order.begin(), order.end(), second) - order.begin());
            }
            else if(first == third)
            {
                return 10 - (std::find(order.begin(), order.end(), first) - order.begin());
            }
        }
    }

    return 0;
}

int main()
{
    std::array<std::vector<std::string>, 3> reels;
    std::array<unsigned, 3> spins;

    reels[0] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[1] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[2] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    spins    = {0, 0, 0};
    assert(fruit(reels, spins) == 100);

    reels[0] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[1] = {"Bar", "Wild", "Queen", "Bell", "King", "Seven", "Cherry", "Jack", "Star", "Shell"};
    reels[2] = {"Bell", "King", "Wild", "Bar", "Seven", "Jack", "Shell", "Cherry", "Queen", "Star"};
    spins    = {5, 4, 3};
    assert(fruit(reels, spins) == 0);

    reels[0] = {"King", "Cherry", "Bar", "Jack", "Seven", "Queen", "Star", "Shell", "Bell", "Wild"};
    reels[1] = {"Bell", "Seven", "Jack", "Queen", "Bar", "Star", "Shell", "Wild", "Cherry", "King"};
    reels[2] = {"Wild", "King", "Queen", "Seven", "Star", "Bar", "Shell", "Cherry", "Jack", "Bell"};
    spins    = {0, 0, 1};
    assert(fruit(reels, spins) == 3);

    reels[0] = {"King", "Jack", "Wild", "Bell", "Star", "Seven", "Queen", "Cherry", "Shell", "Bar"};
    reels[1] = {"Star", "Bar", "Jack", "Seven", "Queen", "Wild", "King", "Bell", "Cherry", "Shell"};
    reels[2] = {"King", "Bell", "Jack", "Shell", "Star", "Cherry", "Queen", "Bar", "Wild", "Seven"};
    spins    = {0, 5, 0};
    assert(fruit(reels, spins) == 6);

    return 0;
}