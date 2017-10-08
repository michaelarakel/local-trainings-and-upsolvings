#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
	int space, dialed;
	cin >> space >> dialed;
	map <string, int> m;
	for (int i = dialed - 1; i >= 0; --i)
	{
		string s;
		cin >> s;
		m[s] = i;
	}
	map <int, string> mp;
	for (map <string, int>::iterator it = m.begin() ; it != m.end(); ++it)
		mp[it->second] = it->first;
	int i = 0;
	for (map <int, string>::iterator it = mp.begin(); it != mp.end() && i < space; ++it, ++i)
		cout << it->second << endl;
	while (i < space)
	{
		cout << "<Empty>" << endl;
		++i;
	}
}