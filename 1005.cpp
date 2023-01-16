#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int indegree[1000];

map<int, int> cost;
map<int, int> resultCost;

int main()
{
	int T, N, K, x, y, W, nodeCost;

	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int result = 0;

		cin >> N >> K;

		vector<vector<int>> v(N + 1);
		queue<int> q;

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &nodeCost);
			cost[i] = nodeCost;
			resultCost[i] = nodeCost;
		}

		for (int i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			v[x].emplace_back(y);
			indegree[y]++;
		}

		cin >> W;

		for (int i = 1; i <= N; i++)
		{
			if (i == W) continue;
			else if (indegree[i] == 0) q.emplace(i);
		}

		while (!q.empty())
		{
			int idx = q.front();
			q.pop();

			for (int i = 0; i < v[idx].size(); i++)
			{
				int n = v[idx][i];
				resultCost[n] = max(resultCost[n], resultCost[idx] + cost[n]);

				if (--indegree[n] == 0) q.emplace(n);
			}
		}

		cout << resultCost[W] << endl;
		
		for (int i = 1; i <= N; i++)
		{
			indegree[i] = 0;
			cost[i] = 0;
			resultCost[i] = 0;
		}
	}
	return 0;
}
