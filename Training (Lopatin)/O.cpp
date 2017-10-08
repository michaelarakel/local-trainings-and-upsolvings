#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 1000;
const int base = 1000 * 1000 * 1000;
int lp[maxn + 1];
vector <int> pr;

void init()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * 1ll * pr[j] <= maxn; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

void mul(vector <ll>& a, int b)
{
	int carry = 0;
	for (int i = 0; i < a.size() || carry; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		ll curr = a[i] * 1ll * b + carry;
		carry = int (curr / base);
		a[i] = (curr % base);
	}
	while (a.back() == 0 && a.size() > 1)
		a.pop_back();
}

void print(const vector <ll>& a)
{
	cout << a.back();
	for (int i = (int)a.size() - 2; i >= 0; --i)
		printf("%09lld", a[i]);
}

int get_max_pow(int a, int b)
{
	int res = 1;
	while (res * a <= b)
		res *= a;
	return (res);
}

int main()
{
	freopen("lcm.in", "r", stdin);
	freopen("1cm.out", "w", stdout);
	init();
	int n;
	cin >> n;
	vector <ll> res(1, 1);
	for (int i = 0; i < pr.size() && pr[i] <= n; ++i)
	{
		int temp = get_max_pow(pr[i], n);
		mul(res, temp);
	}
	print(res);
}