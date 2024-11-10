#include <bits/stdc++.h>
using namespace std;

// 定义类型简化代码
typedef map<char, int> MCI;
typedef pair<char, int> PCI;

// 自定义比较函数，用于排序
bool cmp(const PCI &a, const PCI &b)
{
    if (a.second == b.second)
        // 如果频率相同，则按照ASCII码值由大到小排序
        return a.first > b.first;
    else
        // 否则，按照频率由高到低排序
        return a.second > b.second;
}

int main()
{
    string input;
    // 使用循环读取输入，直到没有更多输入
    while (cin >> input)
    {
        // 使用map统计每个字符的出现次数
        MCI cnt;
        for (auto c : input)
        {
            cnt[c]++;
        }
        // 将map中的元素复制到vector中，以便排序
        vector<PCI> charCounts(cnt.begin(), cnt.end());
        // 使用自定义的比较函数进行排序
        sort(charCounts.begin(), charCounts.end(), cmp);
        // 遍历排序后的vector，并打印字符及其出现次数
        for (auto p : charCounts)
        {
            printf("%c:%d ", p.first, p.second);
        }
        // 每输出完一个字符串的统计信息后换行
        puts("");
    }
    return 0;
}
