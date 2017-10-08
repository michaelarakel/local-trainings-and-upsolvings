#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
	string s;
	cin >> s;
	if (islower(s[0]))
	{
		for (int i = 1; i < s.size(); ++i)
			if (!isupper(s[i]))
			{
				cout << s;
				return 0;
			}
		s[0] = toupper(s[0]);
		if (s.size() != 1)
			transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
		cout << s;
	}
	else
	{
		for (int i = 1; i < s.size(); ++i)
		{
			if (!isupper(s[i]))
			{
				cout << s;
				return 0;
			}
		}
		s[0] = tolower(s[0]);
		if (s.size() != 1)
			transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
		cout << s;
	}
	return 0;
}