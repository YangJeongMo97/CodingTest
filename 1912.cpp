#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //iostream�� stdio�� ����ȭ ���� ����
	cout.tie(NULL);	//������� ������ ����. �Է��� ���޾� �ϰ� ����� �Ǵ� ����
	cin.tie(NULL);

	int n, max = 0x80000000, sum = 0;

	cin >> n;

	int* n_array = new int[n + 1]{ 0 };

	for (int i = 1; i <= n; i++)
	{
		cin >> n_array[i];
		if (n_array[i - 1] > 0) n_array[i] = n_array[i] + n_array[i - 1];
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (max < n_array[i]) max = n_array[i];
	}

	cout << max;

	return 0;
}