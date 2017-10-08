#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int base = 1000 * 1000 * 1000;

vector <int> sum(const vector <int>& c, const vector <int>& b)
{
	vector <int> a(c);
	int carry = 0;
	for (int i = 0; i < max(a.size(), b.size()) || carry; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		int curr = a[i] + carry;
		if (i < b.size())
			curr += b[i];
		carry = curr >= base;
		if (carry)
			curr -= base;
		a[i] = curr;
	}
	return a;
}

void print(const vector <int>& a)
{
	cout << a.back();
	for (int i = (int)a.size() - 2; i >= 0; --i)
		printf("%09d", a[i]);
}

int main()
{
	freopen("fido.in", "r", stdin);
	freopen("fido.out", "w", stdout);

	vector <int> z(1), o(1, 1);
	vector <vector <int> > fid;
	fid.push_back(z);
	fid.push_back(o);
	fid.push_back(o);
	int n;
	cin >> n;

	for (int i = 3; i <= n; ++i)
		fid.push_back(sum(fid[i - 1], fid[i - 3]));
	print(fid[n]);
}