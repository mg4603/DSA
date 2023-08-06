#include <iostream>
#include <vector>

template <typename T>
int binary_search(std::vector<T> &vec, T key)
{
    int left(0);
    int right = vec.size();
    while( left <= right)
    {
        int mid((left + right)/2);
        if(key == vec[mid])
        {
            return mid;
        }
        if(key < vec[mid]){
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
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