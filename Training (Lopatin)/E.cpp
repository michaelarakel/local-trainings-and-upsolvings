#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void print(const vector <int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)
		cout << v[i] << '+';
	cout << v[v.size() - 1] << endl;
}

void rec(const int n, vector <int>& v, int sum, int pos)
{
	if (sum > n)
		return;
	if (sum == n)
	{
		print(v);
		return;
	}

	for (int i = pos; i > 0; --i)
	{
		v.push_back(i);
		rec(n, v, sum + i, i);
		v.pop_back();
	}
}

int main()
{
	freopen("part.in", "r", stdin);
	freopen("part.out", "w", stdout);
	int n;
	cin >> n;
	vector <int> v;
	rec(n, v, 0, n);
}