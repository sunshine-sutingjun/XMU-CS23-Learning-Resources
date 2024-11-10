#include <iostream>
#include <vector>

using namespace std;

int fibSumLastThreeDigits(int a, int b, int l, int r) {
    vector<int> f(r + 1); // 使用向量来存储斐波那契数列
    f[0] = a % 1000; // 保留最后三位
    f[1] = b % 1000; // 保留最后三位
    int sum = 0;

    // 计算整个斐波那契数列直到r
    for (int i = 2; i <= r; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % 1000;
    }

    // 累加指定范围内的斐波那契数
    for (int i = l; i <= r; ++i) {
        sum = (sum + f[i]) % 1000;
    }

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