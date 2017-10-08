#include <iostream>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

void add (deque <int>& d1, deque <int>& d2, int num)
{	
	d2.push_back(num);
	if (d1.size() + 2 == d2.size())
	{
		d1.push_back(d2[0]);
		d2.pop_front();
	}
}

void take (deque <int>& d1, deque <int>& d2)
{
	if (d1.empty() && d2.empty())
		return;
	d2.pop_back();
	if (d1.size() > d2.size())
	{
		d2.push_front(d1[d1.size() - 1]);
		d1.pop_back();
	}
}

int main ()
{
	int n;
	cin >> n;
	deque <int> d1, d2;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		getline (cin, s);
		istringstream iss(s);
		if (s.substr(0, 3) == "add")
		{
			string temp;
			int n;
			iss >> temp >> n;
			add(d1, d2, n);
		}
		if (s == "take")
			take(d1, d2);
		if (s == "swap")
		{
			swap(d1, d2);
			if (d1.size() > d2.size())
			{
				d2.push_front(d1.back());
				d1.pop_back();
			}
		}
	}
	cout << d1.size() + d2.size() << endl;
	for (int i = 0; i < d1.size(); i++)
		cout << d1[i] << " ";
	for (int i = 0; i < d2.size(); i++)
		cout << d2[i] << " ";
}