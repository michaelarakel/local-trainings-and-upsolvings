#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char hello[5] = {'h', 'e', 'l', 'l', 'o'};
	string line;
	getline( cin , line );
	for ( int i = 0, k = 0; i < line.size(); i++ )
	{
		if ( line[i] == hello[k] )
			k++;
		if ( k == 5 )
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
