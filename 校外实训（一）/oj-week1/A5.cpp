#include <iostream>
#include <cstring>
using namespace std;
string left_strings[3];
string right_strings[3];
string result[3];
bool isFeitcoin(char icoin, bool islight)
{
    string c;
    c.push_back(icoin);
    for (int i = 0; i < 3; i++)
    {
        string l = left_strings[i], r = right_strings[i];
        if (!islight)
        {
            swap(l, r);
        }
        switch (result[i][0])
        {
        case 'e':
            if (l.find(c) != string::npos || r.find(c) != string::npos)
                return false;
            break;
        case 'u':
            if (r.find(c) == string::npos)
                return false;
            break;
        case 'd':
            if (l.find(c) == string::npos)
                return false;
            break;

        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> left_strings[i] >> right_strings[i] >> result[i];
        }
        for (char icoin = 'A'; icoin <= 'L'; icoin++)
        {
            if (isFeitcoin(icoin, true))
            {
                cout << icoin << " is the counterfeit coin and it is light. " << endl;
                break;
            }
            else if (isFeitcoin(icoin, false))
            {
                cout << icoin << " is the counterfeit coin and it is heavy. " << endl;
                break;
            }
        }
    }
    return 0;
}