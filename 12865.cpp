#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int inventory[101][100001];
int weight[101];
int value[101];

int main()
{
	ios_base::sync_with_stdio(false); //iostream�� stdio�� ����ȭ ���� ����
	cout.tie(NULL);	//������� ������ ����. �Է��� ���޾� �ϰ� ����� �Ǵ� ����
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= weight[i])
			{
				inventory[i][j] = max(inventory[i - 1][j], value[i] + inventory[i - 1][j - weight[i]]);
			}
			else
				inventory[i][j] = inventory[i - 1][j];
		}
	}

	cout << inventory[N][K];

	return 0;
}