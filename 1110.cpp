#include <iostream>

using namespace std;

int main()
{
    int origin, count = 0, currentNum, fixedNum;

    cin >> origin;

    currentNum = origin;
    do
    {
        if (currentNum < 10) fixedNum = currentNum;
        else fixedNum = (currentNum / 10) + (currentNum % 10);

        currentNum = (currentNum % 10 * 10) + fixedNum % 10;
        count++;

    } while (origin != currentNum);

    cout << count << endl;

    return 0;
}