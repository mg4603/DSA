#ifndef TEACHER_H
#define TEACHER_H
#include "user.h"

// Teacher class inherits from user class, meaning it inherits all members
// and methods from User class
// 
// This implies that teacher is a type of user
// 
class Teacher: public User
{
    public:
        Teacher();
        void output();
};

#endif