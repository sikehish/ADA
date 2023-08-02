#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cicf(int a, int b)
{
    int gcd = 1, count = 0;
    for (int i = 1; i <= a && i <= b; i++)
    {
        count++;
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }

    return count;
}

int modified_euclid(int m, int n)
{
    int r, count = 0;
    while (n > 0)
    {
        count++;
        r = m % n;
        m = n;
        n = r;
    }

    return count;
}

int euclid(int m, int n)
{
    int count = 0;
    if (m == 0 || n == 0)
        return 0;
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
// int euclid(int m , int n){
//     int count=0,temp;
//     while(n>0){
//         if(n>m){
//             temp=m; m=n; n=m;
//         }
//         m-=n;
//         count++;
//     }

//     return count;
// }

void main()
{
    // srand(time(NULL));
    FILE *fp;
    fp = fopen("gcd.dat", "a");
    for (int i = 0; i < 10; i++)
    {
        fprintf(fp, "%d\t", i + 1);
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        if (x < y)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        printf("(%d,%d)\n", x, y);
        // CICF
        fprintf(fp, "%d\t", cicf(x, y));
        // Euclids
        fprintf(fp, "%d\t", euclid(x, y));
        // Modified Euclids
        fprintf(fp, "%d\n", modified_euclid(x, y));
    }
    // system("gnuplot > load 'plotfile.txt' ");
    fclose(fp);
}