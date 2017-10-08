#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool do_for(const vector<string>& v, const int k, const char c, int& num, int i , int j, const string S)
{

	if (j + k <= v[i].size() && v[i].substr(j, k) == S)
	{
		++num;
		return true;
	}
				
	int temp = i;
	while (temp < v.size() && v[temp][j] == c)
		++temp;
	if (temp - i >= k)
	{
		++num;
		return true;
	}

	bool l = true, r = true;
	int len = 1, x = 1;
	while (l || r)
	{
		if (r)
		{
			if (i + x < v.size() && j + x < v[i].size() && v[i + x][j + x] == c)
				++len;
			else
				r = false;
		}
		if (l)
		{
			if (i - x >= 0 && j - x >= 0 && v[i - x][j - x] == c)
				++len;
			else
				l = false;
		}
		++x;
	}
	if (len >= k)
	{
		++num;
		return true;
	}

	l = true;
	r = true;
	x = 1;
	len = 1;

	while (l || r)
	{
		if (l)
		{
			if (j + x < v[i].size() && i - x >= 0 && v[i - x][j + x] == c)
				++len;
			else
				l = false;
		}
		if (r)
		{
			if (j - x >= 0 && i + x < v.size() && v[i + x][j - x] == c)
				++len;
			else
				r = false;
		}
		++x;
	}
	if (len >= k)
	{
		++num;
		return true;
	}
	return false;
}

void solve(int& first, int& second)
{
	int n, m, k;
	cin >> m >> n >> k;
	string X(k, 'x'), O(k, 'o');
	vector <string> v(n, string());
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 'x')
				if (do_for(v, k, 'x', first, i, j, X))
					return;
			if (v[i][j] == 'o')
				if (do_for(v, k, 'o', second, i, j, O))
					return;
		}
	}
}

int main ()
{
	int gamenum, first_won = 0, second_won = 0;
	cin >> gamenum;
	for (int i = 0; i < gamenum; ++i)
		solve(first_won, second_won);
	cout << first_won << ":" << second_won;
}