#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxn = 100;
int dp[maxn + 1][maxn + 1];

int main()
{
	freopen("maxcon.im", "r", stdin);
	freopen("maxcom.out", "w", stdout);

	string s1, s2;
	cin >> s1 >> s2;
	for (int i = s1.size(); i >= 0; --i)
		for (int j = s2.size(); j >= 0; --j)
		{
			if (i == s1.size() || j == s2.size())
			{
				dp[i][j] = 0;
				continue;
			}
			if (s1[i] == s2[j])
				dp[i][j] = dp[i + 1][j + 1] + 1;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	cout << dp[0][0] << endl;

	int i = 0, j = 0;
	vector <int> pos[2];

	while (i < s1.size() && j < s2.size())
	{
		if (s1[i] == s2[j])
		{
			pos[0].push_back(i);
			pos[1].push_back(j);
			++i; ++j;
		}
		else
		{
			if (dp[i + 1][j] >= dp[i][j + 1])
				++i;
			else
				++j;
		}
	}

	for (int k = 0; k < 2; ++k)
	{
		for (int i = 0; i < pos[k].size(); ++i)
			cout << pos[k][i] + 1 << ' ';
		cout << endl;
	}
}