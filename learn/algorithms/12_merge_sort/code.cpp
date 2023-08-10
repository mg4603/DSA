#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T> &vec, int left, int mid, int high)
{
    int i(left);
    int j(mid + 1);
    std::vector<T> temp;
    while( i <=  mid && j <= high)
    {
        if(vec[i] < vec[j])
        {
            temp.push_back(vec[i++]);
        }
        else
        {
            temp.push_back(vec[j++]);
        }
    }
    while(i <= mid)
    {
        temp.push_back(vec[i++]);
    }
    while(j <= high)
    {
        temp.push_back(vec[j++]);
    }
    
    int k(left);
    i = 0;
    while(k <= high)
    {
        vec[k++] = temp[i++]; 
    }
}

template <typename T>
void merge_sort(std::vector<T> &vec, int left, int right)
{
    if(left < right)
    {
        int mid((left + right) / 2);
        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

template <typename T>
void merge_sort(std::vector<T> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

template <typename T>
void print_vector(std::vector<T> &vec)
{
    for(T ele: vec)
    {
        std::cout << ele <<  ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec({1, 4, 5, 7, 2, 9, 0, 15, -6});

    std::cout << "Before sort:\n";
    print_vector<int>(vec);

    merge_sort<int>(vec);
    std::cout << "After sort:\n";
    print_vector<int>(vec);
    return 0;
}