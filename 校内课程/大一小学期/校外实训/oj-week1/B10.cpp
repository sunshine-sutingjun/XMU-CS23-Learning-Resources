#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
vector<string> ans;
void dfs(int n)
{
    bitset<16> a(n);
    bool isFirstOne = true;
    for (int i = 15; i >= 0; i--)
    {
        if (a.test(i))
        {
            if (!isFirstOne)
            {
                ans.push_back("+");
            }
            else
                isFirstOne = false;
            if (i == 0)
                ans.push_back("2(0)");
            else if (i == 1)
                ans.push_back("2");
            else
            {
                ans.push_back("2");
                ans.push_back("(");
                dfs(i);
                ans.push_back(")");
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    dfs(n);
    for (auto l : ans)
        cout << l;
    cout << endl;
    return 0;
}