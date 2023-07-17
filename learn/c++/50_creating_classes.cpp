#include <iostream>
#include <vector>

// classes are used by convention for complex data structures that need
// to be bundled with methods
class User{
    // members and methods are implicitly defined as private
    std::string first_name;
    std::string last_name;

    std::string status;
    // static members are associated with the class rather than any single
    // object of the class, they don't have to be called using an object

    // use public access modifier to make members or methods public
    public:
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

// returns the index of user in users if it exists and pushes it onto
// the vector if it doesn't exists
int add_user_if_not_exists(std::vector<User> &users, User user)
{
    for(int i(0); i < users.size(); i++)
    {
        if(users[i].get_first_name() == user.get_first_name() &&
            users[i].get_last_name() == user.get_last_name())
        {
            return i;
        }
    }
    users.push_back(user);
    return users.size() - 1;
}

int main()
{
    std::cout << "Creating Classes\n\n";

    // create a vector of User
    std::vector<User> users;

    // create an object - don't have to use the new key word in c++
    User user1;
    user1.set_first_name("First1");
    user1.set_last_name("Last1");

    User user2;
    user2.set_first_name("First2");
    user2.set_last_name("Last2");

    User user3;
    user3.set_first_name("First3");
    user3.set_last_name("Last3");
    
    // add user objects to the vector
    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);

    // instantiate an object of User inline
    users.push_back(User());

    std::cout << "Output data\n";
    std::cout << "\tFirst Name: " << users[0].get_first_name() << std::endl;
    std::cout << "\tLast Name: " << users[0].get_last_name() << std::endl;

    User user;
    user.set_first_name("First1");
    user.set_last_name("Last1");

    // add user if not exists and return index of element
    std::cout << "Position of user: " << add_user_if_not_exists(users, user) << std::endl;
    std::cout << "Size of users vector: " << users.size() << std::endl;
    return 0;
}