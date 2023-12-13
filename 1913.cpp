#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, findNum;
    int currentX, currentY, startX, startY, nPattern = 1, nDirection = 0, nCount = 0;

    cin >> N >> findNum;

    int** nArray = new int* [N] {0};
    for (int i = 0; i < N; i++)
        nArray[i] = new int[N] {0};

    startX = N / 2;
    startY = N / 2;

    currentX = startX;
    currentY = startY;

    for (int i = 0; i < N * N; i++)
    {
        nArray[currentY][currentX] = i + 1;

        switch (nDirection)
        {
        case 0:
            currentY--;
            break;
        case 1:
            currentX++;
            break;
        case 2:
            currentY++;
            break;
        case 3:
            currentX--;
            break;
        }

        nCount++;
        if (nPattern == nCount)
        {
            nCount = 0;
            if (nDirection % 2 == 1)
            {
                if (nDirection == 3) nDirection = 0;
                else nDirection++;
                nPattern++;
            }
            else nDirection++;
        }

    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (findNum == nArray[i][j])
            {
                currentX = j;
                currentY = i;
            }
            cout << nArray[i][j] << " ";
        }
        cout << "\n";
    }

    cout << currentY + 1 << " " << currentX + 1 << endl;

    return 0;
}
