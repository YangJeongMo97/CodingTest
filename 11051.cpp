#include <iostream>
#include <algorithm>

using namespace std;

unsigned int dp[1001][1001];

unsigned int binominal(int n, int k)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] % 10007 + dp[i - 1][j] % 10007) % 10007;
			}
		}
	}

	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false); //iostream�� stdio�� ����ȭ ���� ����
	cout.tie(NULL);	//������� ������ ����. �Է��� ���޾� �ϰ� ����� �Ǵ� ����
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;

	if (N > 1000 || K > N) return 0;

	cout << binominal(N, K) << endl;

	return 0;
}