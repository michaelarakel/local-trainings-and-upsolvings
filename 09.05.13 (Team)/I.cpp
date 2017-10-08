#include <iostream>
#include <string>
using namespace std;

int main()
{
	string d;
	int n;
	cin >> n >> d;
	if (d.size() == n)
	{
		cout<<d;
		return 0;
	}
	if (n < d.size())
	{
		cout<<"No solution";
		return 0;
	}
	if (n > d.size())
	{
		int s = d.size();
		for (int i = 0; i < n - s; i++)
			d.push_back('0');
	}
	cout << d;
	return 0;
}