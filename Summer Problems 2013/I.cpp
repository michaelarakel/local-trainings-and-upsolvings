#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector <long long> v(1, 0);
	for (long long i = 1; i <= 1000; ++i)
		v.push_back(i * (i + 1)/2 + v[i - 1]);
	int n;
	cin >> n;
	for (int itnum = 1; itnum <= n; ++itnum)
	{
		int num;
		cin >> num;
		cout << itnum << ": " << num << " " << v[num] << endl;
	}
}