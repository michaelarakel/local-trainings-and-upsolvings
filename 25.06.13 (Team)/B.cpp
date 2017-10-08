#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <vector <char> > v (n, vector <char> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	if (v[0][0] == '1')
	{
		cout << 0;
		return 0;
	}
	int count = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int k = 0; k < i; k++)
		{
				if (v[count][k] == '1' || v[k][count] == '1')
				{
					cout << count;
					return 0;
				}
		}
		count ++;
	}
	cout << count;
}