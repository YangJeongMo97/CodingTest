#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    bool* bArray;
    int* iArray;
    int N, K, resIdx = 0, count = 0, currentIDX = 0, bCount = 0;

    cin >> N;
    cin >> K;

    bArray = new bool[N] {false, };
    iArray = new int[N] {0, };

    while (bCount != N)
    {
        if (currentIDX == N) currentIDX = 0;
        if (bArray[currentIDX])
        {
            currentIDX++;
            continue;
        }
        count++;
        if (count == K)
        {
            bArray[currentIDX] = true;
            count = 0;
            iArray[resIdx++] = currentIDX + 1;
            bCount++;
        }
        currentIDX++;
    }

    cout << "<";
    for (int i = 0; i < N - 1; i++)
        cout << iArray[i] << ", ";
    cout << iArray[N - 1] << ">\n";

    delete[] bArray;
    delete[] iArray;

    return 0;
}