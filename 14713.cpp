#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<queue<string>> q(n + 1);
    string s_input;

    getline(cin, s_input);

    for (int i = 0; i < n + 1; i++)
    {
        getline(cin, s_input);
        istringstream ss(s_input);
        string s_buff;
        while (getline(ss, s_buff, ' '))
        {
            q[i].push(s_buff);
        }
    }

    bool isImpossible = true;
    int q_size = q[n].size();

    for (int i = 0; i < q_size; i++)
    {
        string base_word = q[n].front();
        for (int j = 0; j < n; j++)
        {
            if (!q[j].empty() && q[j].front() == base_word)
            {
                q[j].pop();
                q[n].pop();
                isImpossible = false;
                break;
            }
        }

        if (isImpossible)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        else isImpossible = true;
    }

    for (int i = 0; i < n; i++)
        if (!q[i].empty())
        {
            cout << "Impossible" << endl;
            return 0;
        }

    cout << "Possible" << endl;

    return 0;
}
