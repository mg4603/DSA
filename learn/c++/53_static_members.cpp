#include <iostream>

class User{
    // static members and methods apply to all objects of the class
    static int user_count;

    std::string first_name;
    std::string last_name;
    
    std::string status;

    public:
        // static members can only be returned by static function
        static int get_user_count()
        {
            return user_count;
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

// static members have to be initialized out-of-line:
//      Memory is allocated only when objects are created, not when the class is
//      defined. But static members are associated with the class and not any 
//      particular object. So, static members have to given memory at some other
//      point in time by initializing them out-of-line.
// 
int User::user_count = 0;

int main()
{
    std::cout << "Static Data Members\n\n";

    User user("First", "Last");
    std::cout << "Data: \n";
    std::cout << "Number of Users: " << User::get_user_count() << std::endl;
    std::cout << "\tFirst name: " << user.get_first_name() << std::endl;
    std::cout << "\tLast name: " << user.get_last_name() << std::endl;
    std::cout << "\tStatus: " << user.get_status() << std::endl;
    return 0;
}