#include <iostream>

int factorial(int n)
{
    int i(n - 1);
    while(i > 1)
    {
        n *= i;
        i--;
    }
    return n;
}

int main()
{
    std::cout << "Control Flow Part 5: while and do-while loop\n\n";
    std::cout << "Factorial of 5: " << factorial(5) << std::endl << std::endl;
    // while or do-while loop condition cannot use variables declared inside
    // the loop
    // 
    // Do while loop: when the loop must execute atleast once
    //      eg: program where the user needs to guess some kind of value
    // 
    std::string password = "password123";
    std::string guess;
    do
    {
        std::cout << "Password > ";
        std::cin >> guess;
    }while(guess != password);

    return 0;
}