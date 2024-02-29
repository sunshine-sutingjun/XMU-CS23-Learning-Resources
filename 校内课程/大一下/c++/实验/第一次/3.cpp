#include <iostream>
#include <string>

using namespace std;

// 函数用于判断标识符是否合法
bool isIdentifierValid(const string& s) {
    if (!isalpha(s[0]) && s[0] != '_') return false; // 首字符检查
    for (char c : s) {
        if (!isalnum(c) && c != '_') return false; // 其余字符检查
    }
    return true;
}

int main() {
    int n;
    cin >> n; // 读取标识符数量

    string identifier;
    for (int i = 0; i < n; ++i) {
        cin >> identifier; // 读取每个标识符
        if (isIdentifierValid(identifier)) {
            cout << "Great" << endl;
        } else {
            cout << "Bad" << endl;
        }
    }

    return 0;
}