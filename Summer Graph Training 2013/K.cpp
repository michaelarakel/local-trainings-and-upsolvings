#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main ()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n, vector <int>(n, INF));
	for (int i = 0; i < m; ++i)
	{
		int first, second;
		cin >> first >> second;
		g[first - 1][second - 1] = 1;
		g[second - 1][first - 1] = 1;
	}
	vector <int> min_edge(n, INF), min_end(n, -1);
	vector <char> used(n);
	min_edge[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || min_edge[j] < min_edge[v]))
				v = j;
		used[v] = true;
		if (min_end[v] != -1)
			cout << v + 1 << ' ' << min_end[v] + 1 << endl;
		for (int j = 0; j < n; ++j)
		{
			if (g[v][j] < min_edge[j] && !used[j])
			{
				min_edge[j] = g[v][j];
				min_end[j] = v;
			}
		}
	}
}