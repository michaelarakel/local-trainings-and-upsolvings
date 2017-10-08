#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs (int node, vector <vector <int> >& g, vector <char>& used)
{
	used[node] = true;
	for (int i = 0; i < g[node].size(); ++i)
		if (!used[g[node][i]])
			dfs(g[node][i], g, used);
}

int main ()
{
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	vector <char> used(n, false);
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		g[start - 1].push_back(end - 1);
		g[end - 1].push_back(start - 1);
	}
	if (m != n - 1)
	{
		cout << "NO";
		return 0;
	}
	dfs(0, g, used);
	if (find(used.begin(), used.end(), false) == used.end())
		cout << "YES";
	else
		cout << "NO";
}