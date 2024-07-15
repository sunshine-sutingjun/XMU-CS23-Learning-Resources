#include <iostream>
#include <cstring>
#include <bitset>
#include <memory>
using namespace std;
bitset<6> source[5], lights[5], result[5], line;
void Output(int t)
{
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				int x;
				cin >> x;
				source[i].set(j, x);
			}
		}
		for (int n = 0; n < 64; n++)
		{
			for (int i = 0; i < 5; i++)
				lights[i] = source[i];
			line = n;
			for (int i = 0; i < 5; i++)
			{
				result[i] = line;
				for (int j = 0; j < 6; j++)
				{
					if (line.test(j))
					{
						if (j > 0)
							lights[i].flip(j - 1);
						lights[i].flip(j);
						if (j < 5)
							lights[i].flip(j + 1);
					}
				}
				if (i < 4)
					lights[i + 1] ^= line;
				line = lights[i];
			}
			if (lights[4].none())
			{
				Output(t);
				break;
			}
		}
	}
	return 0;
}