#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int row[1234], col[5678];
	for (int i = 0; i < 1234; ++i)
		row[i] = i;
	for (int i = 0; i < 5678; ++i)
		col[i] = i;
	char c;
	while (cin >> c)
	{
		int x, y, z;
		if (c != 'W')
			cin >> x >> y;
		else
			cin >> z;
		if (c == 'C')
			swap(col[x - 1], col[y - 1]);
		if (c == 'R')
			swap(row[x - 1], row[y - 1]);
		if (c == 'Q')
			cout << row[x - 1] * 5678 + col[y - 1] + 1 << endl;
		if (c == 'W')
		{
			--z;
			x = z / 5678;
			y = z - x * 5678;
			cout << find(row, row + 1234, x) - row + 1 << ' ' << find (col, col + 5678, y) - col + 1 << endl;
		}
	}
}