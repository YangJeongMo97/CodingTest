#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int N, B, C;
	long int result = 0;
	int* A;

	cin >> N;

	A = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		A[i] -= B;
		if (A[i] <= 0)
		{
			result++;
		}
		else
		{
			result++;
			if (A[i] % C != 0)
			{
				result += A[i] / C + 1;
			}
			else result += A[i] / C;
		}
	}

	cout << result << endl;

	return 0;
}
