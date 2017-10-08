#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum % 2 == 0 && 
		(sum/2 == a ||
		 sum/2 == b ||
		 sum/2 == c) )
		 cout << "YES";
	else
		cout << "NO";
	return 0;
}