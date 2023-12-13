#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    bool isWordStart = false;
    int nCount = 0, nLastIndex = 0;
    string sInput, sTemp;

    getline(cin, sInput, '\n');

    for (int i = 0; i < sInput.length(); i++)
    {
        if (sInput.at(i) == '<')
        {
            if (nCount > 0)
            {
                reverse(sTemp.begin(), sTemp.end());
                sInput.replace(nLastIndex, nCount, sTemp);
                sTemp.clear();
            }

            for (int j = i + 1; j < sInput.length(); j++)
                if (sInput.at(j) == '>')
                {
                    i = j;
                    isWordStart = false;
                    nCount = 0;
                    break;
                }
        }

        else if (sInput.at(i) == ' ')
        {
            if (nCount > 0)
            {
                reverse(sTemp.begin(), sTemp.end());
                sInput.replace(nLastIndex, nCount, sTemp);
                sTemp.clear();
            }
            isWordStart = false;
            nCount = 0;
            continue;
        }

        else
        {
            sTemp.append(1, sInput.at(i));
            if (!isWordStart)
            {
                nLastIndex = i;
                isWordStart = true;
                nCount++;
            }
            else
            {
                nCount++;
            }
        }
    }
    if (!sTemp.empty())
    {
        reverse(sTemp.begin(), sTemp.end());
        sInput.replace(nLastIndex, nCount, sTemp);
        sTemp.clear();
    }

    cout << sInput << endl;

    return 0;
}
