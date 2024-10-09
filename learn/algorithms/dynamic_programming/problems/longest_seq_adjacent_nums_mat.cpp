#include <iostream>
#include <vector>

std::vector<int> findLongestSeq(
                std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    std::vector<int> longestSeq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::vector<int> seq = findLongestSeq(mat, i, j);
            if(longestSeq.size() > seq.size()) {
                longestSeq = seq;
            }
        }
    }
    return longestSeq;
}

template <typename T>
void printVector(std::vector<T> &vec) {
    for(T it: vec) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> mat =
    {
        { 10, 13, 14, 21, 23 },
        { 11, 9, 22, 2, 3 },
        { 12, 8, 1, 5, 4 },
        { 15, 24, 7, 6, 20 },
        { 16, 17, 18, 19, 25 }
    };
    std::vector<int> res = findLongestPath(mat);
    printVector(res);
    return 0;
}