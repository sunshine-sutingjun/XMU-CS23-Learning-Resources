#include <bits/stdc++.h>
using namespace std;
string mv[10] = {"", "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
int ori_t[9], t[9]; // ori_t[i]:i+'A'的时间 t:临时数组，为ori_t的复制
int m[10], a[10];	// m[i]:第i种移动执行的次数 a[i]:总执行次数最少时，第i种移动执行的次数
void move()			// 根据m数组执行移动
{
	for (int i = 1; i <= 9; ++i)
	{
		string s = mv[i];
		for (int j = 1; j <= m[i]; ++j) // 第i种移动执行m[i]次
			for (int k = 0; k < s.length(); ++k)
				t[s[k] - 'A'] = (t[s[k] - 'A'] + 1) % 4;
	}
}
bool isAllZero() // 判断是否所有的时钟都是12点，即t[0]~t[8]都是0
{
	for (int i = 0; i < 9; ++i)
		if (t[i] != 0)
			return false;
	return true;
}
int sumMoveTimes() // 求总移动次数
{
	int sum = 0;
	for (int i = 1; i <= 9; ++i)
		sum += m[i];
	return sum;
}
int main()
{
	int mn = 50; // 最少移动次数
	for (int i = 0; i < 9; ++i)
		cin >> ori_t[i];
	for (m[1] = 0; m[1] < 4; ++m[1])
		for (m[2] = 0; m[2] < 4; ++m[2])
			for (m[3] = 0; m[3] < 4; ++m[3])
				for (m[4] = 0; m[4] < 4; ++m[4])
					for (m[5] = 0; m[5] < 4; ++m[5])
						for (m[6] = 0; m[6] < 4; ++m[6])
							for (m[7] = 0; m[7] < 4; ++m[7])
								for (m[8] = 0; m[8] < 4; ++m[8])
									for (m[9] = 0; m[9] < 4; ++m[9])
									{
										memcpy(t, ori_t, sizeof(ori_t));
										move();
										if (isAllZero())
										{
											int mt = sumMoveTimes();
											if (mt < mn) // 如果mt比最少移动次数mn还少
											{
												mn = mt;
												memcpy(a, m, sizeof(m)); // 记录各移动的执行次数
											}
										}
									}
	for (int i = 1; i <= 9; ++i) // 根据a数组输出序列
	{
		while (a[i] > 0)
		{
			cout << i << ' ';
			a[i]--;
		}
	}
	return 0;
}