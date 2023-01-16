#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, temp, result;
    cin >> n;
    
    result = 4;
    temp = sqrt(result);
    
    for(int i = 0; i < n; i++)
    {
        result = pow(2 * temp - 1, 2);
        temp = sqrt(result);
    }
    
    cout << result;
    
    return 0;
}
