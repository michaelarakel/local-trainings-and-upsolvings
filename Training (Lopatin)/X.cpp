#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (n & 1)
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	else
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i] << endl;

}