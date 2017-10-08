#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	long long n;
	cin >> n;
	int count = 0;
	for (int i = 1; 1ll * i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			++count;
		}
	}
	count *= 2;
	if ( sqrt(1.0*n) == (int)sqrt(1.0*n) )
		--count;
	cout << count;
}