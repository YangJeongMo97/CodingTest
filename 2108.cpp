#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int averageValue(int* numArray, int size);
int mode(int* numArray, int size);

int main()
{
    int T;
    int* numArray;

    cin >> T;

    numArray = new int[T];

    for (int i = 0; i < T; i++)
        cin >> numArray[i];

    sort(numArray, numArray + T);

    cout << averageValue(numArray, T) << endl;
    cout << numArray[T / 2] << endl;
    cout << mode(numArray, T) << endl;
    cout << numArray[T - 1] - numArray[0] << endl;

    delete numArray;

    return 0;
}

int averageValue(int* numArray, int size)
{
    int sum = 0;
    double result;
    for (int i = 0; i < size; i++)
        sum += numArray[i];
    result = (double)sum / (double)size;
    result = round(result);
    return (int)result;
}

int mode(int* numArray, int size)
{
    int result = 0, maxNum = 0, firstmin = 0, secondmin = 0;
    unordered_map <int, int> un_map;

    for (int i = 0; i < size; i++)
    {
        un_map[numArray[i]]++;
    }

    for (const auto& num : un_map)
    {
        if (num.second > maxNum)
        {
            maxNum = num.second;
            result = num.first;
            firstmin = result;
            secondmin = 4001;
        }
        else if (num.second == maxNum)
        {
            if (firstmin > num.first)
            {
                secondmin = firstmin;
                firstmin = num.first;
            }
            else if (secondmin > num.first) secondmin = num.first;
            result = secondmin;
        }
    }

    return result;
}
