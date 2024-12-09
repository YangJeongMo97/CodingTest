#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    float result = (float)num1 / (float)num2 * 1000;
    int answer = (int)result;
    return answer;
}
