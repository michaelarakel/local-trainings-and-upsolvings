#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	string s;
	cin >> s;
	vector <int> v(26);
	for (int i = 0; i < s.size(); i++)
		v[s[i] - 'a']++;
	int oddCount = 0, count = 0;
	char odd;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]%2 == 1)
		{
			odd = (i + 'a');
			oddCount++;
		}
		if (v[i] != 0)
			count++;
	}
	if (oddCount > 1 || (oddCount == 1 && s.size()%2 == 0))
	{
		cout << "Angry Carlsen!";
		return 0;
	}
	if (oddCount == 1)
		v[odd - 'a']--;
	s = "";
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i]/2; j++)
		{
			char temp = i + 'a';
			s.push_back(temp);
		}
	}
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	if (oddCount == 1)
		cout << odd;
	for (int i = s.size() - 1; i >= 0; --i)
		cout << s[i];
}