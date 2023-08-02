#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cicf(int x, int y)
{
    int ans = 1, count = 0;
    for (int i = 1; i <= x && i <= y; i++)
    {
        count++;
        if (x % i == 0 && y % i == 0)
            ans = i;
    }
    return count;
}

int modified_euclids(int m, int n)
{
    int rem = 1, count = 0;
    while (n > 0)
    {
        count++;
        rem = m % n;
        m = n;
        n = rem;
    }

    return count;
}
int euclids(int m, int n)
{
    int count = 0;
    while (m != n)
    {
        if (n > m)
            n -= m;
        else
            m -= n;
        count++;
    }
    return count;
}

int gcd_modulo(int a, int b)
{
    int rem, count = 0;
    while (b != 0)
    {
        count++;
        rem = a % b;
        a = b;
        b = rem;
    }
    return count;
}

int gcd_rept_sub(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    int count = 0;

    while (a != b)
    {
        count++;
        if (a > b)
            a = a - b;

        else
            b = b - a;
    }

    return count;
}

int gcd_cons_intg(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    int t, t1, t2, count = 0;

    if (a > b)
        t = b;

    else
        t = a;

    while (t != 1)
    {
        count++;
        t1 = a % t;
        if (t1 == 0)
        {
            t2 = b % t;
            if (t2 == 0)
                return count;
        }
        t = t - 1;
    }
    return count;
}

void main()
{
    // srand(time(NULL));
    FILE *fp, *fp2;
    fp = fopen("gcd2.dat", "a");
    fp2 = fopen("gcd.dat", "a");
    for (int i = 0; i <= 10; i++)
    {
        fprintf(fp, "%d\t", i);
        fprintf(fp2, "%d\t", i);
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        printf("(%d,%d)\n", x, y);
        // CICF
        fprintf(fp, "%d\t", cicf(x, y));
        fprintf(fp2, "%d\t", gcd_cons_intg(x, y));
        // Euclids
        fprintf(fp, "%d\t", euclids(x, y));
        fprintf(fp2, "%d\t", gcd_rept_sub(x, y));
        // Modified Euclids
        fprintf(fp, "%d\n", modified_euclids(x, y));
        fprintf(fp2, "%d\n", gcd_modulo(x, y));
    }
    // system("gnuplot > load 'plotfile2.txt'");
    fclose(fp);
    fclose(fp2);
}