#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>

using namespace std;

void print(deque <int>& v)
{
	for (deque<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	cout << endl;
}

vector <deque <int> > rec(int n)
{
	if (n == 1)
	{
		deque <int> l;
		l.push_back(1);
		return vector <deque <int> >(1, l);
	}
	vector <deque <int> > v = rec(n - 1);
	vector <deque <int> > ans;

	for (int j = 0; j < v.size(); ++j)
	{
		if (j & 1)
		{
			for (int i = 0; i <= v[j].size(); ++i)
			{
				v[j].insert(v[j].begin() + i, n);
				ans.push_back(v[j]);
				v[j].erase(v[j].begin() + i);
			}
		}
		else
		{
			for (int i = v[j].size(); i >= 0; --i)
			{
				v[j].insert(v[j].begin() + i, n);
				ans.push_back(v[j]);
				v[j].erase(v[j].begin() + i);
			}
		}
	}
	return ans;
}


int main()
{
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	int n;
	cin >> n;
	vector <deque <int> > ans = rec(n);

	for (int i = 0; i < ans.size(); ++i)
		print(ans[i]);
}