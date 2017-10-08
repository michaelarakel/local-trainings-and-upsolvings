#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void bfs (const vector <vector <int> >& v, vector <char>& used)
{
	deque <int> d(1, 0);
	used[0] = true;
	while (!d.empty())
	{
		int node = d[0];
		d.pop_front();
		for (int i = 0; i < v[node].size(); i++)
			if (!used[v[node][i]])
			{
				d.push_back(v[node][i]);
				used[v[node][i]] = true;
			}
	}
}

int main ()
{
	int n;
	cin >> n;
	vector <vector <int> > g(n, vector <int>());
	int connection_count = 0;
	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			int exists;
			cin >> exists;
			if (exists)
			{
				g[i].push_back(j);
				++connection_count;
			}
		}
	}
	if (connection_count/2 == n - 1)
	{
		vector <char> used(n);
		bfs(g, used);
		for (int i = 0; i < n; i++)
			if (!used[i])
			{
				cout << "NO";
				return 0;
			}
		cout << "YES";
	}
	else
		cout << "NO";
}