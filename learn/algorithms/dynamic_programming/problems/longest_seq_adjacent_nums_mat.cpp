#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> &vec) {
    for(T it: vec) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}

int main() {

    return 0;
}