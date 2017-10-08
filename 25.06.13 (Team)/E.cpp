#include <iostream>
#include <cmath>

using namespace std;

struct line
{
	long long a;
	long long b;
	long long c;
};

line makeline (int x1, int y1, int x2, int y2)
{
	line ans;
	ans.a = y2 - y1;
	ans.b = x1 - x2;
	ans.c = 1ll * y1 * x2  - 1ll * x1 * y2;
	return ans;
}

double length (int x1, int y1, int x2, int y2)
{
	return sqrt( 1. * ( 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1) ) );
}

int main ()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	line a = makeline(x1, y1, x2, y2);
	if (1ll * a.a * x3 + 1ll * a.b * y3 + a.c == 0)
	{
		if ( (min (x1, x2) <= x3 && x3 <= max(x1, x2) &&
			min(y1, y2) <= y3 && y3 <= max(y1, y2)))
		{
			cout << 0;
			return 0;
		}
			long double a = length(x1, y1, x3, y3),
						b = length(x2, y2, x3, y3);
			cout << min(a, b);
		return 0;
	}
	long double len = (a.a * x3 + a.b * y3 + a.c)/(sqrt(1. * (a.a * a.a + a.b * a.b)));
	long double alpha = ((x3 - x1) * (x2 - x1) + (y2 - y1) * (y3 - y1))/ (sqrt( 1. * (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)) * sqrt( 1. * (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))),
		beta = ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2))/ (sqrt( 1. * (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)) * sqrt( 1. * (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
	if (alpha < 0 || beta < 0)
	{
		long double a = length(x1, y1, x3, y3),
				    b = length(x2, y2, x3, y3);
		cout << min(a, b);
	}
	else
		cout << fabs(len);
}