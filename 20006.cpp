#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int p, l, m, lastIdx = 0;
    string n;
    vector<pair<string, int>> room[301];

    cin >> p >> m;

    for (int i = 0; i < p; i++)
    {
        cin >> l >> n;

        bool isPossible = false;

        for (int j = 0; j < i; j++)
        {
            if (room[j].size() < m && room[j].size() > 0)
            {
                if (abs(room[j][0].second - l) <= 10)
                {
                    isPossible = true;
                    room[j].push_back(make_pair(n, l));
                    break;
                }
            }
        }
        if (!isPossible) room[i].push_back(make_pair(n, l));
    }

    for (int i = 0; i < 301; i++)
    {
        if (room[i].size() == 0) continue;
        else if (room[i].size() >= m)
            cout << "Started!" << endl;
        else if (room[i].size() < m)
            cout << "Waiting!" << endl;

        sort(room[i].begin(), room[i].end());

        for (int j = 0; j < room[i].size(); j++)
            cout << room[i][j].second << " " << room[i][j].first << endl;
    }

    return 0;
}
