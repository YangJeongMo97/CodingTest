#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, K;
    map <int, pair<int, int>> um_Student;

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;

        if (um_Student.find(temp) == um_Student.end())
        {
            if (um_Student.size() < N)
            {
                um_Student[temp].first++;
                um_Student[temp].second = i;
            }
            else
            {
                pair<int, int> pTemp;
                int index = um_Student.begin()->first;
                pTemp = um_Student.begin()->second;

                for (auto& data : um_Student)
                {
                    if (pTemp > data.second)
                    {
                        index = data.first;
                        pTemp = data.second;
                    }
                }
                um_Student.erase(index);
                um_Student[temp].first++;
                um_Student[temp].second = i;
            }
        }
        else
        {
            um_Student[temp].first++;
        }
    }

    for (auto& data : um_Student)
        cout << data.first << " ";

    cout << endl;

    return 0;
}