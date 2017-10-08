#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sum (vector <int>& v1, vector <int>& v2)
{
	vector <int> sum;
	bool inmind = false;
	for (int i = 0; i < v1.size(); i++)
	{
		int temp = v1[i] + v2[i];
		if (temp == 9)
		{
			if (inmind)
				sum.push_back(1);
			else
				sum.push_back(9);
		}
		else if (temp <= 8)
		{
			if (inmind)
			{
				++temp;
				inmind = false;
			}
			sum.push_back(temp);
		}
		else
		{
			if (inmind)
				temp++;
			sum.push_back(temp - 10);
			inmind = true;
		}
	}
	if (inmind)
		sum.push_back(1);
	v1 = sum;
}

int main ()
{
	int n;
	cin >> n;
	vector <int> v(1, 2);
	for (int i = 0; i < n; i++)
		sum(v, v);
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}