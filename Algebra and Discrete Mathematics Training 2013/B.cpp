#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" },
		months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main ()
{
	int day;
	while (cin >> day)
	{
		string month, year;
		cin >> month >> year;
		int month_num = find(months, months + 12, month) - months + 1;
		int temp = year.size() - 1;
		int mod = ( (int) (year[temp] - '0') + (int) (year[temp - 1] - '0') * 10 + (int) (year[temp - 2] - '0') * 100 + (int) (year[temp - 3] - '0') * 1000) % 400 + 400;
		int a = (14 - month_num)/12, y = mod - a, m = month_num + 12 * a - 2;
		int week_num = (7000 + (day + y + y/4 - y/100 + y/400 + 31 * m / 12)) % 7;
		cout << week[week_num] << endl;
	}
}