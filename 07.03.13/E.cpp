#include <iostream>
#include <string>

using namespace std;

string rev (const string& order)
{
	if (order == "white")
		return "black";
	return "white";
}

int main ()
{
	string w, b, order;
	cin >> w >> b >> order;
	if (order == "w")
		order = "white";
	else
		order = "black";
	int wx = w[1] - '0', bx = b[1] - '0', wy = w[0] - 'a', by = b[0] - 'a';
	if (wy == by)
	{
		if (wx < bx)
			cout << "draw";
		else
		{
			if (8 - wx == bx - 1)
				cout << order;
			else if (8 - wx < bx - 1)
				cout << "white";
			else
				cout << "black";
		}
	}
	else if (wy != by + 1 &&
		wy != by - 1)
	{
		if (wx == 2)
			++wx;
		if (bx == 7)
			--bx;
		if (8 - wx == bx - 1)
			cout << order;
		else if (8 - wx < bx - 1)
				cout << "white";
		else
				cout << "black";
	}
	else
	{
		if (wx != 2 && bx != 7)
		{
			if (wx < bx)
			{
				int temp = bx - wx;
				if (temp%2 == 1)
					cout << order;
				else
					cout << rev(order);
			}
			if (wx >= bx)
			{
				if (8 - wx == bx - 1)
					cout << order;
				else if (8 - wx < bx - 1)
						cout << "white";
				else
						cout << "black";
			}
		}
		if (wx == 2 && bx == 7)
			cout << rev(order);
		if (wx == 2 && bx != 7)
		{
			if (bx == 2)
				cout << "black";
			else if (bx == 5 && order[0] == 'b')
				cout << "black";
			else if (bx == 4 && order[0] == 'w')
				cout << "black";
			else if (bx == 3 && order[0] == 'b')
				cout << "black";
			else
				cout << "white";
		}
		if (wx != 2 && bx == 7)
		{
			if (wx == 7)
				cout << "white";
			else if (wx == 6 && order[0] == 'w')
				cout << "white";
			else if (wx == 5 && order[0] == 'b')
				cout << "white";
			else if (wx == 4 && order[0] == 'w')
				cout << "white";
			else
				cout << "black";
		}
	}
}