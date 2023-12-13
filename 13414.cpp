#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int K, L, nStudent;
    map <int, int> mStudent;

    cin >> K >> L;

    for (int i = 0; i < L; i++)
    {
        cin >> nStudent;
        mStudent[nStudent] = i;
    }

    vector <pair<int, int>> vStudent(mStudent.begin(), mStudent.end());

    sort(vStudent.begin(), vStudent.end(), [](pair<int, int> left, pair<int, int> right) { return left.second < right.second; });

    int count = 0;

    for (auto& data : vStudent)
    {
        if (count == K) break;
        printf("%08d\n", data.first);
        count++;
    }

    return 0;
}