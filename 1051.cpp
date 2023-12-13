#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, m, max = 1;
    string input;

    int nArray[51][51] = { 0 };

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < input.size(); j++)
            nArray[i][j] = input[j] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 1; ; k++)
            {
                if (i + k >= n || j + k >= m) break;
                if (nArray[i][j] == nArray[i][j + k] && nArray[i][j] == nArray[i + k][j] && nArray[i][j] == nArray[i + k][j + k])
                {
                    if (max < (int)pow(k + 1, 2)) max = (int)pow(k + 1, 2);
                }
            }
        }
    }

    cout << max << endl;
    return 0;
}
