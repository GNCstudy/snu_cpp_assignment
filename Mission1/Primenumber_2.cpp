#include <iostream>
#include <cmath>
using namespace std;

int number = 100;
int primeNum[101];

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
            printf("%d\n", primeNum[i]);
    }
}
int main()
{
    primeNumberSieve();
}