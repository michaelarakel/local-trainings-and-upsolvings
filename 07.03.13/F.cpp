#include <iostream>

using namespace std;
const int v[] = {8, 16, 36, 82, 188, 428, 984, 2240, 5152, 11728, 26976, 61408, 141248, 321536, 739584, 1683584, 3872512, 8815360, 20276736, 46157824};

int main()
{
	int n;
	cin >> n;
	cout << v[n - 1];
}