
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void bubbleSort(int* arr, int size)
{
for (int i = 0; i < size - 1; i++) {
      
    for (int j = 0; j < size - i - 1; j++) {
      
      if (arr[j] > arr[j + 1]) {

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}



int binarySearch(int array[], int x, int low, int high) {
int count=0;
  while (low <= high) {
    int mid = (high + low) / 2;
	count++;
 if(array[mid] == x)
      return count;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }
	if(!count) count++;

  return count;
}

void main()
{
	int size=0, key=0;
	srand(time(NULL));
	FILE* fptr;
	printf("Enter the size of the array\n");
	scanf("%d", &size);
	if(size<=0) {
		printf("Invalid size\n");
		exit(1);
	}	 
		int *arr=(int *)malloc(sizeof(int)*size);
//printf("Enter the elements to be inserted: ");
	for(int i=0; i<size; i++){
	arr[i]=rand();
}
//printf("Enter the key to be searched\n");
//	scanf("%d",&key);

fptr = fopen("timing.dat","a");
 if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


bubbleSort(arr,size);
/*printf("ELEMENTS: ");
for(int i=0; i<size; i++) printf("%d ", arr[i]);
printf("\n")*/
	
//WORST CASE
clock_t t;
 t = clock();
int counts=binarySearch(arr, arr[size-1],0, size-1);
double duration=((double)t)/CLOCKS_PER_SEC;
duration*=1000;
printf("WORST CASE: Binary search took %f milli-seconds to execute\n", duration);
printf("WORST CASE: Binary search took %d counts to execute\n", counts);
fprintf(fptr,"%d\t%d\t",size, counts);


//AVG CASE

t = clock();
 counts=binarySearch(arr, arr[rand()%(size-1)],0, size-1);
 duration=((double)t)/CLOCKS_PER_SEC;
duration*=1000;
printf("AVG CASE: Binary search took %f milli-seconds to execute\n", duration);
printf("AVG CASE: Binary search took %d counts to execute\n", counts);
fprintf(fptr,"%d\t%d\t",size, counts);


//BESTCASE CASE
 t = clock();
counts=binarySearch(arr, arr[(size-1)/2],0, size-1);
duration=((double)t)/CLOCKS_PER_SEC;
duration*=1000;
printf("BEST CASE: Binary search took %f milli-seconds to execute\n", duration);
printf("BEST CASE: Binary search took %d counts to execute\n", counts);
fprintf(fptr,"%d\t%d\n",size, counts);



fclose(fptr);

}

//plotfile.txt
set title "Binary Search"
set xrange [1000:40000]
set yrange [1: 30]
set xlabel 'Number of elements(n)'
set ylabel 'Count(Number of operations)'
set style data linespoints
plot 'timing.dat' u 1:2 w l, 'timing.dat' u 3:4 w l,  'timing.dat' u 5:6 w l


// timing.dat

1000	10	1000	7	1000	1
2000	11	2000	11	2000	1
5000	13	5000	13	5000	1
10000	14	10000	5	10000	1
20000	15	20000	15	20000	1
30000	15	30000	14	30000	1
40000	16	40000	16	40000	1
