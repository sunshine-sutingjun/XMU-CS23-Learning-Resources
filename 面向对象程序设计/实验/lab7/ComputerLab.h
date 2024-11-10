#ifndef COMPUTERLAB_H
#define COMPUTERLAB_H

#include <string>
#include <map>
#include <vector>
#include "User.h"

struct LoginReq
{
    User *userPointer;
    int labNumber;
    int stationNumber;
};

struct LogoffReq
{
    User *userPointer;
};

class ComputerLab
{
private:
    std::map<int, std::vector<std::string>> labs;
    std::map<std::string, std::pair<int, int>> loggedInUsers;

public:
    ComputerLab();
    void operator+(LoginReq &r);
    void operator-(LogoffReq &r);
    void displayStatus() const;
};

#endif // COMPUTERLAB_H
