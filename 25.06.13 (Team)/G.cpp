#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs (const vector <vector <int> >& g, vector <char>& used, int node)
{
	used[node] = true;
	for (int i = 0; i < g[node].size(); ++i)
		if (!used[g[node][i]])
		{
			used[g[node][i]] = true;
			dfs(g, used, g[node][i]);
		}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > v(n);
	vector <pair <int, int> > kox;
	for (int i = 0; i < m; i++)
	{
		int pl1, pl2;
		cin >> pl1 >> pl2;
		kox.push_back(make_pair(pl1 - 1, pl2 - 1));
		v[pl1 - 1].push_back(pl2 - 1);
		v[pl2 - 1].push_back(pl1 - 1);
	}
	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		int x = kox[i].first, y = kox[i].second;
		v[x].erase(find(v[x].begin(), v[x].end(), y));
		v[y].erase(find(v[y].begin(), v[y].end(), x));
		vector <char> used(n);
		dfs(v, used, 0);
		for (int i = 0; i < n; ++i)
			if (!used[i])
			{
				++count;
				break;
			}
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << count;
}
