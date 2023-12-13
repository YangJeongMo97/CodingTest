#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int* num;

    cin >> n;

    num = new int[n];

    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    for (int i = 0; i < n; i++)
        cout << num[i] << "\n";

    delete[] num;

    return 0;
}