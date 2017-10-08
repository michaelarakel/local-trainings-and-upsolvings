#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;

int rec(int n1, int n2, vector <vector <int> >& v)
{
	if (n1 < 0 || n2 < 0)
		return 0;
	if (v[n1][n2] != -1)
		return v[n1][n2];
	if (s1[n1] == s2[n2])
		v[n1][n2] = rec(n1 - 1, n2 - 1, v) + 1;
	else
		v[n1][n2] = max(rec(n1 - 1, n2, v), rec(n1, n2 - 1, v));
	return v[n1][n2];
}

int main()
{
	cin >> s1 >> s2;
	vector <vector <int> > v(s1.size(), vector <int>(s2.size(), -1));
	rec(s1.size() - 1, s2.size() - 1, v);
	cout << v[s1.size() - 1][s2.size() - 1] << endl;
	int i = s1.size() - 1, j = s2.size() - 1;
	vector <int> ans[2];
	while (i >= 0 && j >= 0)
	{
		if (s1[i] == s2[j])
		{
			ans[0].push_back(i);
			ans[1].push_back(j);
			--i;
			--j;
		}
		else
		{

		}
	}
}