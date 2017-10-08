#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int rev (int n)
{
	if (n == 1)
		return 2;
	if (n == 2)
		return 1;
}
int main ()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		g[node1 - 1].push_back(node2 - 1);
		g[node2 - 1].push_back(node1 - 1);
	}
	vector <char> used(n);
	vector <int> color(n);
	color[0] = 1;
	used[0] = false;
	for (int j = 0; j < n; ++j)
	{
		if (!used[j])
		{
			used[j] = true;
			deque <int> d;
			d.push_back(j);
			color[j] = 1;
			while (!d.empty())
			{
				int node = d[0];
				int currColor = color[node];
				d.pop_front();
				for (int i = 0; i < g[node].size(); ++i)
				{
					int currNode = g[node][i];
					if (!used[currNode])
					{
						used[currNode] = true;
						color[currNode] = rev(currColor);
						d.push_back(currNode);
					}
					else
					{
						if (currColor == color[currNode])
						{
							cout << "no";
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "yes";
}