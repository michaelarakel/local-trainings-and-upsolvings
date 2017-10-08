#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs (const vector <vector <int> >& g, int start)
{
	vector <char> used(g.size(), false);
	queue <int> q;
	vector <int> ans;
	used[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (int i = 0; i < g[node].size(); ++i)
			if (!used[g[node][i]])
			{
				used[g[node][i]] = true;
				q.push(g[node][i]);
			}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] + 1 << ' ';
}

int main ()
{
	freopen ("wave.in", "r", stdin);
	freopen ("wave.out", "w", stdout);
	int n, m, v;
	cin >> n >> m >> v;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		g[start - 1].push_back(end - 1);
		g[end - 1].push_back(start - 1);
	}
	bfs(g, v - 1);
}