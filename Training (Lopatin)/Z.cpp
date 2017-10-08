#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int n;

void print(const vector <char>& s)
{
	for (int i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;
}

void rec(vector <char>& s, int depth)
{
	if (depth > n)
		return;
	if (depth < 0)
		return;
	if (s.size() > 2 * n)
		return;
	if (s.size() == 2 * n &&
		depth == 0)
	{
		print(s);
		return;
	}
	s.push_back('(');
	rec(s, depth + 1);
	s.pop_back();
	s.push_back(')');
	rec(s, depth - 1);
	s.pop_back();
}

int main()
{
	freopen("paren.in", "r", stdin);
	freopen("paren.out", "w", stdout);
	cin >> n;
	vector <char> s;
	rec(s, 0);
}