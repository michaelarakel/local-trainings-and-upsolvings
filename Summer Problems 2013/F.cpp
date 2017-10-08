#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		vector <char> used(49, false);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 6; ++j)
			{
				int num;
				cin >> num;
				used[num - 1] = true;
			}
		bool found = true;
		for (int i = 0; i < 49; ++i)
			if (!used[i])
				found = false;
		if (found)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
		cin >> n;
	}
}