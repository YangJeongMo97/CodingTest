#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, M, B;
    int minTime = 2147383647;
    int highest;
    int house[500][500];

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> house[i][j];

    for (int h = 0; h <= 256; h++)
    {
        int removeBlock = 0;
        int buildBlock = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int mainHeight = house[i][j] - h;
                if (mainHeight > 0) removeBlock += mainHeight;
                else buildBlock -= mainHeight;
            }
        }

        if (removeBlock + B >= buildBlock)
        {
            if (minTime >= removeBlock * 2 + buildBlock)
            {
                minTime = removeBlock * 2 + buildBlock;
                highest = h;
            }
        }
    }

    cout << minTime << " " << highest << endl;

    return 0;
}
