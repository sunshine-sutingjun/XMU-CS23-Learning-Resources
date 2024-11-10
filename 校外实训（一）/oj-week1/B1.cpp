#include <iostream>
void move(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        std::cout << source << "->" << destination << std::endl;
        return;
    }
    move(n - 1, source, destination, auxiliary);
    std::cout << source << "->" << destination << std::endl;
    move(n - 1, auxiliary, source, destination);
}
int main()
{
    int n;
    std::cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}