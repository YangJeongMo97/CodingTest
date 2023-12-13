#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    int a, b;
    int* result;

    cin >> T;

    result = new int[T];

    for (int i = 0; i < T; i++)
    {
        cin >> a;
        cin >> b;
        result[i] = 1;
        for (int j = 0; j < b; j++)
        {
            result[i] = result[i] * a % 10;
            if (result[i] == 0) result[i] = 10;
        }
    }
    for (int i = 0; i < T; i++)
        cout << result[i] << endl;

    delete[] result;

    return 0;
}
