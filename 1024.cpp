#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	int N, L, num = 0, result;

	cin >> N >> L;

	for (int i = 0; i < L; i++)
		num += i;

	while ((N - num) % L != 0)
	{
		num += L;
		L++;
	}

	if (L < 2 || L > 100 || N < num)
	{
		cout << "-1\n";
		return 0;
	}

	result = (N - num) / L;

	for (int i = 0; num != 0; i++)
	{
		num -= i;
		cout << result + i << " ";
	}

	cout << "\n";

	return 0;
}
