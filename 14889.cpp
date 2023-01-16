#include <iostream>
#include <math.h>

using namespace std;

int table[21][21];
bool check[22];
int N;
int result = 1000000000;

void TeamMaking(int x, int pos)
{
	if (x == N / 2)
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i] == true && check[j] == true) start += table[i][j];
				if (check[i] == false && check[j] == false) link += table[i][j];
			}
		}

		int temp = abs(start - link);
		if (result > temp) result = temp;

		return;
	}

	for (int i = pos; i < N; i++)
	{
		check[i] = true;
		TeamMaking(x + 1, i + 1);
		check[i] = false;
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> table[i][j];
		}
	}

	TeamMaking(0, 1);

	cout << result;
    
    return 0;
} 
