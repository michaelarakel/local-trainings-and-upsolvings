#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	while (n != 0)
	{
		map <string, int> name_to_num;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			name_to_num[s] = i;
		}
		vector <set <int> > g(n);
		for (int i = 0; i < n; ++i)
			g[i].insert(i);
		for (int i = 0; i < m; ++i)
		{
			string first, second;
			cin >> first >> second;
			int a = name_to_num[first], b = name_to_num[second];
			for (set<int>::iterator it = g[b].begin(); it != g[b].end(); ++it)
				g[a].insert(*(it));
			for (set<int>::iterator it = g[a].begin(); it != g[a].end(); ++it)
				g[b].insert(*(it));
		}
		bool found = true;
		for (int i = 0; i < n; ++i)
			if (g[i].size() != n)
			{
				found = false;
				break;
			}
		if (found)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
		cin >> n >> m;
	}
}