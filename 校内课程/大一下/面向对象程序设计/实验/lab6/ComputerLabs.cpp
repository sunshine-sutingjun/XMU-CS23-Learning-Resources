#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Define a class to represent a computer station
class ComputerStation
{
private:
    string userId;

public:
    int labNumber;
    int stationNumber;

    // Constructor
    ComputerStation(int stationNum) : stationNumber(stationNum) {}

    // Method to log in a user
    void login(const string &userId)
    {
        this->userId = userId;
    }

    // Method to log off a user
    void logout()
    {
        userId.clear();
    }

    // Method to check if the station is occupied
    bool isOccupied() const
    {
        return !userId.empty();
    }

    // Method to get the user ID logged into the station
    string getUserId() const
    {
        return userId;
    }
};

// Define a class to represent a computer lab
class ComputerLab
{
private:
    vector<ComputerStation> stations;

public:
    ComputerLab() {}

    // Constructor
    ComputerLab(int numStations)
    {
        for (int i = 1; i <= numStations; ++i)
        {
            stations.emplace_back(ComputerStation(i));
        }
    }

    // Method to log in a user to a station
    bool login(int stationNumber, const string &userId)
    {
        if (stationNumber <= 0 || stationNumber > stations.size())
        {
            return false; // Invalid station number
        }
        if (stations[stationNumber - 1].isOccupied())
        {
            return false; // Station is already occupied
        }
        stations[stationNumber - 1].login(userId);
        return true;
    }

    // Method to log off a user from a station
    bool logout(int stationNumber)
    {
        if (stationNumber <= 0 || stationNumber > stations.size())
        {
            return false; // Invalid station number
        }
        stations[stationNumber - 1].logout();
        return true;
    }

    // Method to get the status of all stations in the lab
    string getStatus() const
    {
        stringstream ss;
        for (int i = 0; i < stations.size(); ++i)
        {
            ss << stations[i].stationNumber << ": ";
            if (stations[i].isOccupied())
            {
                ss << stations[i].getUserId();
            }
            else
            {
                ss << "empty";
            }
            if (i < stations.size() - 1)
            {
                ss << " ";
            }
        }
        return ss.str();
    }
};

// Define a class to represent a computer lab tracker
class ComputerLabTracker
{
private:
    unordered_map<int, ComputerLab> labs;
    unordered_map<string, pair<int, int>> userToLabStation;

public:
    // Constructor
    ComputerLabTracker()
    {
        for (int i = 4; i >= 1; i--)
        {
            labs[i] = ComputerLab(getNumStationsForLab(i));
        }
    }

    // Method to log in a user to a station in a lab
    string login(int labNumber, int stationNumber, const string &userId)
    {
        stringstream ss;
        bool loginSuccessFlag = 1;

        if (userToLabStation.find(userId) != userToLabStation.end())
        {
            ss << "invalid login" << endl; // User already logged in somewhere
            loginSuccessFlag = 0;
        }
        else if (labNumber < 0 || labNumber > 4 || !labs[labNumber].login(stationNumber, userId))
        {
            ss << "invalid login" << endl; // User already logged in somewhere
            loginSuccessFlag = 0;
        }

        if (loginSuccessFlag == 1)
        {
            userToLabStation[userId] = {labNumber, stationNumber};
        }

        ss << displayStatus();

        return ss.str();
    }

    // Method to log off a user from a station in a lab
    string logout(const string &userId)
    {
        stringstream result;

        if (userToLabStation.find(userId) == userToLabStation.end())
        {
            result << "invalid logoff" << endl;
        }
        else
        {
            int labNumber = userToLabStation[userId].first;
            int stationNumber = userToLabStation[userId].second;
            if (!labs[labNumber].logout(stationNumber))
            {
                result << "invalid logoff" << endl;
            }
        }
        userToLabStation.erase(userId);
        result << displayStatus();

        return result.str();
    }

    // Method to display the status of all labs
    string displayStatus() const
    {
        stringstream ss;
        for (const auto &pair : labs)
        {
            ss << pair.first << " ";
            ss << pair.second.getStatus();
            ss << endl;
        }
        return ss.str();
    }

private:
    // Helper method to get the number of stations for a lab
    int getNumStationsForLab(int labNumber) const
    {
        switch (labNumber)
        {
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 3;
        default:
            return 0; // Invalid lab number
        }
    }
};

int main()
{
    ComputerLabTracker tracker;

    // Sample input
    vector<string> input = {
        "+ SWE100 1 1",
        "+ DMT200 2 6",
        "+ SWE400 1 1",
        "+ SWE400 4 3",
        "+ SWE400 2 1",
        "+ SWE700 2 3",
        "- SWE700",
        "- DMT700",
        "+ SWE800 1 6",
        "+ SWE900 5 1",
        "- SWE700",
        "="};

    // Process input
    for (const string &line : input)
    {
        istringstream iss(line);
        char op;
        string userId;
        int labNumber, stationNumber;
        iss >> op;
        if (op == '=')
            break; // End of input
        if (op == '+')
        {
            iss >> userId >> labNumber >> stationNumber;
            string result = tracker.login(labNumber, stationNumber, userId);
            if (!result.empty())
            {
                cout << result << endl;
            }
        }
        else if (op == '-')
        {
            iss >> userId;
            string result = tracker.logout(userId);
            if (!result.empty())
            {
                cout << result << endl;
            }
        }
    }

    return 0;
}
