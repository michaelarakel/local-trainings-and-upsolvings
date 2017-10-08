#include <iostream>
#include <vector>

using namespace std;

const int a[55] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11};

int main ()
{
	int nt = 0;
	int n;
	cin >> n;
	for (int i = 0; i < 55; ++i)
		if (10 + a[i] == n)
			++nt;
	cout << nt;
}