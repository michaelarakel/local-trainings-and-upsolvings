#include <iostream>
#include <string>
using namespace std;
/*
zinvori uxix dirq hamarenq \-/

shrjvac dirq@ /-\

aj dirq@ /
         |
		 \

dzax dirq@    \
			  |
			  /
*/

int head[2], hand1[2], hand2[2];

void print (char a[100][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == hand1[0] && j == hand1[1])
				cout << '/';
			else
			{
				if (i == hand2[0] && j == hand2[1])
					cout << '\\';
				else
				{
					if (i == head[0] && j == head[1])
					{
						if (hand1[1] == hand2[1])
							cout << '|';
						else
							cout << '-';
					}
					else
						cout << '.';
				}
			}
		}
		cout << endl;
	}
}
void change(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MoveLeft ()
{
	if (hand1[1] == head[1] + 1)//uxix dirqic dzax
	{
		hand1[1] = head[1];
		hand2[1] = head[1];
		hand1[0] = head[0] + 1;
		hand2[0] = head[0] - 1;
		return;
	}
	if (hand1[1] == head[1] - 1)//shrjvac dirqic dzax
	{
		hand1[0] = head[0] - 1;
		hand1[1] = head[1];
		hand2[0] = head[0] + 1;
		hand2[1] = head[1];
		return;
	}
	if (hand1[0] == head[0] - 1)//aj dirqic dzax
	{
		hand1[0] = head[0];
		hand1[1] = head[1] + 1;
		hand2[0] = head[0];
		hand2[1] = head[1] - 1;
		return;
	}
	if (hand1[0] == head[0] + 1)//dzax dirqic dzax
	{
		hand1[0] = head[0];
		hand1[1] = head[1] - 1;
		hand2[0] = head[0];
		hand2[1] = head[1] + 1;
		return;
	}

}

void MoveRight ()
{
	for (int i = 0; i < 3; i++)
		MoveLeft();
}
void MoveAbout ()
{
	if ( (hand1[1] == head[1] + 1) ||
	     (hand1[1] == head[1] - 1)  )//uxix dirqic ptuyt kam shrjvac dirqic ptuyt
		change(hand1[1], hand2[1]);
	if ( (hand1[0] == head[0] + 1) ||
		  (hand1[0] == head[0] - 1) )//dzax dirqic ptuyt kam aj dirqic ptuyt
		  change(hand1[0], hand2[0]);
}

void MoveForward ()
{
	if (hand1[1] == head[1] + 1)//uxix dirqic araj
	{
		hand1[0]--;
		hand2[0]--;
		head[0]--;
	}
	if (hand1[1] == head[1] - 1)//shrjvac dirqic araj
	{
		hand1[0]++;
		hand2[0]++;
		head[0]++;
	}
	if (hand1[0] == head[0] + 1)//dzax dirqic araj
	{
		hand1[1]--;
		hand2[1]--;
		head[1]--;
	}
	if (hand1[0] == head[0] - 1)//aj dirqic araj
	{
		hand1[1]++;
		hand2[1]++;
		head[1]++;
	}
}
int main ()
{
	char space[100][100];
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == '-' ||
				space[i][j] == '|'  )
			{
				head[0] = i;
				head[1] = j;
			}
			if (space[i][j] == '/')
			{
				hand1[0] = i;
				hand1[1] = j;
			}
			if (space[i][j] == '\\')
			{
				hand2[0] = i;
				hand2[1] = j;
			}
		}
	}
	string word[2];
	for (int i = 0; i < k; i++)
	{
		cin >> word[0] >> word[1];
		if (word[0] == "Left")
			MoveLeft();
		if (word[0] == "Right")
			MoveRight();
		if (word[0] == "About")
			MoveAbout();
		if (word[0] == "Forward")
			MoveForward();
	}
	print (space, n, m);
	return 0;
}