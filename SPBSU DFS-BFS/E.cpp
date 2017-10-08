#include <iostream>
#include <vector>

using namespace std;

void dfs (int node, vector <vector <int> >& g, vector <char>& used, vector <int>& comp, const int comp_num)
{
	used[node] = true;
	comp[node] = comp_num;
	for (int i = 0; i < g[node].size(); ++i)
		if (!used[g[node][i]])
			dfs(g[node][i], g, used, comp, comp_num);
}

int main ()
{
	freopen ("connect.in", "r", stdin);
	freopen ("connect.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		g[start - 1].push_back(end - 1);
		g[end - 1].push_back(start - 1);
	}
	vector <char> used(n, false);
	vector <int> comp(n);
	int comp_num = 1;
	for (int i = 0; i < n; ++i)
		if (!used[i])
		{
			dfs(i, g, used, comp, comp_num);
			++comp_num;
		}
	cout << comp_num - 1 << endl;
	for (int i = 0; i < n; ++i)
		cout << comp[i] << ' ';
}