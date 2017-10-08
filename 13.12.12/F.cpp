#include <iostream>
#include <string>
using namespace std;

string p;

void min (char& a, char& b)
{
	if (a == '?' && b == '?')
	{
		a = '0';
		b = '0';
	}
	else
	{
		if (a == '?')
			a = b;
		if (b == '?')
			b = a;
	}
}

bool check(string& s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] != s[s.size()-i-1])
			return false;
	return true;
}

int main ()
{
	cin >> p;
	int n = p.size();
	for (int i = 0; i < n; i++)
		min (p[i], p[n - i -1]);

	if (check(p))
		cout << p;
	else
		cout << "NO SOLUTION";
}
