#include "ComputerLab.h"
#include <iostream>

ComputerLab::ComputerLab()
{
    labs[1] = std::vector<std::string>(5, "empty");
    labs[2] = std::vector<std::string>(6, "empty");
    labs[3] = std::vector<std::string>(4, "empty");
    labs[4] = std::vector<std::string>(3, "empty");
}

void ComputerLab::operator+(LoginReq &r)
{
    if (r.labNumber < 1 || r.labNumber > 4 || r.stationNumber < 1 || r.stationNumber > labs[r.labNumber].size())
    {
        std::cout << "invalid login" << std::endl;
        displayStatus();
        return;
    }
    if (loggedInUsers.find(r.userPointer->getId()) != loggedInUsers.end())
    {
        std::cout << "invalid login" << std::endl;
        displayStatus();
        return;
    }
    if (labs[r.labNumber][r.stationNumber - 1] != "empty")
    {
        std::cout << "invalid login" << std::endl;
        displayStatus();
        return;
    }

    labs[r.labNumber][r.stationNumber - 1] = r.userPointer->getId();
    loggedInUsers[r.userPointer->getId()] = {r.labNumber, r.stationNumber};
    displayStatus();
}

void ComputerLab::operator-(LogoffReq &r)
{
    auto it = loggedInUsers.find(r.userPointer->getId());
    if (it == loggedInUsers.end())
    {
        std::cout << "invalid logoff" << std::endl;
        displayStatus();
        return;
    }

    int labNumber = it->second.first;
    int stationNumber = it->second.second;
    labs[labNumber][stationNumber - 1] = "empty";
    loggedInUsers.erase(it);
    displayStatus();
}

void ComputerLab::displayStatus() const
{
    for (const auto &lab : labs)
    {
        std::cout << lab.first << " ";
        for (size_t i = 0; i < lab.second.size(); ++i)
        {
            std::cout << i + 1 << ": " << lab.second[i] << " ";
        }
        std::cout << std::endl;
    }
}
