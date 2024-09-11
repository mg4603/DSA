#include <iostream>
#include <vector>

int longest_palindromic_subseq(std::string s, int i, int j) {
    if(i > j)return 0;
    if(i == j)return 1;

    if(s[i] == s[j]) return 2 + longest_palindromic_subseq(s, i + 1, j - 1);
    return std::max(longest_palindromic_subseq(s, i + 1, j), longest_palindromic_subseq(s, i, j - 1));
}

int main() {
    std::string s = "ABBDCACB";
    int n = s.length();
    std::cout<< "Longst Palindromic Subseq len: " << 
        longest_palindromic_subseq(s, 0, n - 1) << std::endl;
    return 0;
}