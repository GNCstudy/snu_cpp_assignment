#include <iostream>
#include <cmath>
using namespace std;

int number = 100; // 검사하고자 하는 소수의 범위
int primeNum[101]; // 검사하고자 하는 소수

void primeNumberSieve()  // Void
{
    for (int i = 2; i <= number; i++) // For Loop (2부터 NUMBER 까지 1씩 증가하면서)
    {
        primeNum[i] = i; // 배열의 초기화
    }

    for (int i = 2; i <= sqrt(number); i++) // For Loop (2부터 루트 NUMBUR의 내림수까지 1씩 증가하면서)
    {
        if (primeNum[i] == 0) // 몇 번째 Loop인가 나타내는 수를 i라 하면 배열 안에서 i 번째의 수가 0이면 다음의 Loop로 바로 이동
            continue;
        for (int j = i * i; j <= number; j += i) // For Loop (i의 제곱부터 NUMBER까지 1씩 증가하면서)
            primeNum[j] = 0; // 0으로 바꿈
    }
    for (int i = 2; i <= number; i++) // For Loop (2부터 루트 NUMBUR의 내림수까지 1씩 증가하면서)
    {
        if (primeNum[i] != 0) // 배열 안에서 0으로 바뀌지 않았다면 그 수는 소수
            printf("%d\n", primeNum[i]);
    }
}
int main() // 메인함수
{
    primeNumberSieve();  // Void의 함수를 불러 옴
}