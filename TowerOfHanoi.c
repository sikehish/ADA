#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char temp, int *count) {
    (*count)++;
    if (n == 1) {
        return;
    }
    towerOfHanoi(n-1, source, temp, destination, count);
    towerOfHanoi(n-1, temp, destination, source, count);
}

int main() {
    FILE *best, *worst;
    best = fopen("best_case.txt", "w");
    worst = fopen("worst_case.txt", "w");

    int n, count;
    for (n = 5; n <= 50; n++) {
        count = 0;
        towerOfHanoi(n, 'A', 'C', 'B', &count);
        fprintf(best, "%d\n", count);
        count = 0;
        towerOfHanoi(n, 'C', 'A', 'B', &count);
        fprintf(worst, "%d\n", count);
    }

    fclose(best);
    fclose(worst);
    return 0;
}
