#include <iostream>

using namespace std;

int main()
{
    int T;
    int result[41] = { 0, 1 };

    for (int i = 2; i < 41; i++)
        result[i] = result[i - 2] + result[i - 1];

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        if (n == 0) cout << "1 0" << endl;
        else if (n == 1) cout << "0 1" << endl;
        else cout << result[n - 1] << " " << result[n] << endl;
    }

    return 0;
}
