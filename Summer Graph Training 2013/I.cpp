#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		 cin >> v[i];
	int q, w;
	cin >> q >> w;
	int x = v[q - 1], y = v[w - 1];
	replace(v.begin(), v.end(), x, y);
	for (int i = 0; i < n; ++i)
		cout << v[i] << ' ';
}