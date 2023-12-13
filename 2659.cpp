#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int TimeNumber(int);
int CheckTN(int);

int main()
{
    int input, min;
    int nMyNum = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> input;
        nMyNum += (int)(input * pow(10, 3 - i));
    }

    min = CheckTN(nMyNum);

    cout << TimeNumber(min) << endl;

    return 0;
}

int TimeNumber(int nMyNum)
{
    int count = 1;
    vector <int> vMemory;

    for (int i = 1111; i <= 9999; i++)
    {
        if ((i % 1000) / 100 == 0 || (i % 100) / 10 == 0 || i % 10 == 0) continue;
        int temp = CheckTN(i);
        if (find(vMemory.begin(), vMemory.end(), temp) == vMemory.end()) vMemory.push_back(temp);
    }

    sort(vMemory.begin(), vMemory.end());

    for (auto& data : vMemory)
    {
        if (data < nMyNum) count++;
        else break;
    }

    return count;
}

int CheckTN(int nMyNum)
{
    int min = 9999, temp, count = 0, idx = 0;
    int nArray[4] = { nMyNum / 1000 , (nMyNum % 1000) / 100, (nMyNum % 100) / 10, nMyNum % 10 };

    for (int i = 0; i < 4; i++)
    {
        temp = nArray[i] * 1000 + nArray[(i + 1) % 4] * 100 + nArray[(i + 2) % 4] * 10 + nArray[(i + 3) % 4];
        if (min > temp)
            min = temp;
    }

    return min;
}
