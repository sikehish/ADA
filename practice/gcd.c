#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mod_euclids(int m, int n)
{
    int r = 0, count = 0;
    while (n > 0)
    {
        r = m % n;
        m = n;
        n = r;
        count++;
    }
    return count;
}

int euclids(int m, int n)
{
    int temp = 0, count = 0;
    while (n > 0 && m > 0)
    {
        if (n > m)
            n -= m;
        else
            m -= n;
        count++;
    }
    return count;
}

int cicf(int m, int n)
{
    int gcd = 1, count = 0;
    for (int i = 2; i <= m && i <= n; i++)
    {
        if (m % i == 0 && n % i == 0)
            gcd = i;
        count++;
    }
    return count;
}

void main()
{
    srand(time(NULL));
    FILE *fp;
    int x;
    fp = fopen("gcd.dat", "a");
    for (int i = 0; i <= 10; i++)
    {
        fprintf(fp, "%d ", i);
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        printf("%d %d\n", x, y);
        // CICF
        fprintf(fp, "%d\t", cicf(x, y));
        // Euclids
        fprintf(fp, "%d\t", euclids(x, y));
        // Modified Euclids
        fprintf(fp, "%d\n", mod_euclids(x, y));
    }
    fclose(fp);
}