#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	vector <long long> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (n % 2 == 0)
		for (int i = v.size() - 1; i >= 0; --i)
			cout << v[i] << endl;
	else
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << endl;
}