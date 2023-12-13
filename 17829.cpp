#include <iostream>
#include <algorithm>

using namespace std;

int DDD_pulling(int** n_array, int size)
{
	if (size == 1) return n_array[0][0];
	else
	{
		int second = 0, i_cnt = 0, j_cnt = 0;
		int** temp = new int* [size / 2];
		for (int i = 0; i < size / 2; i++)
			temp[i] = new int[size / 2];
		for (int i = 0; i < size; i += 2)
		{
			for (int j = 0; j < size; j += 2)
			{
				int find_second[4] = { n_array[i][j], n_array[i][j + 1], n_array[i + 1][j], n_array[i + 1][j + 1] };
				sort(find_second, find_second + 4);
				second = find_second[2];
				temp[i_cnt][j_cnt] = second;
				j_cnt++;
			}
			j_cnt = 0;
			i_cnt++;
		}
		size /= 2;
		second = DDD_pulling(temp, size);
		return second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	int N;

	cin >> N;

	int** n_array = new int* [N];

	for (int i = 0; i < N; i++)
		n_array[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> n_array[i][j];

	cout << DDD_pulling(n_array, N) << endl;

	return 0;
}