#include <iostream>

using namespace std;

int joseph (int n, int k)
{
	return n>1 ? (joseph (n-1, k) + k - 1) % n + 1 : 1;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << joseph(n, k);
}