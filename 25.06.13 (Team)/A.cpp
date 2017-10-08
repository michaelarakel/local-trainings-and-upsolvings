#include <iostream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	long long a = 0, b = 0;
	for (int i = 0; i < n; ++i)
	{
		long long temp;
		cin >> temp;
		a += temp;
	}
	for (int i = 0; i < n - 1; ++i) 
	{
		long long temp;
		cin >> temp;
		b += temp;
	}
	cout << a - b;
}