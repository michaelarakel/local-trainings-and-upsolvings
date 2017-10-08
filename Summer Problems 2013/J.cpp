#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	string s;
	cin >> s;
	while (s != "#")
	{
		int num = count(s.begin(), s.end(), '1');
		char c = s[s.size() - 1];
		if (num % 2 == 0)
		{
			if (c == 'e')
				s[s.size() - 1] = '0';
			else
				s[s.size() - 1] = '1';
		}
		else
		{
			if (c == 'e')
				s[s.size() - 1] = '1';
			else
				s[s.size() - 1] = '0';
		}
		cout << s << endl;
		cin >> s;
	}
}