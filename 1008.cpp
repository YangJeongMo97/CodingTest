#include <iostream>
using namespace std;

int main()
{
    int a, b;
    double result;
    cin >> a >> b;
    
    result = a / (double)b;
    
    cout.precision(10);
    cout << result << endl;
    
    return 0;
}
