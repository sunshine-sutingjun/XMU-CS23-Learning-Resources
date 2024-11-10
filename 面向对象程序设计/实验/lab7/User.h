#ifndef USER_H
#define USER_H

#include <string>

class User
{
protected:
    std::string id;

public:
    User(const std::string &id) : id(id) {}
    virtual ~User() {}
    virtual std::string getType() const = 0;
    std::string getId() const { return id; }
};

class Student : public User
{
public:
    Student(const std::string &id) : User(id) {}
    std::string getType() const override { return "Student"; }
};

class Staff : public User
{
public:
    Staff(const std::string &id) : User(id) {}
    std::string getType() const override { return "Staff"; }
};

#endif // USER_H
