#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

const long long base = 1000 * 1000 * 1000;
const long double EPS = 1e-15;

struct point {
	int x;
	int y;
};

struct segment {
	long double sqr_len()
	{
		return sqrt((a.x - b.x) * 1. * (a.x - b.x) + (a.y - b.y) * 1ll * (a.y - b.y));
	}
	point a;
	point b;
};

long double gcm(long double t1, long double t2)
{
	if (t2 <= EPS)
		return t1;

	long long n = (t1 / t2 + EPS);
	if (n == 0)
		return 0;

	return gcm(t2, t1 - n * t2);
}

int main()
{
	freopen("common.in", "r", stdin);
	freopen("common.out", "w", stdout);
	segment s[2];
	for (int i = 0; i < 2; ++i)
		cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;

	long double t1 = s[0].sqr_len(),
		t2 = s[1].sqr_len();

	if (t1 < t2)
		swap(t1, t2);

	long double measure = gcm(t1, t2);
	if (measure < 1e-6)
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		cout << fixed << setprecision(6) << measure << endl;
	}
}