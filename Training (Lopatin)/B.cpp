#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <vector <int> > g;
vector <char> used;
vector <int> matching;

bool augment_path(int v)
{
	if (used[v])
		return false;

	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int node = g[v][i];
		if (matching[node] == -1 || augment_path(node))
		{
			matching[node] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("pairs.in", "r", stdin);
	//freopen("pairs.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		while (cin >> num)
		{
			if (num == 0)
				break;
			g[i].push_back(num - 1);
		}
	}

	used = vector <char>(n, false);
	matching = vector <int>(m, -1);
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		used.assign(n, false);
		augment_path(i);
	}

	for (int i = 0; i < m; ++i)
		if (matching[i] != -1)
			++count;

	cout << count << endl;

	for (int i = 0; i < matching.size(); ++i)
		if (matching[i] != -1)
			cout << matching[i] + 1 << ' ' << i + 1 << endl;
}