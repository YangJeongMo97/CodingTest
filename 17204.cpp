#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, K, input, count = 1, last_idx = 0;

    cin >> N >> K;

    vector <pair<int, bool>> the_game_of_death;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        the_game_of_death.push_back({ input, false });
    }

    while (K != the_game_of_death[last_idx].first)
    {
        the_game_of_death[last_idx].second = true;
        last_idx = the_game_of_death[last_idx].first;

        if (the_game_of_death[last_idx].second)
        {
            count = -1;
            break;
        }

        count++;
    }

    cout << count;

    return 0;
}
