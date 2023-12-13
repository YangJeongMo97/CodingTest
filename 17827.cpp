#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n_array[200001];
int n, m, v;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m >> v;

	int head = --v;
	int body = n - head;

	for (int i = 0; i < n; i++)
		cin >> n_array[i];

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (k < head) cout << n_array[k] << "\n";
		else cout << n_array[(k - head) % body + head] << "\n";
	}

	return 0;
}