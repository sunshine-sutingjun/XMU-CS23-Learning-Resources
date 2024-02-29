#include <iostream>
#include <vector>

using namespace std;

int fibSumLastThreeDigits(int a, int b, int l, int r) {
    int f0 = a % 1000; // 只保留最后三位
    int f1 = b % 1000; // 只保留最后三位
    int sum = 0;

    // 特殊处理初始情况
    if (l == 0) sum = f0;
    if (l <= 1) sum += f1;
    sum %= 1000; // 确保和也只保留最后三位

    // 从 2 开始计算斐波那契数列，直到 r
    for (int i = 2; i <= r; ++i) {
        int f2 = (f0 + f1) % 1000; // 只保留计算结果的最后三位
        f0 = f1;
        f1 = f2;
        if (i >= l) sum = (sum + f2) % 1000; // 如果在指定范围内，将其添加到总和中
    }

    // 对于 l > 1 的情况，初始 sum 应该为 0
    // 因此，只有当索引在范围内时，才开始累加
    return sum;
}

int main() {
    int t;
    cin >> t; // 读取测试案例数量

    while (t--) {
        int a, b, l, r;
        cin >> a >> b >> l >> r; // 读取每个测试案例的参数
        cout << fibSumLastThreeDigits(a, b, l, r) << endl; // 输出结果
    }

    return 0;
}