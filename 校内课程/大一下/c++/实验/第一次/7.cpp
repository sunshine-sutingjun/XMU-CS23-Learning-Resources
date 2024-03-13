#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<long long, pair<int, string>> PLLIS; // 保存数值，输入顺序和原始字符串

// 读入数据并转换成十进制，同时记录原始格式和输入顺序
void readNumbers(int n, int base, vector<PLLIS>& nums, int& order) {
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        long long val = stoll(s, nullptr, base); // 根据基数转换成十进制
        nums.push_back({val, {order++, s}}); // 保存十进制值，输入顺序和原始字符串
    }
}

// 自定义比较函数，优先比较数值大小，若相等则比较输入顺序
bool cmp(const PLLIS& a, const PLLIS& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second.first < b.second.first; // 数值相同，比较输入顺序
}

int main() {
    int x, y, z, order = 0;
    cin >> x >> y >> z; // 读入三种数的个数

    vector<PLLIS> nums;
    readNumbers(x, 10, nums, order); // 读入并转换十进制数
    readNumbers(y, 8, nums, order);  // 读入并转换八进制数
    readNumbers(z, 16, nums, order); // 读入并转换十六进制数

    sort(nums.begin(), nums.end(), cmp); // 根据值大小和输入顺序排序

    // 输出最大值，保留其原始进制表示
    cout << nums[0].second.second << endl;

    return 0;
}