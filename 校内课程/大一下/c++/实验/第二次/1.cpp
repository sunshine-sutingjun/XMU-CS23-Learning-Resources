#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // 定义一个长整型别名ll，用于处理大数

// 函数：计算能构成三角形的最大周长
ll maxTrianglePerimeter(vector<int> &sticks)
{
    // 首先，将所有棍子按长度从大到小排序
    sort(sticks.begin(), sticks.end(), greater<int>());
    // 遍历排序后的棍子数组
    for (int i = 0; i < sticks.size() - 2; ++i)
    {
        int a = sticks[i], b = sticks[i + 1], c = sticks[i + 2];
        // 检查当前的三根棍子是否能构成三角形
        if (a + b > c && a + c > b && b + c > a)
        {
            // 如果可以，返回这三根棍子的周长
            return ll(sticks[i] + sticks[i + 1] + sticks[i + 2]);
        }
    }
    // 如果没有找到能构成三角形的三根棍子，返回-1
    return -1;
}

int main()
{
    int n; // 用于存储输入的棍子数量
    while (cin >> n)
    {                          // 循环读取输入直到结束
        vector<int> sticks(n); // 创建一个向量存储棍子的长度
        for (int i = 0; i < n; ++i)
        {
            cin >> sticks[i]; // 读取每根棍子的长度
        }
        // 调用函数计算最大周长并输出结果
        cout << maxTrianglePerimeter(sticks) << endl;
    }
    return 0;
}
