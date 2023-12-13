#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    double trimmed_mean, adjusted_mean, sum = 0.0;

    cin >> N >> K;

    if (K > N) return 0;

    double* num_array = new double[N];

    for (int i = 0; i < N; i++)
        cin >> num_array[i];

    sort(num_array, num_array + N);

    for (int i = K; i < N - K; i++)
        sum += num_array[i];

    trimmed_mean = sum / (N - 2 * K);
    sum = 0;

    for (int i = 0; i < K; i++)
    {
        num_array[i] = num_array[K];
        num_array[N - i - 1] = num_array[N - K - 1];
    }

    for (int i = 0; i < N; i++)
        sum += num_array[i];

    adjusted_mean = sum / N;

    printf("%.2lf\n", trimmed_mean + 0.00000001);
    printf("%.2lf\n", adjusted_mean + 0.00000001);

    return 0;
}
