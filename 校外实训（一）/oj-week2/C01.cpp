#include <iostream>
#include <string>
using namespace std;
string ans[9] = { "534678912","672195348","198342567","859761423","426853791","713924856","961537284","287419635","345286179" };
int main()
{
    string tmp;
    for (int i = 0; i < 9; i++)
    {
        cin >> tmp;
        if (tmp != ans[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}