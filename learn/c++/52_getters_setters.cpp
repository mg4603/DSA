#include <iostream>

// Encapsulation:
//      * ensures that the class can only be used in the intended way
//          through a well defined interface
//      * provides an interface to abstract away users from the inner
//          working of the class
//      * class methods can access private members
//      * objects cannot be used to access private members
//      * usually used when there is some logic to be encapsulated,
//          like when you intend to add checks to ensure that values
//          are within an expected range or when you intend to store
//          and display values in different formats, like when you use a
//          number to indicate a category internally but want to return a
//          string
// 

class User{
    std::string first_name;
    std::string last_name;

    std::string status;


    public:
        static int num_users;

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

        // setter for private member first_name which cannot be accessed from 
        // outside the class
        void set_first_name(std::string first_name)
        {
            this->first_name = first_name;
        }    

        // setter for private member last_name which cannot be accessed from 
        // outside the class
        void set_last_name(std::string last_name)
        {
            this->last_name = last_name;
        }

        // setter for private member status which cannot be accessed from 
        // outside the class
        void set_status(std::string status)
        {
            this->status = status;
        }
        
        // getter for private member first_name which cannot be access from 
        // outside the class
        std::string get_first_name()
        {
            return this->first_name;
        }
        
        // getter for private member last_name which cannot be accessed from 
        // outside the class
        std::string get_last_name()
        {
            return this->last_name;
        }

        // getter for private member status which cannot be accessed from 
        // outside the class
        std::string get_status()
        {
            return this->status;
        }
};


int User::num_users = 0;

int main()
{
    std::cout << "Getters & Setters\n\n";

    User user("First", "Last");
    std::cout << "Data: \n";
    std::cout << "Number of Users: " << User::num_users << std::endl;
    std::cout << "\tFirst name: " << user.get_first_name() << std::endl;
    std::cout << "\tLast name: " << user.get_last_name() << std::endl;
    std::cout << "\tStatus: " << user.get_status() << std::endl;
    return 0;
}