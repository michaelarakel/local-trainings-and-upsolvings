#include <iostream>
#include <vector>

using namespace std;

const int base = 1000 * 1000 * 1000;

void print (const vector <int>& a)
{
	printf("%d", a.empty()? 0 : a.back());
	for (int i = (int) a.size() - 2; i >= 0; --i)
		printf("%09d", a[i]);
}

vector <int> sum (vector <int>& a, vector <int>& b)
{
	int mind = 0;
	for (int i = 0; i < max(a.size(), b.size()) || mind; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		a[i] += mind;
		if (i < b.size())
			a[i] += b[i];
		mind = a[i] >= base;
		if (mind)
			a[i] -= base;
	}
	return a;
}

int main ()
{
	int n;
	cin >> n;
	vector <vector <int> > fidonacci;
	vector <int> temp (1, 0);
	fidonacci.push_back(temp);
	temp[0] = 1;
	while (fidonacci.size() < 3)
		fidonacci.push_back(temp);
	for (int i = 3; i <= n; ++i)
		fidonacci.push_back(sum(fidonacci[i - 3], fidonacci[i - 1]));
	print(fidonacci[n]);
}