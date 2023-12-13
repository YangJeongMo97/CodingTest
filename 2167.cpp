#include <iostream>

using namespace std;

int main()
{
    unsigned int i, j, x, y, K, N, M;

    cin >> N;
    cin >> M;

    int** nArray = new int* [N];

    for (int a = 0; a < N; a++)
        nArray[a] = new int[M] {0};

    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            cin >> nArray[a][b];
        }
    }

    cin >> K;

    int* sumArray = new int[K] {0};

    for (int a = 0; a < K; a++)
    {
        cin >> i >> j >> x >> y;
        for (int q = i - 1; q < x; q++)
            for (int w = j - 1; w < y; w++)
                sumArray[a] += nArray[q][w];
    }

    for (int a = 0; a < K; a++)
        cout << sumArray[a] << endl;

    for (int a = 0; a < N; a++)
        delete[] nArray[a];
    delete[] nArray;
    delete[] sumArray;

    return 0;
}