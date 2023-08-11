#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
int partition(std::vector<T> & vec, int low, int high)
{
    T pivot = vec[high];
    int i = low - 1;

    for(int j(low); j < high; j++)
    {
        if(vec[j] < pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }

    }
    std::swap(vec[i + 1], vec[high]);
    
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T> &vec, int low, int high)
{
    if(low < high)
    {
        int j = partition(vec, low, high);
        quick_sort(vec, low, j - 1);
        quick_sort(vec, j + 1, high);
    }
}

template <typename T>
void quick_sort(std::vector<T> &vec)
{
    std::random_shuffle(vec.begin(), vec.end());
    quick_sort(vec, 0, vec.size() - 1);
}

template <typename T>
void print_vector(std::vector<T> &vec)
{
    for(T ele: vec)
    {
        std::cout << ele << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1, 5, 2, -6, 7, 3, 9, -11};
    std::cout << "Vector before sort:\n";
    print_vector<int>(vec);
    quick_sort(vec);
    std::cout << "Vector after sort:\n";
    print_vector<int>(vec);
    return 0;
}