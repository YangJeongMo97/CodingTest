#include <iostream>

using namespace std;

int checkD(int current);

int main()
{
    bool numArray[10001] = { false };
    int result;
    for (int i = 1; i <= 10000; i++)
    {
        result = checkD(i);
        if (result <= 10000)
            numArray[result] = true;
    }

    for (int i = 1; i <= 10000; i++)
        if (!numArray[i]) cout << i << endl;
    return 0;
}

int checkD(int current)
{
    int result = current;
    while (current / 10 != 0 || current % 10 != 0)
    {
        result += current % 10;
        current /= 10;
    }
    return result;
}
