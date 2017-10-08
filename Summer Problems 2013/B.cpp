/*#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-3;

int program_1(int n)
{
	return sqrt(1. * n) + EPS;
}

int program_2(int n)
{
	const int a[11] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121};
	int count = 0;
	while (a[count] <= n)
		++count;
	return count;
}

int program_3(int n)
{
	bool a[100] = {false};
	for (int i = 1; i <= n; ++i)
		for (int j = i - 1; j < n; j += i)
			a[j] = !a[j];
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (a[i])
			++count;
	return count;
}

int main ()
{
	for (int i = 2; i < 100; ++i)
	{
		int a = program_1(i),
			b = program_2(i),
			c = program_3(i);
		if (a != b ||
			a != c ||
			b != c)
			cout << "Error " << i << " " << a << " " << b << " " << c << endl;
	}
}*/

#include <iostream>
#include <cmath>

int main ()
{
	const double EPS = 1e-3;
	int casenum;
	std::cin >> casenum;
	for (int i = 0; i < casenum; ++i)
	{
		int n;
		std::cin >> n;
		n = sqrt(1. * n) + EPS;
		std::cout << n << std::endl;
	}
}