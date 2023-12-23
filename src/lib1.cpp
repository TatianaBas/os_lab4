#include "lib.h"

// Алгоритм Евклида
int GCF(int A, int B){
    int max, min;

    if (A > B){
        max = A;
        min = B;
    }
    else if(A < B){
        max = B;
        min = A;
    }
    else{
        return A;
    }

    while (min != 0){
        int q = min;
        min = max % min;
        max = q;
    }

    return max;
}

// Наивный алгоритм подсчета простых чисел
bool bruteforce(int n)
{
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return true;
        }
        ++i;
    }
    return false;
}

int PrimeCount(int A, int B)
{
    int count = 0;
    for (int i = A; i <= B; ++i)
    {
        if (not bruteforce(i))
        {
            count++;
        }
    }
    return count;
}