#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
	freopen ("dfsongrid.in", "r", stdin);
	freopen ("dfsongrid.out", "w", stdout);
	int n, m;
	pair <int, int> start, end;
	cin >> m >> n >> start.second >> start.first >> end.second >> end.first;
	--start.first; --start.second; --end.first; --end.second;
	vector <vector <char> >g(n, vector <char>(m));
	const int a[] = {-1, 1, 0, 0},
			b[] =   {0, 0, -1, 1};
	queue <pair <int, int> > q;
	q.push(start);
	vector <vector <char> > used(n, vector <char>(m, false));
	used[start.first][start.second] = true;
	vector <vector <pair <int, int> > > pre(n, vector <pair <int, int> >(m, make_pair(-1, -1)));
	while (!q.empty())
	{
		pair <int, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = curr.first + a[i],
				y = curr.second + b[i];
			if (x >= 0 && x < n &&
				y >= 0 && y < m)
				if (!used[x][y] && g[x][y] == '.')
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
		cout << "NO";
		return 0;
	}
	vector <pair <int, int> > path;
	for (pair <int, int> v = end; v != make_pair(-1, -1); v = pre[v.first][v.second])
		path.push_back(v);
	cout << "YES" << endl;
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i].second + 1 << ' ' << path[i].first + 1 << ' ';
}