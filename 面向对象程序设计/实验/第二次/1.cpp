#include <iostream>
using namespace std;

// Function to calculate the nth day of 2020
int dayOfYear(int year, int month, int day) {
    // Days in each month of 2020
    int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Calculate the sum of days until the previous month
    int totalDays = 0;
    for (int i = 1; i < month; ++i) {
        totalDays += daysInMonth[i];
    }
    
    // Add the days of the current month
    totalDays += day;
    
    return totalDays;
}

int main() {
    int year, month, day;
    
    // Assuming multiple input sets as per the example, process each set
    while (cin >> year >> month >> day) {
        cout << dayOfYear(year, month, day) << endl;
    }
    
    return 0;
}