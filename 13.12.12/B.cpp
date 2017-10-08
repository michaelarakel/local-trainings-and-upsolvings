#include <iostream>
#include <string>
using namespace std;

void check(string& s, string& t)
{
	int j = 0, k = 0, count = 0;
	for (int i = k; i < t.size() && j < s.size(); i++)
	{
		if (s[j] == t[i])
		{
			k = i;
			j++;
			count++;
		}
	}
	if (count == s.size())
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	string s, t;
	cin >> s >> t;
	check(s, t);
	return 0;
}