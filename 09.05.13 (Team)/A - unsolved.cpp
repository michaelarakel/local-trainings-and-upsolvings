#include <iostream>
#include <string>

using namespace std;

string binary(long long a)
{
	string ans;
	while (a != 0)
	{
		ans.push_back(a%2 + '0');
		a/= 2;
	}
	return ans;
}

long long decimal (string& s)
{
	long long ans = 0, pow = 1;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		ans += (s[i] - '0') * pow;
		pow *= 2;
	}
	return ans;
}


int main ()
{
	unsigned long long a, b;
	cin >> a >> b;
	if (a == b)
	{
		cout << 0;
		return 0;
	}
	cout << binary (a^b) << endl;
	string first = binary(a), second = binary(b);
	string ans = "";
	if (second.size() > first.size())
		for (int i = 0; i < second.size(); ++i)
			ans.push_back('1');
	else
	{
		for (int i = first.size() - 1; i >= 0; --i)
		{
			if (first[i] == second[i])
				ans.push_back(first[i]);
			else
			{
				for (int j = 0; j < i; ++j)
					ans.push_back('1');
				break;
			}
		}
	}
	cout << decimal(ans);
	return 0;
}