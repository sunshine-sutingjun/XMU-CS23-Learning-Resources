#include <iostream>
#include <iomanip> // 用于设置输出格式
#include <cmath>   // 用于数学计算，包括 M_PI

using namespace std;

int main() {
    int n; // 披萨的数量
    cin >> n;

    double sumArea = 0.0; // 所有披萨的面积之和
    for (int i = 0; i < n; ++i) {
        int r, alpha; // 单个披萨的半径和圆心角
        cin >> r >> alpha;

        // 将圆心角从度转换为弧度
        double radian = alpha * M_PI / 180.0;

        // 计算单个扇形的面积并累加到总和中
        double area = 0.5 * r * r * radian;
        sumArea += area;
    }

    // 输出所有披萨的面积之和，保留三位小数
    cout << fixed << setprecision(3) << sumArea << endl;

    return 0;
}