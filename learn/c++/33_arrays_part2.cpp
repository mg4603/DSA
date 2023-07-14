#include <iostream>

void print_array(int array[], int size)
{
    std::cout << "sizeof returns size of pointer to array: " << 
                sizeof(array) << std::endl;
    // the parameter decays to a pointer to the first element of array
    // losing the information that tells it how many elements the array
    // has
    std::cout <<  "Elements of the array: ";
    for(int i(0); i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Arrays Part 2: Passing arrays into functions\n\n";
    int elements[] = {1, 2, 3, 4, 5};
    std::cout << "size of array: " << sizeof(elements) << std::endl;
    print_array(elements, 5);
    std::cout << std::endl;
    return 0;
}