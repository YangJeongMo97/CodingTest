#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int minute, score = 0, state = 0;

    cin >> minute;

    int* list = new int[minute];
    int** homework = new int* [minute];

    for (int i = 0; i < minute; i++)
        homework[i] = new int[2]{ 0, };

    for (int i = 0; i < minute; i++)
    {
        cin >> list[i];
        if (list[i] != 0)
        {
            cin >> homework[i][0] >> homework[i][1];
        }
    }

    for (int i = 0; i < minute; i++)
    {
        if (list[i] != 0)
            state = i;
        homework[state][1]--;
        if (homework[state][1] == 0)
        {
            score += homework[state][0];
            for (int j = state; j >= 0; j--)
            {
                if (homework[j][1] != 0)
                {
                    state = j;
                    break;
                }
            }
        }
    }

    cout << score << endl;

    delete[] list;
    for (int i = 0; i < minute; i++)
        delete[] homework[i];
    delete[] homework;

    return 0;
}