#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string encryption_rule, encrypted_text, decrypted_text = "";
    getline(cin, encryption_rule); // 读取加密规则
    getline(cin, encrypted_text); // 读取加密后的文本，包括空格

    // 构建解密映射
    map<char, char> decrypt_map;
    for (int i = 0; i < 26; ++i) {
        decrypt_map[encryption_rule[i]] = 'A' + i;
    }

    bool lastWasSpace = true; // 跟踪上一个字符是否是空格

    // 解密文本
    for (char ch : encrypted_text) {
        if (isupper(ch)) { // 如果是大写字母，则解密
            decrypted_text += decrypt_map[ch];
            lastWasSpace = false; // 更新状态
        } else if (ch == ' ' && !lastWasSpace) { // 如果是空格且前一个字符不是空格，则保留一个空格
            decrypted_text += ch;
            lastWasSpace = true; // 更新状态
        }
        // 如果是连续空格，则跳过
    }

    // 如果解密后的文本以空格结尾，移除它
    if (!decrypted_text.empty() && decrypted_text.back() == ' ') {
        decrypted_text.pop_back();
    }

    cout << decrypted_text << endl; // 输出解密后的文本

    return 0;
}