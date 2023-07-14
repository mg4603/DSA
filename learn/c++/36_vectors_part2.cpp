#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// when vectors are passed into functions, a copy of the argument is stored
// in the parameter and operated on. Any change made to the data in the 
// function is not reflected on the argument.
void print_vector(std::vector<int> data)
{
    // appending new value to data doesn't reflect so last value will 
    // always be 11
    data.push_back(11);
    for(int i(0); i < static_cast<int>(data.size()); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

// vectors can be passed by reference when you intend to reflect changes
// made to data in the function on to the argument
void append_random_num(std::vector<int> &data)
{
    data.push_back(rand() % 10);
}

int main()
{
    srand(time(NULL));
    std::cout << "Vectors Part 2: Passing Vectors to Functions\n\n";
    std::vector<int> data({1, 2, 3, 4, 5, 6, 7});
    print_vector(data);
    append_random_num(data);
    print_vector(data);
    append_random_num(data);
    print_vector(data);

    return 0;
}