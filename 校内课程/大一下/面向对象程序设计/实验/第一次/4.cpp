#include <iostream>
#include <cmath>
using namespace std;

struct Circle {
    double x, y, r; // 圆的坐标(x, y)和半径r
};

// 计算两个圆心之间的距离
double distance(const Circle& a, const Circle& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n, p;
    cin >> n; // 读取圆的数量
    Circle circles[n]; // 存储所有圆的数组

    // 读取圆的信息
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    cin >> p; // 读取玩家所在圆的索引

    bool hit = false; // 标记玩家是否中弹
    for (int i = 0; i < n; ++i) {
        if (i == p) continue; // 跳过玩家自己
        double dist = distance(circles[p], circles[i]); // 计算圆心距
        if (dist < circles[p].r + circles[i].r) {
            // 如果两圆相交
            hit = true;
            break;
        }
    }

    if (hit) cout << "Biu" << endl;
    else cout << "Alive" << endl;

    return 0;
}