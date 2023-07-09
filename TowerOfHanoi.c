#include <stdio.h>

void towerOfHanoi(int n, char source, char temp, char dest, int *count) {
    (*count)++;
    if (n == 1) return;
    towerOfHanoi(n-1, source, temp, dest, count);
    towerOfHanoi(n-1, temp, dest, source, count);
}

int main() {
    FILE* file;
    file = fopen("timing.dat", "a");

    int n, count;
    for (n = 1; n <= 10; n++) {
        count = 0;
        towerOfHanoi(n, 'A', 'B', 'C', &count);
        fprintf(file,"%d\t%d\n",n, count);
    }

    fclose(file);
    return 0;
}

//timing.dat
1	1
2	3
3	7
4	15
5	31
6	63
7	127
8	255
9	511
10	1023

//plotfile.txt
 set title "Tower of Hanoi"
set xrange [0:10]
set yrange [0:1000]
set xlabel 'Number of Disks(n)'
set ylabel 'Number of Calls'
set style data linespoints
plot 'timing.dat'

