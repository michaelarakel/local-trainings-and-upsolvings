#include <iostream>
#include <string>
using namespace std;
void distributing (string& s1, string& s2, string&s, int n)
{
	for (int i = 2; i < n; i += 2)
			s1 = s[i] + s1;
	for (int i = 3; i < n; i += 2)
			s2 = s[i] + s2;
}

void mixing (string& s)
{
	string s1, s2;
	s1 = s[0];
	s2 = s[1];
	int n = s.size(), i;
	distributing(s1, s2, s, n);
	if (n % 2 == 0)
		s = s1 + s2;
	else
		s = s2 + s1;
}

int main()
{
	int k;
	string cards;
	cin >> cards >> k;
	for (int i = 0; i < k; i++)
		mixing(cards);
	cout << cards;
	return 0;
}