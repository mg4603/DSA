#include <iostream>
#include <vector>

int shortestCommonSupersequenceLength(
            std::string s1, std::string s2,
            int m, int n){

    if(m == 0 || n == 0){
        return m + n;
    }

    if(s1[m - 1] == s2[n - 1]) {
        return shortestCommonSupersequenceLength(
                        s1, s2, m - 1, n - 1) + 1;
    }
    return std::min(
        shortestCommonSupersequenceLength(s1, s2, m - 1, n) + 1,
        shortestCommonSupersequenceLength(s1, s2, m, n - 1) + 1);
}

int memoShortestCommonSupersequenceLength(
        std::string s1, std::string s2,
        int m, int n, 
        std::vector<std::vector<int>> &memo) {

        if(m == 0 || n == 0) {
            return m + n;
        }

        if(memo[m][n] != 0)return memo[m][n];

        if(s1[m - 1] == s2[n - 1]) {
            memo[m][n] = memoShortestCommonSupersequenceLength(s1, s2,
                            m - 1, n - 1, memo) + 1;
        }else {
            memo[m][n] = 
                std::min(
                  memoShortestCommonSupersequenceLength(
                    s1, s2, m - 1, n, memo) + 1,
                  memoShortestCommonSupersequenceLength(
                    s1, s2, m, n - 1, memo) + 1);
        }
        return memo[m][n];
}

int tableShortestCommonSupersequenceLength(
    std::string s1, std::string s2,
    int m, int n, std::vector<std::vector<int>> &table) {
    
    for(int i = 0; i <= m; i++) {
        table[i][0] = 0;
    }

    for(int j = 0; j <= n; j++) {
        table[0][j] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                table[i][j] = 1 + table[i - 1][j - 1];
            }else {
                if(table[i - 1][j] < table[i][j - 1]) {
                    table[i][j] = 1 + table[i - 1][j];
                }else {
                    table[i][j] = 1 + table[i][j - 1];
                }
            }
        }
    }
    return table[m][n];
}

int main() {
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCABA";
    int m = s1.length(), n = s2.length();
    std::cout << "Len of shortest common supersequence: " 
            << shortestCommonSupersequenceLength(s1, s2, m, n) 
            << std::endl;
    
    std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, 0));
    std::cout << "Len of shortest common supersequence(memo): " 
            << memoShortestCommonSupersequenceLength(s1, s2, m, n, memo)
            << std::endl;

    std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));
    std::cout << "Len of shortest common supersequence(table): " 
            << memoShortestCommonSupersequenceLength(s1, s2, m, n, memo)
            << std::endl;
    return 0;
}