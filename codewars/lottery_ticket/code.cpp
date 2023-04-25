#include <assert.h>
#include <iostream>

#include <string>
#include <vector>
typedef std::pair<std::string, int> p;

std::string bingo(std::vector<p> ticket, int win){
    int count(0);
    for(auto pair: ticket){
        if(pair.first.find(pair.second) != std::string::npos)count++;
    }
    if(count >= win)return "Winner!";
    return "Loser!";
}

int main(){
    assert(bingo({p("ABC", 65), p("HGR", 74), p("BYHT", 74)}, 2) == "Loser!");
    assert(bingo({p("ABC", 65), p("HGR", 74), p("BYHT", 74)}, 1) == "Winner!");
    assert(bingo({p("HGTYRE", 74), p("BE", 66), p("JKTY", 74)}, 3) == "Loser!");
}