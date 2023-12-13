#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coin[101];
int value[10001];

int main()
{
	ios_base::sync_with_stdio(false); //iostream�� stdio�� ����ȭ ���� ����
	cout.tie(NULL);	//������� ������ ����. �Է��� ���޾� �ϰ� ����� �Ǵ� ����
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	value[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			value[j] += value[j - coin[i]];
		}
	}

	cout << value[k];

	return 0;
}