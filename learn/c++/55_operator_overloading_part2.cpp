#include <iostream>

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

};

std::ostream& operator << (std::ostream &output, User & user)
{
    output << "\tFirst name: " << user.get_first_name() << std::endl;
    output << "\tLast name: " << user.get_last_name() << std::endl;
    output << "\tStatus: " << user.get_status();
    return output;
}

std::istream & operator >> (std::istream &input, User &user)
{
    std::string first_name;
    std::string last_name;
    input >> first_name >> last_name;
    user.set_first_name(first_name);
    user.set_last_name(last_name);
    return input;
}


int User::user_count = 0;

int main()
{
    std::cout << "Operator Overloading Part2: insertion and extraction\n\n";

    // User user("First", "Last");
    User user;
    std::cout << "Enter First and last name separated by space: \n";
    std::cin >> user;
    std::cout << "Data: \n";
    std::cout << "Number of Users: " << User::get_user_count() << std::endl;
    std::cout << user << std::endl;
    return 0;
}