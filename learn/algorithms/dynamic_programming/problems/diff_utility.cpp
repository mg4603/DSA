#include <iostream>
#include <vector>

std::vector<std::vector<int>> findLCS(std::string s1, std::string s2) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }else {
                table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table;
}

int main() {

    return 0;
}