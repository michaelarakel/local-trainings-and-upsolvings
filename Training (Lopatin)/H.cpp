#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int main()
{
	freopen("horse.in", "r", stdin);
	freopen("horse.out", "w", stdout);
	int n, m, p, q, x1, y1, x2, y2;
	cin >> n >> m >> p >> q >> x1 >> y1 >> x2 >> y2;
	--x2; --y2;
	--x1; --y1;
	int a[] = {p, p, -p, -p, q, q, -q, -q},
		b[] = {-q, q, -q, q, p, -p, p, -p};
	queue <pair <int, int> > bfs;
	bfs.push(make_pair(x1, y1));

	vector <vector <char> > used(n, vector <char>(m, false));
	vector < vector <pair <int, int> > > pre(n, vector <pair <int, int> >(m, make_pair(-1, -1)));
	used[x1][y1] = true;
	pre[x1][y1] = make_pair(x1, y1);
	bool found = false;

	while (!bfs.empty())
	{
		if (used[x2][y2])
			break;
		pair <int, int> curr = bfs.front();
		bfs.pop();

		for (int i = 0; i < 8; ++i)
		{
			int x = curr.first + a[i],
				y = curr.second + b[i];

			if ((x >= 0 && x < n) &&
				(y >= 0 && y < m))
			{
				if (!used[x][y])
				{
					used[x][y] = true;
					pre[x][y] = curr;
					bfs.push(make_pair(x, y));
				}
			}

		}
	}
	if (!used[x2][y2])
	{
		cout << -1 << endl;
		return 0;
	}

	vector <pair <int, int > > path;
	for (pair <int, int> v = make_pair(x2, y2);	; v = pre[v.first][v.second])
	{
		path.push_back(v);
		if (v == pre[v.first][v.second])
			break;
	}

	cout << (path.size() - 1) << endl;

	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i].first + 1 << ' ' << path[i].second + 1 << endl;
} 