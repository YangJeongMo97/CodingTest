#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int N, textNum, queueNum, count;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        count = 0;
        queue<pair<int, int>> q_queue;
        priority_queue<int> pq_Priority;

        cin >> textNum >> queueNum;

        for (int j = 0; j < textNum; j++)
        {
            int x;
            cin >> x;
            q_queue.push({ j, x });
            pq_Priority.push(x);
        }

        while (!q_queue.empty())
        {
            int idx = q_queue.front().first;
            int importance = q_queue.front().second;
            q_queue.pop();
            if (pq_Priority.top() == importance)
            {
                pq_Priority.pop();
                count++;
                if (idx == queueNum)
                {
                    cout << count << endl;
                    break;
                }
            }
            else q_queue.push({ idx, importance });
        }
    }


    return 0;
}
