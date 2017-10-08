#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

long long factorial( int n )
{
	long long ans = 1;
	for ( int i = 2; i <= n; i++ )
		ans*= i;
	return ans;
}

int main()
{
	unsigned long long borders[21] = { 0ll, 1ll, 3ll, 9ll, 33ll, 153ll, 873ll, 5913ll, 46233ll, 409113ll, 4037913ll, 43954713ll, 522956313ll, 6749977113ll, 93928268313ll, 1401602636313ll, 22324392524313ll, 378011820620313ll, 6780385526348313ll, 128425485935180313ll, 2561327494111820313ll};
	long long summ = 0;
	string line, entered;
	getline( cin, entered );
	summ += borders[entered.size() - 1] + 1;
	for ( int i = 0, k = 0; i < entered.size(); i++, k++ )
		line.push_back( 'a' + k );
	for ( int i = 0; i < entered.size(); i++ )
		for ( int j = 0; j < line.size(); j++ )
			if ( line[j] == entered[i] )
			{
				summ += j*factorial(entered.size()-i-1);
				line.erase( line.begin() + j );
				break;
			}
	cout << summ;
}
