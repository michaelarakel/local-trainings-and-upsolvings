#include <iostream>
#include <map>
#include <vector>

using namespace std;

void dfs (const vector <vector <int> >& g, vector <int>& used, int node)
{
	used[node] = 1;
	for (int i = 0; i < g[node].size(); ++i)
		if (!used[g[node][i]])
			dfs(g, used, g[node][i]);
}

int main ()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;// it's like i don't need them o.O
	}
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector <int> used(n, 0);
	int plain_num = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			dfs(g, used, i);
			int node_num = 0, segm_num = 0;
			for (int j = 0; j < n; ++j)
				if (used[j] == 1)
				{
					++used[j];
					++node_num;
					segm_num += g[j].size();
				}
			segm_num /= 2;
			plain_num += 2 + segm_num - node_num - 1;
		}
	}
	cout << plain_num + 1;
}