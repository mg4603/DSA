#include <iostream>
#include <vector>

int shortestCommonSupersequenceLength(
            std::string s1, std::string s2,
            int m, int n){

    if(m == 0 || n == 0){
        return m + n;
    }

    if(s1[m - 1] == s2[n - 1]) {
        return 1 + shortestCommonSupersequenceLength(
                        s1, s2, m - 1, n - 1);
    }
    return std::min(
        shortestCommonSupersequenceLength(s1, s2, m - 1, n),
        shortestCommonSupersequenceLength(s1, s2, m, n - 1));
}

int main() {
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCABA";
    int m = s1.length(), n = s2.length();
    std::cout << "Len of shortest common supersequence: " 
            << shortestCommonSupersequenceLength(s1, s2, m, n) 
            << std::endl;
    return 0;
}