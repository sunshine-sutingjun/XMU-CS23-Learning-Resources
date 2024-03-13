#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 函数用于将字符串形式的整数转换为十进制整数
long long convertToDecimal(const string& num) {
    if (num[0] == '0') {
        if (num.size() > 1 && num[1] == 'x') { // 十六进制
            return stoll(num, nullptr, 16);
        } else if (num.size() > 1 && num[1] == 'b') { // 二进制
            return stoll(num.substr(2), nullptr, 2);
        } else { // 八进制
            return stoll(num, nullptr, 8);
        }
    }
    // 十进制
    return stoll(num);
}

int main() {
    string input;
    getline(cin, input); // 读取一行输入
    stringstream ss(input);
    vector<long long> numbers;
    string num;

    // 使用逗号作为分隔符读取和转换每个数
    while (getline(ss, num, ',')) {
        numbers.push_back(convertToDecimal(num));
    }

    // 对转换后的十进制数进行排序
    sort(numbers.begin(), numbers.end());

    // 输出排序后的数
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) cout << ","; // 数字间以逗号隔开
        cout << numbers[i];
    }

    return 0;
}