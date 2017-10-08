#include <iostream>
using namespace std;
bool isprime(int num)
{
	for (int i = 2; i*i <= num; i++)
		if (num % i == 0)
			return false;
	return true;
}
int primenum(int num)
{
	int primecount = 0;
	for (int i = 2; ; i++)
	{
		if (isprime(i))
		{
			primecount++;
			if (primecount == num)
				return i;
		}
	}
}
int main()
{
	int k;
	cin >> k;
	cout << primenum(primenum(k));
	return 0;
}