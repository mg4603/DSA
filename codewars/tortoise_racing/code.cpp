#include <vector>
#include <assert.h>

class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g);
};

void testequal(std::vector<int> ans, std::vector<int> sol)
{
    assert(ans == sol);
}
void dotest(int v1, int v2, int g, std::vector<int> expected)
{
    testequal(Tortoise::race(v1, v2, g), expected);
}

int main(){
    dotest(720, 850, 70, {0, 32, 18});
    dotest(820, 81, 550, {-1, -1, -1});
    dotest(80, 91, 37, {3, 21, 49});
    return 0;
}

std::vector<int> Tortoise::race(int v1, int v2, int g){
    if(v1 >= v2)return {-1, -1, -1};
    int t = g * 3600 / (v2 - v1);
    int s(t % 60);
    t /= 60;
    int m(t % 60);
    t /= 60;
    return {t, m, s};
}