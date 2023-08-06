#include <iostream>
#include <vector>

template <typename T>
int binary_search(std::vector<T> &vec, T key, int left, int right)
{
    int mid((left + right) / 2);
    if(vec[mid] ==  key)
    {
        return mid;
    }
    if(vec[mid] < key)
    {
        return binary_search(vec, key, mid + 1, right);
    }
    else
    {
        return binary_search(vec, key, left, mid - 1);
    }
}

template <typename T>
int binary_search(std::vector<T> &vec, T key)
{
    return binary_search(vec, key, 0, vec.size());
}

int main()
{
    std::vector<int> vec = {
                        3, 6, 8, 12, 14, 17, 25, 29, 
                        31, 36, 42, 47, 53, 55, 62
                        };

    std::cout << binary_search(vec, 6) << std::endl;;
    return 0;
}