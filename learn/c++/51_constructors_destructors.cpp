#include <iostream>
// A default constructor is created implicitly and called when an object
// is created
// 
// If a parameterized constructor is created then the default constructor
// is not created implicitly. This is done to enforce the creation of 
// objects with required arguments.
// 
// If a default constructor is required when a parameterized constructor has
// been created, it has to be explicitly defined
// 
// A constructor has the same name as the class and no return type
// A destructor has a tilde before the name of the class and no return type

class User{
    std::string first_name;
    std::string last_name;

    std::string status;


    public:
        static int num_users;

        // parameterized constructors
        User(std::string first_name, std::string last_name)
        {
            this->first_name = first_name;
            this->last_name = last_name;
            this->status = "Gold";
            num_users++;

        }

        ~User()
        {
            num_users--;
        }

        void set_first_name(std::string first_name)
        {
            this->first_name = first_name;
        }    

        void set_last_name(std::string last_name)
        {
            this->last_name = last_name;
        }
        
        void set_status(std::string status)
        {
            this->status = status;
        }
        
        std::string get_first_name()
        {
            return this->first_name;
        }
        
        std::string get_last_name()
        {
            return this->last_name;
        }
        
        std::string get_status()
        {
            return this->status;
        }
};


int User::num_users = 0;

int main()
{
    std::cout << "Constructor & Destructors\n\n";

    User user("First", "Last");
    std::cout << "Data: \n";
    std::cout << "Number of Users: " << User::num_users << std::endl;
    std::cout << "\tFirst name: " << user.get_first_name() << std::endl;
    std::cout << "\tLast name: " << user.get_last_name() << std::endl;
    std::cout << "\tStatus: " << user.get_status() << std::endl;
    return 0;
}