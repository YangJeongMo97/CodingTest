#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, direction, length, maxW = 0, maxH = 0, minA = 501, minB = 501;
    vector<pair<int, int>> vLength;
    pair<int, int> temp;

    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        cin >> direction >> length;
        vLength.push_back({ direction, length });
    }

    for (auto& data : vLength)
    {
        temp = data;
        vLength.push_back(temp);
    }

    for (int i = 0; i < vLength.size() / 2; i++)
    {
        if (vLength[i].first / 3 == 0)
        {
            if (maxH < vLength[i].second) maxH = vLength[i].second;
        }
        else
        {
            if (maxW < vLength[i].second) maxW = vLength[i].second;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (vLength[i].second == maxW && vLength[i + 1].second == maxH || vLength[i].second == maxH && vLength[i + 1].second == maxW)
        {
            minA = vLength[i + 3].second;
            minB = vLength[i + 4].second;
        }
    }

    cout << (maxW * maxH - minA * minB) * N << endl;

    return 0;
}


