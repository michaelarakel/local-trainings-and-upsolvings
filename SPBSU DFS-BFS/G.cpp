#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
	freopen ("horse.in", "r", stdin);
	freopen ("horse.out", "w", stdout);
	int n, m, p, l;
	pair <int, int> start, end;
	cin >> m >> n >> p >> l >> start.second >> start.first >> end.second >> end.first;
	--start.first; --start.second; --end.first; --end.second;
	const int a[] = {p, p, -p, -p, l, l, -l, -l},
			b[] =   {l, -l, l, -l, p, -p, p, -p};
	queue <pair <int, int> > q;
	q.push(start);
	vector <vector <char> > used(n, vector <char>(m, false));
	used[start.first][start.second] = true;
	vector <vector <pair <int, int> > > pre(n, vector <pair <int, int> >(m, make_pair(-1, -1)));
	while (!q.empty())
	{
		pair <int, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int x = curr.first + a[i],
				y = curr.second + b[i];
			if (x >= 0 && x < n &&
				y >= 0 && y < m)
				if (!used[x][y])
				{
					used[x][y] = true;
					pre[x][y] = curr;
					if (make_pair(x, y) == end)
						goto here;
					else
						q.push(make_pair(x, y));
				}
		}
	}
here:
	if (!used[end.first][end.second])
	{
		cout << -1;
		return 0;
	}
	vector <pair <int, int> > path;
	for (pair <int, int> v = end; v != make_pair(-1, -1); v = pre[v.first][v.second])
		path.push_back(v);
	cout << path.size() - 1 << endl;
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i].second + 1 << ' ' << path[i].first + 1 << ' ';
}