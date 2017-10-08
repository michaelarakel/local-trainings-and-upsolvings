#include <iostream>
#include <vector>

using namespace std;

struct RGB
{
	int R;
	int G;
	int B;
};

istream& operator >> (istream& input, RGB& color)
{
	input >> color.R >> color.G >> color.B;
	return input;
}

ostream& operator << (ostream& output, const RGB& color)
{
	output << '(' << color.R << ',' << color.G << ',' << color.B << ')';
	return output;
}

int dist (const RGB& one, const RGB& two)
{
	return (one.B - two.B) * (one.B - two.B) + (one.G - two.G) * (one.G - two.G) + (one.R - two.R) * (one.R - two.R);
}

int main ()
{
	RGB colors[16];
	for (int i = 0; i < 16; ++i)
		cin >> colors[i];
	RGB curr;
	cin >> curr;
	while (curr.R != -1)
	{
		RGB min_color = colors[0];
		int min_len = dist(curr, colors[0]);
		for (int i = 1; i < 16; ++i)
		{
			int curr_len = dist(curr, colors[i]);
			if (min_len > curr_len)
			{
				min_len = curr_len;
				min_color = colors[i];
			}
		}
		cout << curr << " maps to " << min_color << endl;
		cin >> curr;
	}
}