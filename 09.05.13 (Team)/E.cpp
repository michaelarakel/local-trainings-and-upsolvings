#include <iostream>

using namespace std;

struct line
{
	long long a;
	long long b;
	long long c;
};

struct vertex
{
	int x;
	int y;
};

line makeLine(const vertex& a, const vertex& b)
{
	line ans;
	ans.a = a.y - b.y;
	ans.b = b.x - a.x;
	ans.c = -1 * (ans.a * a.x + ans.b * a.y);
	return ans;
}

long long put(line c, vertex a)
{
	return c.a * a.x + c.b * a.y + c.c;
}

bool check (vertex x1, vertex x2, vertex x3, vertex x4)
{
    return ((x3.x <= x1.x && x1.x <= x4.x) || (x3.x <= x2.x && x2.x <= x4.x) || (x4.x <= x1.x && x1.x <= x3.x) || (x4.x <= x2.x && x2.x <= x3.x)) &&
           ((x3.y <= x1.y && x1.y <= x4.y) || (x3.y <= x2.y && x2.y <= x4.y) || (x4.y <= x1.y && x1.y <= x3.y) || (x4.y <= x2.y && x2.y <= x3.y));
}

int main ()
{
	//freopen ("INPUT.TXT", "r", stdin);
	//freopen ("OUTPUT.TXT", "w", stdout);
	vertex a1, a2, b1, b2;
	cin >> a1.x >> a1.y >> a2.x >> a2.y >> b1.x >> b1.y >> b2.x >> b2.y;
	line first, second;
	first = makeLine(a1, a2);
	second = makeLine(b1, b2);
	long long orient2 = put(first, b1) * put(first, b2),
		orient1 = put(second, a1) * put(second, a2);
	if (orient1 == 0 && orient2 == 0)
	{
		if (check(a1, a2, b1, b2) ||
			check(b1, b2, a1, a2))
			cout << "Yes";
		else
			cout << "No";
	}
	else
	{
		if (orient1 <= 0 && orient2 <= 0)
			cout << "Yes";
		else
			cout << "No";
	}
}