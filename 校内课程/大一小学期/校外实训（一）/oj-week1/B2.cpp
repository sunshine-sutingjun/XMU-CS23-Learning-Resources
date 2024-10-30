#include <iostream>
void move(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        std::cout << n << ":" << source << "->" << destination << std::endl;
        return;
    }
    move(n - 1, source, destination, auxiliary);
    std::cout << n << ":" << source << "->" << destination << std::endl;
    move(n - 1, auxiliary, source, destination);
}
int main()
{
    int n;
    char a, b, c;
    std::cin >> n;
    std::cin >> a >> b >> c;
    move(n, a, b, c);
    return 0;
}