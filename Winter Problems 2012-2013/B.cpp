#include <iostream>
#include <string>
using namespace std;

int pow (int a, int b)
{
	int multip = 1;
	for (int i = 0; i < b; i++)
		multip *= a;
	return multip;
}

int revstrtoint(string s)
{
	int num = 0, n = s.size();
	for (int i = 0; i < n; i++)
		num += (s[i] - '0') * pow(10, i);
	return num;
}

int main ()
{
	string equation;
	cin >> equation;
	string num1 = "", num2 = "", num3 = "";
	bool a = true, b = false, c = false;
	int n = equation.size();
	for (int i = 0; i < n; i++)
	{
		if (equation[i] == '+')
		{
			a = false;
			b = true;
			continue;
		}
		if (equation[i] == '=')
		{
			b = false;
			c = true;
			continue;
		}
		if (a)
			num1 += equation[i];
		if (b)
			num2 += equation[i];
		if (c)
			num3 += equation[i];
	}
	if (revstrtoint(num1) + revstrtoint(num2) == revstrtoint(num3))
		cout << "True";
	else
		cout << "False";
	return 0;
}
