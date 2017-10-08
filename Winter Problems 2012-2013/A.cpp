#include <iostream>
using namespace std;
int main ()
{
	int r, w, l;
	cin >> r >> w >> l;
	if (4*r*r >= (w*w + l*l))
		cout << "Pizza fits on the table";
	else
		cout << "Pizza does not fit on the table";
	return 0;
}