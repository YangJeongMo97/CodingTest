#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num_array[101][101];

int main()
{
    int x[] = { 1, 0, -1, 0 }, y[] = { 0, 1, 0, -1 };
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> num_array[i][j];

    int sum = 2 * n * m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = j + x[k];
                int ny = i + y[k];
                if (num_array[i][j] > num_array[ny][nx])
                    sum += (num_array[i][j] - num_array[ny][nx]);
            }
        }
    }

    cout << sum << endl;

    return 0;
}
