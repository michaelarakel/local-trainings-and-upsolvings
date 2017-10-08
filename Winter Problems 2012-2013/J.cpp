#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector <string> v;

void rec (string& s, const int n, int num, int pos)
{
	if (n == num)
	{
		v.push_back(s);
		return;
	}
	for (int i = pos; i >= 0; --i)
	{
		if (s[i] == '0')
		{
			s[i] = '1';
			rec(s, n, num + 1, i);
			s[i] = '0';
		}
	}
}

int main ()
{
	string s;
	cin >> s;
	v.push_back(s);
	int zeroNum = count(s.begin(), s.end(), '0');
	for (int i = 1; i <= zeroNum; ++i)
		rec (s, i, 0, s.size() - 1);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}