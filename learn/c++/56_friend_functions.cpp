#include <iostream>

// Friend function:
//      * function defined outside the class that can access private members
//          of the class if granted access by declaring the function inside the
//          class with the keyword friend and defining it outside it without
//          the keyword.
//      * friend function is not an method of the class and cannot be called
//          with the class object
//      * friend functions can also be used to overload operators
// 
// 

class User{
    static int user_count;

    std::string first_name;
    std::string last_name;
    
    std::string status;

    public:
        static int get_user_count()
        {
            return user_count;
        }

        User()
        {
            this->status = "Gold";
            user_count++;
        }

        User(std::string first_name, std::string last_name)
        {
            this->first_name = first_name;
            this->last_name = last_name;
            this->status = "Gold";
            user_count++;

        }

        ~User()
        {
            user_count--;
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

        // friend function
        // declared in the class & defined outside it
        friend std::ostream& operator << (std::ostream &output, User & user);
        friend std::istream & operator >> (std::istream &input, User &user);
};

// define friend function
std::ostream& operator << (std::ostream &output, User & user)
{
    output << "\tFirst name: " << user.first_name << std::endl;
    output << "\tLast name: " << user.last_name << std::endl;
    output << "\tStatus: " << user.status;
    return output;
}

std::istream & operator >> (std::istream &input, User &user)
{
    input >> user.first_name >> user.last_name;
    return input;
}


int User::user_count = 0;

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