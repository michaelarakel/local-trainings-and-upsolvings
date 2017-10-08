#include <iostream>

using namespace std;

void solve (const int n, const int T1, const int T2, const int T3)
{
	int ans = (n << 2) - 1; //n * 3 (the full revolutions) + n - 1 we can start near the T1 and make n - 1 ticks
	
	if (T2 > T1)
		ans += (T2 - T1);
	else
		ans += n - (T1 - T2);

	if (T3 > T2)
		ans += n - (T3 - T2);
	else
		ans += (T2 - T3);

	cout << ans << endl;
}

int main ()
{
	int n, T1, T2, T3;
	cin >> n >> T1 >> T2 >> T3;
	while (n != 0)
	{
		solve(n, T1, T2, T3);
		cin >> n >> T1 >> T2 >> T3;
	}
}