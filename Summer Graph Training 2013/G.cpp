#include <iostream>
#include <vector>
#include <numeric>

const int INF = 1000 * 1000 * 1000;

using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	vector <char> used(n);
	vector <vector <int> > g(n, vector <int>(n, INF));
	for (int i = 0; i < m; ++i)
	{
		int node1, node2, len;
		cin >> node1 >> node2 >> len;
		g[node1 - 1][node2 - 1] = len;
		g[node2 - 1][node1 - 1] = len;
	}
	vector <int> min_edge(n, INF), min_end(n, -1);
	min_edge[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || min_edge[j] < min_edge[v]))
				v = j;
		used[v] = true;
		for (int j = 0; j < n; ++j)
		{
			if (g[v][j] < min_edge[j] && !used[j])
			{
				min_edge[j] = g[v][j];
				min_end[j] = v;
			}
		}
	}
	cout << accumulate(min_edge.begin(), min_edge.end(), 0);
}