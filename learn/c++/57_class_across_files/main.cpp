#include <iostream>
#include "user.h"

int main()
{
    std::cout << "Friend Functions: Operator overloading\n\n";

    // User user("First", "Last");
    User user;
    std::cout << "Enter First and last name separated by space: \n";
    std::cin >> user;
    std::cout << "Data: \n";
    std::cout << "Number of Users: " << User::get_user_count() << std::endl;
    std::cout << user << std::endl;
    return 0;
}