#include <iostream>
#include <string>
using namespace std;

int n;

int pseudodigsum(int a[])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

/*void sum (vector <int>& v1, vector <int>& v2)
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
}*/

int main ()
{
	int digitnum, digitsum;
	cin >> digitsum >> digitnum;
	if (digitnum*9 < digitsum || (digitnum!=1 && digitsum == 0))
	{
		cout << "-1";
		return 0;
	}
	n = digitnum;
	int start[10000] = {0}, end[10000] = {9};
	if (digitnum != 1)
	{
		end[0] = 1;
		for (int i = 1; i < n; i++)
			end[i] = 9;
		for (int i = 0; i < n-1; i++)
		{
			if (i != 0)
				end[i] = 0;
			if (pseudodigsum(end) < digitsum)
				while (pseudodigsum(end) < digitsum)
					end[i]++;
		}
	}
	while (pseudodigsum(end) != digitsum)
		end[n-1]--;
	for (int i = 0; i < n; i++)
		cout << end[i];
}