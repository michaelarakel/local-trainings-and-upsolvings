#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("invers.in", "r", stdin);
	//freopen("invers.out", "w", stdout);
	vector <int> v_table;
	int n;
	while (cin >> n)
		v_table.push_back(n);
	vector <int> v(v_table.size(), -1);
	for (int i = 0; i < v_table.size(); ++i)
	{
		int count = 0;
		int j = 0;
		while (count < v_table[i])
		{
			if (v[j] == -1)
				++count;
			++j;
		}
		while (v[j] != -1)
			++j;
		v[j] = i + 1;
	}
	vector <int> reverse(v.size());
	for (int i = 0; i < v.size(); ++i)
		reverse[v[i] - 1] = i + 1;
	vector <int> reverse_table(reverse.size(), 0);
	for (int i = 1; i < reverse.size(); ++i)
	for (int j = 0; j < i; ++j)
	if (reverse[j] > reverse[i])
		++reverse_table[reverse[i] - 1];
	for (int i = 0; i < reverse_table.size(); ++i)
	{
		cout << reverse_table[i];
		if (i != reverse_table.size() - 1)
			cout << ' ';
	}
}