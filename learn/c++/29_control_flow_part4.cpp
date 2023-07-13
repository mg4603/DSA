#include <iostream>

void count_up(int n)
{
    std::cout << "Count to " << n << ": ";
    for(int i(0); i < n ; i++)
    {
        std::cout << i + 1 << ' ';
    }
    std::cout << std::endl;
}

void count_down(int n)
{
    std::cout << "Count down from " << n << ": ";
    for(int i(n); i > 0; i--)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int factorial(int n)
{
    for(int i(n - 1); i > 0; i--)
    {
        n *= i;
    }
    return n;
}

int main()
{
    std::cout << "Control Flow Part 4: For loops\n\n";
    count_up(10);
    std::cout << std::endl;
    count_down(10);
    std::cout << std::endl;
    std::cout << "Factorial of 5: " << factorial(5) << std::endl << std::endl;
    return 0;
}