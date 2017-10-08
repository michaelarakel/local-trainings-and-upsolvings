#include <iostream>
#include <vector>

using namespace std;

const int base = 1000 * 1000 * 1000;

vector <int> primes;

vector <int> get_factorisation (int n)
{
	vector <int> fact(primes.size(), 0);
	for (int i = 0; i < primes.size() && n != 1; ++i)
		while (n % primes[i] == 0)
		{
			n /= primes[i];
			++fact[i];
		}
	return fact;
}

void LCM (vector <int>& a, const vector <int>& b)
{
	for (int i = 0; i < a.size(); ++i)
		a[i] = max(a[i], b[i]);
}

void print (const vector <int>& a)
{
	printf ("%d", a.empty()? 0 : a.back());
	for (int i = (int) a.size() - 2; i >= 0; --i)
		printf ("%09d", a[i]);
}

void multiply (vector <int>& a, int n)
{
	int mind = 0;
	for (int i = 0; i < a.size() || mind; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		long long curr = mind + a[i] * 1ll * n;
		a[i] = (int) (curr % base);
		mind = (int) (curr/base);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
}

void normalize (vector <int>& lcm, vector <int>& a)
{
	for (int i = 0; i < lcm.size(); ++i)
		while (lcm[i] != 0)
		{
			multiply(a, primes[i]);
			--lcm[i];
		}
}

int main ()
{
	primes.push_back(2);
	vector <char> sieve(1001, true);
	sieve[0] = sieve[1] = false;
	for (int i = 3; i < 1001; i += 2)
	{
		if (sieve[i])
		{
			primes.push_back(i);
			if (i * 1ll * i <= 1000)
				for (int j = i * i; j <= 1000; j += i)
					sieve[j] = false;
		}
	}
	vector <int> lcm (primes.size(), 0);
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	vector <int> ans (1, 1);
	for (int i = 2; i <= n; ++i)
	{
		vector <int> temp = get_factorisation(i);
		LCM(lcm, temp);
	}
	normalize(lcm, ans);
	print(ans);
}