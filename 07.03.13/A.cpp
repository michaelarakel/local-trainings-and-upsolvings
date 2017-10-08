#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct player
{
	string name;
	double points;
};

bool operator < (const player& a, const player& b)
{
	if (a.points == b.points)
		return a.name < b.name;
	return a.points < b.points;
}

bool find (vector <player>& v, player a, int& n)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].name == a.name)
		{
			n = i;
			return true;
		}
	}
	return false;
}

int main ()
{
	int n;
	string s;
	cin >> n;
	getline (cin, s);
	vector <player> v;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		char temp1 = '-', temp2 = ':';
		int pos1 = s.find(temp1), pos2 = s.find(temp2);
		player one, two;
		one.name = s.substr(0, pos1);
		two.name = s.substr(pos1 + 1, pos2 - pos1 - 1);
		s.erase(0, pos2 + 1);
		pos2 = s.find(temp1);
		if (pos2 == 1)
		{
			one.points = s[0] - '0';
			two.points = s[2] - '0';
		}
		else
			one.points = two.points = 0.5;
		int j = 0;
		if (!find(v, one, j))
			v.push_back(one);
		else
			v[j].points += one.points;
		j = 0;
		if (!find(v, two, j))
			v.push_back(two);
		else
			v[j].points += two.points;
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++)
	{
		int num1 = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].points != v[j].points)
				break;
			i++;
		}
		if (num1 == i)
			cout << num1 + 1 << ". " << v[i].name << " - " << v[i].points;
		else
		{
			cout << num1 + 1 << '-' << i + 1 << '.';
			for (int j = i; j >= num1 ; j--)
			{
				cout << " " << v[j].name;
				if (j != num1)
					cout << ',';
			}
			cout << " - " << v[num1].points;
		}
		cout << endl;
	}
}