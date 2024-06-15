#include <iostream>
#include <sstream>
#include "User.h"
#include "ComputerLab.h"

int main()
{
    ComputerLab lab;
    std::string input;
    while (std::getline(std::cin, input))
    {
        if (input == "=")
            break;

        std::istringstream iss(input);
        char action;
        std::string userId;
        int labNumber, stationNumber;

        iss >> action;
        if (action == '+')
        {
            iss >> userId >> labNumber >> stationNumber;
            User *user;
            if (userId.substr(0, 3) == "SWE")
            {
                user = new Student(userId);
            }
            else
            {
                user = new Staff(userId);
            }
            LoginReq req = {user, labNumber, stationNumber};
            lab + req;
        }
        else if (action == '-')
        {
            iss >> userId;
            User *user;
            if (userId.substr(0, 3) == "SWE")
            {
                user = new Student(userId);
            }
            else
            {
                user = new Staff(userId);
            }
            LogoffReq req = {user};
            lab - req;
        }
    }

    return 0;
}
