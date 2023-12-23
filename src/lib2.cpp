#include "lib.h"

// Наивный алгоритм
int GCF(int A, int B){
    int min;

    if (A > B){
        min = B;
    }
    else if (A < B){
        min = A;
    }
    else{
        return A;
    }

    int q = min;

    while (q != 0){
        if (A % q == 0 && B % q == 0){
            return q;
        }
        --q;
    }

    return -1;
}

// Решето Эратосфена
int PrimeCount(int A, int B)
{
    bool sieve[B];
    int count = 0;

    for (int i = 1; i <= B; i++)
    { // Изначально все числа не вычеркнуты.
        sieve[i] = true;
    }

    for (int i = 2; i <= B; i++)
    {
        if (sieve[i])
        { // если i не вычеркнуто
            if (i >= A)
            {
                count++;
            }

            for (int j = i * i; j <= B; j += i)
            { // вычеркиваем все кратные числа начиная с i^2
                sieve[j] = false;
            }
        }
    }
    return count;
}