#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	vector <int> v(n);
	for (int i = 0; i < n; i++)
		cin>>v[i];
	sort (v.begin(), v.end());
	int start = 1;
	int end = v[n - 1];
	while (start <= end)
	{
		int s = 0;
		int m = (start+end)/2;
		for (int i = 0; i < v.size(); i++)
			s += v[i]/m;
		if (s >= k)
			start = m + 1;
		else
			end = m - 1;
	}
	cout << end;
	return 0;
}
