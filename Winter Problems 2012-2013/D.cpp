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

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
void adding(string& c, int n)
{
	for (int i = 0; i < n; i++)
			c = '0' + c;
}
void add(string& c, int n)
{
	char temp = n + '0';
	c = temp + c;
}
string sum(string s1, string s2)
{
	unsigned int n = max(s1.size(), s2.size());
	if (s1.size() < n)
		adding(s1, n - s1.size());
	if (s2.size() < n)
		adding (s2, n - s2.size());
	string summary;
	int temp;
	bool inmind = false;
	for (int i = n-1; i >= 0; i--)
	{
		temp = (s1[i] - '0') + (s2[i] - '0');
		if (temp < 10)
		{
			
			if (inmind && temp == 9)
				add(summary, 0);
			if (!inmind)
				add(summary, temp);
			if (inmind && temp != 9)
			{
				add(summary, temp+1);
				inmind = false;
			}
			
		}
		else
		{
			if (inmind)
				add(summary, temp - 9);
			if (!inmind)
				add(summary, temp - 10);
			inmind = true;
		}
	}
	if (inmind)
		add(summary, 1);
	return summary;
}

int main ()
{
	int n, p;
	cin >> p >> n;
	if (n < 3)
	{
		string num1 = "", num2 = "", num3 = "";
		int temp = p*p;
		while (temp != 0)
		{
			add(num1, temp%10);
			temp /= 10;
		}
		temp = 2*p*p;
		while (temp != 0)
		{
			add(num2, temp%10);
			temp /= 10;
		}
		for (int i = 0; i <= n; i++)
			num2 += '0';
		temp = p*p;
		while (temp != 0)
		{
			add (num3, temp%10);
			temp /= 10;
		}
		for (int i = 0; i < 2*n + 2; i++)
			num3 += '0';
		cout << sum (sum(num1, num2), num3);
	}
	else
	{
		if (p >= 8)
		{
			cout << p*p;
			for (int i = 0; i < n-2; i++)
				cout << '0';
			cout << 2*p*p;
			for (int i = 0; i < n-1; i++)
				cout << '0';
			cout << p*p;
		}
		if (p > 3 && p <= 7)
		{
			cout << p*p;
			for (int i = 0; i < n-1; i++)
				cout << '0';
			cout << 2*p*p;
			for (int i = 0; i < n-1; i++)
				cout << '0';
			cout << p*p;
		}
		if (p == 3)
		{
			cout << '9';
			for (int i = 0; i < n-1; i++)
				cout << '0';
			cout << "18";
			for (int i = 0; i < n; i++)
				cout << '0';
			cout << '9';
		}
		if (p < 3)
		{
			cout << p*p;
			for (int i = 0; i < n; i++)
				cout << '0';
			cout << 2*p*p;
			for (int i = 0; i < n; i++)
				cout << '0';
			cout << p*p;
		}
	}
}