#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void print (const vector <int>& v)
{
	if ( v[v.size() - 1] == 0 )
	{
		cout << 0;
		return;
	}
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
}

int main ()
{
	int n;
	cin >> n;
	vector <int> ans(n);
	bool noZero = true;
	for ( int i = 0; i < n; i++ )
	{
		cin >> ans[i];
		if ( ans[i] == 0 )
			noZero = false;
	}
	sort( ans.begin(), ans.end() );
	int sum = accumulate(ans.begin(), ans.end(), 0)%3;
	if ( noZero )
	{
		cout << "No solution";
		return 0;
	}
	if ( sum == 0 )
	{
		print(ans);
		return 0;
	}
	bool extraFound = false;
	for ( int i = 0; i < ans.size(); i++ )
		if ( ans[i] % 3 == sum )
		{
			ans.erase( ans.begin() + i );
			extraFound = true;
			break;
		}
	if ( extraFound )
	{
		print(ans);
		return 0;
	}
	int sum2 = ( sum % 2 ) ? 2 : 1;
	bool secondFound = false;
	if ( !extraFound )
		for ( int i = 0, k = 0; i < ans.size() && k != 2; i++ )
		{
			if ( ans[i] % 3 == sum2)
			{
				ans.erase( ans.begin() + i );
				i--;
				k++;
				if ( k == 2 )
					secondFound = true;
			}
		}
		if ( secondFound )
			{
				print(ans);
				return 0;
			}
			else
				cout << 0;
}