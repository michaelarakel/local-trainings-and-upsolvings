#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <vector <int> > factorials;

const int base = 1000 * 1000 * 1000;

vector <int> multiply (vector <int> a, int n)
{
	int mind = 0;
	for (int i = 0; i < a.size() || mind; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		long long curr = mind + a[i] * 1ll * n;
		a[i] = (int) (curr % base);
		mind = (int) (curr / base);
	}
	return a;
}

void print (const vector <int>& a)
{
	printf ("%d", a.empty()? 0 : a.back());
	for (int i = (int) a.size() - 2; i >= 0; --i)
		printf("%09d", a[i]);
}

void diff (vector <int>& a, const vector <int>& b)
{
	int mind = 0;
	for (int i = 0; i < b.size() || mind; ++i)
	{
		a[i] -= mind;
		if (i < b.size())
			a[i] -= b[i];
		mind = a[i] < 0;
		if (mind)
			a[i] += base;
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
}

bool is_more (const vector <int>& a, const vector <int>& b)
{
	if (a.size() != b.size())
		return a.size() > b.size();
	for (int i = a.size() - 1; i >= 0; --i)
	{
		if (a[i] < b[i])
			return false;
		if (a[i] > b[i])
			return true;
	}
	return true;
}

int main ()
{
	//freopen ("INPUT.TXT", "r", stdin);
	//freopen ("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	string temp;
	cin >> temp;
	vector <int> k;
	for (int i = temp.size(); i > 0; i -= 9)
	{
		if (i < 9)
			k.push_back(atoi(temp.substr(0, i).c_str()));
		else
			k.push_back(atoi(temp.substr(i - 9, 9).c_str()));
	}
	vector <int> a (1, 1);
	diff (k, a);
	factorials.push_back(a);
	a[0] = 0;
	for (int i = 1; i < n; ++i)
		factorials.push_back(multiply(factorials[i - 1], i));
	vector <int> set (n);
	for (int i = 0; i < n; ++i)
		set[i] = i + 1;
	for (int i = n - 1; i >= 0; --i)
	{
		int num = 0;
		while (is_more(k, factorials[i]))
		{
			++num;
			diff(k, factorials[i]);
		}
		cout << set[num];
		if (i != 0)
			cout << ' ';
		set.erase(set.begin() + num);
	}
}