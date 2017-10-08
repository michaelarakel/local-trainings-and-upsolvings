#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	freopen("area.ln", "r", stdin);
	freopen("area.out", "w", stdout);
	int n;
	cin >> n;
	long long area = 0;
	vector <pair <int, int> > v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < n; ++i)
		area += v[i].first * 1ll * v[(i + 1) % n].second - v[i].second * 1ll * v[(i + 1) % n].first;
	int temp = area / 2;
	int zero_count = 600;
	cout << temp << '.';
	if (area & 1)
	{
		cout << 5;
		--zero_count;
	}
	for (int i = 0; i < zero_count; ++i)
		cout << 0;
}