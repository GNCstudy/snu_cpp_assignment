#include "stdc++.h"  // The header file is already included in the folder.
#include <cmath>
using namespace std;

int number = 10000;
int primeNum[10001];

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