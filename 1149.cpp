#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rgb_array[1001][3];

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	int N;
	int cost[3] = { 0 };

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		rgb_array[i][0] = min(rgb_array[i - 1][1], rgb_array[i - 1][2]) + cost[0];
		rgb_array[i][1] = min(rgb_array[i - 1][0], rgb_array[i - 1][2]) + cost[1];
		rgb_array[i][2] = min(rgb_array[i - 1][0], rgb_array[i - 1][1]) + cost[2];
	}

	cout << min(rgb_array[N][0], min(rgb_array[N][1], rgb_array[N][2]));

	return 0;
}