#include <iostream>
#include <vector>
using namespace std;

// 检查从(x, y)开始，沿着方向(dx, dy)是否有连续5个player棋子
bool check(const vector<string>& board, int x, int y, int dx, int dy, char player) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + i * dx, ny = y + i * dy;
        // 越界或者不是player的棋子，直接返回false
        if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size() || board[nx][ny] != player) return false;
    }
    return true;
}

// 判断是否胜利的函数
bool isWin(const vector<string>& board, char player) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == player) {
                // 检查四个方向：水平(1,0)，垂直(0,1)，对角线(1,1)和反对角线(1,-1)
                if (check(board, i, j, 1, 0, player) || check(board, i, j, 0, 1, player) ||
                    check(board, i, j, 1, 1, player) || check(board, i, j, 1, -1, player))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> board(n);
        for (int i = 0; i < n; ++i) cin >> board[i];

        // 判断胜负
        if (isWin(board, 'B')) cout << "Black" << endl;
        else if (isWin(board, 'W')) cout << "White" << endl;
        else cout << "Not so fast" << endl;
    }
    return 0;
}
