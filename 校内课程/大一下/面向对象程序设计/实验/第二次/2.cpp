#include <bits/stdc++.h>
using namespace std;

// 判断是否为峰值数的函数
bool isPeakNumber(int n)
{
    string num = to_string(n); // 将整数转换为字符串，以便逐字符比较
    int trend = 0, last = 0;   // trend用于记录当前趋势，last用于记录上一个趋势
    for (int i = 1; i < num.length(); i++)
    {
        last = trend; // 更新last为上一次的趋势
        // 判断当前数字与前一个数字的关系，更新trend
        if (num[i] > num[i - 1])
        {
            trend = 1; // 递增
        }
        else if (num[i] < num[i - 1])
        {
            trend = -1; // 递减
        }
        // 如果发现趋势由递增变为递减，说明形成了峰顶
        if (last == 1 && trend == -1)
        {
            return true; // 找到峰顶，返回1
        }
    }
    // 未找到峰顶，返回0
    return false;
}

int main()
{
    int n;
    while (cin >> n) // 循环读取输入
    {
        // 根据isPeakNumber函数的返回值判断并输出结果
        if (!isPeakNumber(n)) // 如果不是峰值数
        {
            puts("Yes"); // 输出Yes
        }
        else // 如果是峰值数
        {
            puts("No"); // 输出No
        }
    }
    return 0;
}