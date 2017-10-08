#include <iostream>
using namespace std;

int main()
{
	int n, v;
	cin>>n;
	if (100 - n + 99 <= 0)
		cout<<0;
	else
		cout<<100 - n + 99;
	return 0;
}