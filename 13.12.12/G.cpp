#include <iostream>
using namespace std;

int n, a[100], b[100];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

void type(int a[])
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int minofSubstr(int c[], int d[])
{
	int diff[1000];
	for (int i = 0; i < n; i++)
		diff[i] = c[i] - d[i];
	int mindiff = min(diff[0], diff[1]);
	for (int i = 0; i < n; i++)
		if (mindiff > diff[i])
			mindiff = diff[i];
	return mindiff;
}


int main ()
{
	cin >> n;
	if (n == 0)
	{
		cout << '0';
		return 0;
	}
	type (a);
	type (b);
	int sum = 0;
	bool takefrom1 = false, takefrom2 = false;
	for (int i = 0; i < n; i++)
	{
		sum += max(a[i], b[i]);
		if (a[i] == max(a[i], b[i]))
			takefrom1 = true;
		if (b[i] == max(a[i], b[i]))
			takefrom2 = true;
	}
	if (!takefrom1)
		sum -= minofSubstr(b, a);
	if (!takefrom2)
		sum -= minofSubstr(a, b);
	cout << sum;
}
