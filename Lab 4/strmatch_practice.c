#include <stdio.h>
#include <stdlib.h>

int strMatch(char str[], char pattern[], int n, int m)
{
    int count = 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && str[i + j] == pattern[j])
        {
            j++;
            count++;
        }
        if (j == m)
            return count;
        count++;
    }
    return count;
}

void main()
{

    char str[1000];
    int m = 100, n = 1000;
    char *pattern = NULL;
    int count = 0;

    FILE *fp = fopen("str2.dat", "a");

    for (int i = 0; i < n; i++)
        str[i] = 'a';

    for (int m = 100; m <= n; m += 100)
    {
        pattern = (char *)malloc(m * sizeof(char));

        // Best case:
        for (int i = 0; i < m; i++)
            pattern[i] = 'a';
        count = strMatch(str, pattern, n, m);
        fprintf(fp, "%d\t%d\t", m, count);

        // Worst case:
        pattern[m - 1] = 'b';
        count = strMatch(str, pattern, n, m);
        fprintf(fp, "%d\n", count);

        free(pattern);
    }

    fclose(fp);
}