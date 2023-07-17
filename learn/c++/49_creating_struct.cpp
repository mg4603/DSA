#include <iostream>

// by convention used to group simple data structures into meaningful units,
// and doesn't include methods, but can include methods
struct User
{
    // by default struct members and methods are public
    std::string first_name;
    std::string last_name;
    std::string get_status()
    {
        return status;
    }
    void set_status(std::string status)
    {
        this->status = status;
    }
    // access modifier than makes members and methods private
    private:
        std::string status;

};

int main()
{
    std::cout << "Creating A Struct\n\n";
    // Create object
    User user;
    // access public user members and methods
    user.first_name = "First";
    user.last_name = "Last";

    // private members can't be accessed from the object
    // user.status = "NA"; // won't work

    user.set_status("Alive");

    std::cout << "Output user data:\n";
    std::cout << "\tFirst Name: " << user.first_name << std::endl;
    std::cout << "\tLast Name: " << user.last_name << std::endl;
    std::cout << "\tStatus: " << user.get_status() << std::endl;
    return 0;
}