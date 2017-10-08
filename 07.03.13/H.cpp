#include <iostream>

using namespace std;

char color (int i, int j)
{
	char c;
	if (i%2 == j%2)
		c = 'w';
	else
		c = 'b';
	return c;
}

int main ()
{
	int m = 0, n = 0;
	char temp, w[2], b[2];
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
		{
			cin >> temp;
			if (temp == 'w')
			{
				w[m] = color(i, j);
				m++;
			}
			if (temp == 'b')
			{
				b[n] = color(i, j);
				n++;
			}
		}
	if (((w[0] == w[1]) && b[0] == b[1]) ||
		((w[0] != w[1]) && (b[0] != b[1])))
		cout << "white";
	else
		cout << "black";
}