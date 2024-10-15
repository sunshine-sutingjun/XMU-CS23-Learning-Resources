#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double f()
{
    string str;
    cin >> str;
    switch (str[0])
    {
    case '+':
        return f() + f();
        break;
    case '-':
        return f() - f();
        break;
    case '*':
        return f() * f();
        break;
    case '/':
        return f() / f();
        break;
    default:
        return atof(str.c_str());
        break;
    }
}
int main()
{
    printf("%f", f());
    return 0;
}