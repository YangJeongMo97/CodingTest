#include <iostream>
using namespace std;

int main()
{
    char* string;
    string = (char*)malloc(sizeof(char) * 100);
    cin >> string;
    cout << string << "??!" << endl;
    free(string);
    
    return 0;
}
