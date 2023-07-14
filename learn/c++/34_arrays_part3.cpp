#include <iostream>
#include <limits>

void print_array(int array[], int size)
{
    for(int i(0); i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    const int SIZE = 100;

    std::cout << "Array Part 3: User Input" << std::endl << std::endl;

    // if the array has been partially initialized during declaration, the 
    // remaining elements that haven't been initialized will be set to zero
    // if array hasn't been initialized during declaration, all the elements
    // will be set to random values.
    // 

    int elements[SIZE];
    int count(0);

    std::cout << "Enter numbers (non-numeric input to stop): " << std::endl;
    for(int i(0); i < SIZE; i++)
    {
        if(std::cin >> elements[i]) // cin returns true only if input of 
        {                           // expected type is passed in
            count++;
        }
        else
        {
            break;
        }
    }

    // when passing in input of wrong type to cin, error flag is set which
    // needs to be cleared before cin can be used to accept input later on
    std::cin.clear();

    print_array(elements, count);

    // input with cin if not directed to a variable, is stored on the buffer
    // as a result, the next time a cin statement is encountered, the buffer
    // content is automatically directed to the user.
    // 
    // this can be prevented by using cin.ignore, that ignores the specified 
    // number of characters up to the specified character.
    // 
    // numeric_limits<std::stringstream>::max() is a safer way of doing this
    // than to hard coded value.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string test;
    std::cout << "\nCheck if cin is working as expected: ";
    std::cin >> test;
    std::cout << test << std::endl << std::endl;

    return 0;
}