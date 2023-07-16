#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void swap(T a[], T b[], int size)
{
    for(int i(0); i < size; i++)
    {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<typename T>
void print_array( T array[], int size)
{
    for(int i(0); i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Overloading Templatized Functions\n\n";

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    std::cout << "Before swap: \n";
    std::cout << "a: ";
    print_array<int>(a, 5);
    std::cout << "b: ";
    print_array<int>(b, 5);

    swap(a, b, 5);

    std::cout << "After swap: \n";
    std::cout << "a: ";
    print_array<int>(a, 5);
    std::cout << "b: ";
    print_array<int>(b, 5);
    return 0;
}