#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	long long l;
	cin >> n >> l;
	--l;
	vector <int> fib;
	fib.push_back(1);
	fib.push_back(2);
	for (int i = 2; i <= n; ++i)
		fib.push_back(fib[i - 1] + fib[i - 2]);
	for (int i = 1; i <= n; ++i)
	{
		if (l >= fib[n - i])
		{
			l -= fib[n - i];
			cout << 1;
		}
		else
			cout << 0;
	}
}