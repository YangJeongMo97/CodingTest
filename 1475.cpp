#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main()
{
    int N, result = 0, sum = 0;
    unordered_map <int, int> un_map;
    cin >> N;

    while (N / 10 != 0 || N % 10 != 0)
    {
        un_map[N % 10]++;
        N /= 10;
    }

    for (const auto& num : un_map)
    {
        if (num.first == 6 || num.first == 9)
        {
            sum += num.second;
            if (result < (int)round((double)sum / 2.f)) result = (int)round((double)sum / 2.f);
        }
        else if (result < num.second) result = num.second;
    }

    cout << result << endl;

    return 0;
}