#include <iostream>
#pragma warning(disable:4996)

using namespace std;

#define MAX 16

int N;
int T[MAX] = { 0, }, P[MAX] = { 0, }, res[MAX] = { 0, };

int Max(int a, int b)
{
	return (a > b) ? a : b;
}

void result()
{
	int deadLine;
	for (int i = N; i > 0; i--)
	{
		deadLine = i + T[i];
		if (deadLine > N + 1)
		{
			res[i] = res[i + 1];
		}
		else
		{
			res[i] = Max(res[i + 1], res[deadLine] + P[i]);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	result();

	cout << res[1] << endl;

	return 0;
}
