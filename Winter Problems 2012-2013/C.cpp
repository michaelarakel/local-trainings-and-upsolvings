#include <iostream>
#include <iomanip>
using namespace std;

int n, m, modgrade[100][100], examgrade[100];
double modcoeff[100][100], examcoeff[100], importance[100];

double modaverage(int i)
{
	double modav = 0;
	for (int j = 0; j < m; j++)
		modav += modgrade[i][j] * modcoeff[i][j];
	return modav;
}

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> modgrade[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> modcoeff[i][j];
	for (int i = 0; i < n; i++)
		cin >> examcoeff[i];
	for (int i = 0; i < n; i++)
		cin >> examgrade[i];
	for (int i = 0; i < n; i++)
		cin >> importance[i];
	double GPA = 0;
	for (int i = 0; i < n; i++)
		GPA += (modaverage(i)*examcoeff[i] + examgrade[i]*(1 - examcoeff[i]))*importance[i];
	cout << fixed << setprecision(5) << GPA/25;
	return 0;
}