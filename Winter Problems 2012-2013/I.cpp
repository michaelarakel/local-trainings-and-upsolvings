#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string word;
	cin >> word;
	int count = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == 'A' ||
			word[i] == 'D' ||
			word[i] == 'G' ||
			word[i] == 'J' ||
			word[i] == 'M' ||
			word[i] == 'P' ||
			word[i] == 'T' ||
			word[i] == 'W')
			count++;
		if (word[i] == 'B' ||
			word[i] == 'E' ||
			word[i] == 'H' ||
			word[i] == 'K' ||
			word[i] == 'N' ||
			word[i] == 'Q' ||
			word[i] == 'U' ||
			word[i] == 'X')
			count += 2;
		if (word[i] == 'C' ||
			word[i] == 'F' ||
			word[i] == 'I' ||
			word[i] == 'L' ||
			word[i] == 'O' ||
			word[i] == 'R' ||
			word[i] == 'V' ||
			word[i] == 'Y')
			count += 3;
		if (word[i] == 'S' ||
			word[i] == 'Z')
			count += 4;
	}
	cout << count;
	return 0;
}