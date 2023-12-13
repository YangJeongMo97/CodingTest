#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long A, B, C, temp;

long long pow(long long b)
{
	if (b == 0) return 1;
	if (b == 1) return A % C;

	temp = pow(b / 2) % C;

	if (b % 2 == 0) return temp * temp % C;
	else return temp * temp % C * A % C;
}

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	cin >> A >> B >> C;

	cout << pow(B);

	return 0;
}