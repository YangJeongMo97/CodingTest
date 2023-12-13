#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isJava(const string& input)
{
    for (const auto& data : input)
    {
        if (isupper(data)) return true;
    }
    return false;
}

bool isCpp(const string& input)
{
    for (const auto& data : input)
    {
        if (data == '_') return true;
    }
    return false;
}

bool isError(const string& input)
{
    bool is_underbar = false;
    bool is_upper = false;
    for (const auto& data : input)
    {
        if (data == '_') is_underbar = true;
        else if (isupper(data)) is_upper = true;
    }

    if (is_underbar && is_upper) return true;

    else if (input[0] == '_' || isupper(input[0])) return true;

    else if (*(input.end() - 1) == '_') return true;

    for (int i = 0; i < input.length() - 1; i++)
        if (input[i] == '_' && input[i + 1] == '_') return true;

    return false;
}

string JavaToCpp(const string& input)
{
    string s_temp = "";

    for (const auto& data : input)
    {
        if (isupper(data))
        {
            s_temp += '_';
            s_temp += tolower(data);
        }
        else s_temp += data;
    }

    return s_temp;
}

string CppToJava(const string& input)
{
    string s_temp = "";
    bool is_underbar = false;

    for (const auto& data : input)
    {
        if (data == '_')
        {
            is_underbar = true;
        }
        else
        {
            if (is_underbar)
            {
                s_temp += toupper(data);
                is_underbar = false;
            }
            else s_temp += data;
        }
    }

    return s_temp;
}

int main()
{
    string input;

    cin >> input;

    if (isError(input))
        cout << "Error!" << endl;

    else if (isCpp(input))
        cout << CppToJava(input) << endl;

    else if (isJava(input))
        cout << JavaToCpp(input) << endl;

    else
        cout << input << endl;


    return 0;
}
