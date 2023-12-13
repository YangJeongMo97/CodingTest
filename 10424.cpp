#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LCS[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false); //iostream�� stdio�� ����ȭ ���� ����
	cout.tie(NULL);	//������� ������ ����. �Է��� ���޾� �ϰ� ����� �Ǵ� ����
	cin.tie(NULL);

	string A, B;

	cin >> A >> B;

	int a_len = A.length();
	int b_len = B.length();

	for (int i = 1; i <= a_len; i++)
	{
		for (int j = 1; j <= b_len; j++)
		{
			if (A[i - 1] == B[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	cout << LCS[a_len][b_len];

	return 0;
}