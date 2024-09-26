#include <iostream>
#include <vector>

int main() {
    std::string s1 = "kitten";
    std::string s2 = "sitting";
    int n = s1.size();
    int m = s2.size();
    std::cout << "The Levenshtein Distance is: " <<
            levenshteinDistance(s1, s2, n, m) << std::endl;
    return 0;
}