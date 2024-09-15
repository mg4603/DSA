#include <iostream>
#include <vector>

int longest_repeated_subseq(std::string s, int i, int j) {
    if(i == s.length() || j == s.length())return 0;

    if(s[i] == s[j] && i != j) {
        return 1 + longest_repeated_subseq(s, i + 1, j + 1);
    }
    return std::max(longest_repeated_subseq(s, i + 1, j), 
                longest_repeated_subseq(s, i , j + 1));
}


int main() {

    std::string s = "ATACTCGGA";
    std::cout << "The length of the longest repeated subsequnce is: " 
            << longest_repeated_subseq(s, 0, 0) << std::endl;
                
    return 0;
}