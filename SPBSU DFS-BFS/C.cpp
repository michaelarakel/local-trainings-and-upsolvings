#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000 * 1000 * 1000;

void bfs (const vector <vector <int> >& g)
{
	vector <char> used(g.size(), false);
	vector <int> d(g.size(), INF);
	vector <int> pre(g.size(), -1);
	d[0] = 0;
	used[0] = true;
	queue <int> q;
	q.push(0);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < g[node].size(); ++i)
			if (!used[g[node][i]])
			{
				q.push(g[node][i]);
				used[g[node][i]] = true;
				d[g[node][i]] = d[node] + 1;
				pre[g[node][i]] = node;
			}
	}
	int maximum = 0;
	for (int i = 0; i < d.size(); ++i)
		if (d[i] != INF && maximum < d[i])
			maximum = d[i];
	cout << maximum << endl;
	vector <int> ans;
	for (int i = 0; i < d.size(); ++i)
		if (d[i] == maximum)
			ans.push_back(i + 1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
}

int main ()
{
	freopen ("rootdist.in", "r", stdin);
	freopen ("rootdist.out", "w", stdout);
	int n;
	cin >> n;
	vector <vector <int> > g(n);
	for (int i = 1; i <= n - 1; ++i)
	{
		int node;
		cin >> node;
		g[i].push_back(node - 1);
		g[node - 1].push_back(i);
	}
	bfs(g);
}