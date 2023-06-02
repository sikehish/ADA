#include<stdio.h>
#include<stdlib.h>

int count=0;

void merge(int arr[], int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],M[n2];
for(int i=0;i<n1; i++) L[i]=arr[p+i];
for(int j=0; j<n2; j++) M[j]=arr[q+1+j];

int i=0, j=0, k=p;

while(i<n1 && j<n2)
{
count++;
if(L[i]<=M[j]){
arr[k]=L[i]; i++;
}
else {
arr[k]== M[j];
j++;
}
k++;
}
while(i<n1){
arr[k]=L[i];i++; k++;
}

while(j<n2){
arr[k]=M[j]; j++; k++;
}
}

void mergeSort(int arr[], int l, int r){
if(l<r){
int m=(l+r)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}}

int join(int arr[], int left[], int right[],int l, int m, int r)
{
int i;
for(i=0; i<=m-l; i++) arr[i]=left[i];
for(int j=0; j<r-m; j++) arr[i+j]= right[j];
}

int split(int arr[], int left[], int right[], int l, int m, int r)
{
for(int i=0; i<=m-l; i++ ) left[i]=arr[i*2];
for(int i=0; i<r-m; i++) right[i]=arr[i*2+1];
}

int generateWorstCase(int arr[], int l, int r)
{
if(l<r){
int m=l+(r-l)/2;
int left[m-l+1];
int right[r-m];
split(arr, left, right, l, m, r);
generateWorstCase(left, l, m);
generateWorstCase(right, m+1, r);
join(arr, left, right, l, m, r);
}
}

int main(){
int* arr,i, n=4;
FILE *fp;
fp=fopen("MergeSortTime.txt","a");
while(n<=4096)
{
count=0;
 n*=2;
arr=(int *)malloc(n*sizeof(int));
for(i=0;i<n; i++) arr[i]=i+1;
mergeSort(arr, 0, n-1);
fprintf(fp,"%d\t%d\t",n,count);
count=0;
generateWorstCase(arr,0,n-1);
mergeSort(arr,0,n-1);
fprintf(fp,"%d\n",count);
free(arr);

}
fclose(fp); 
	system("gnuplot > load 'msplot.txt' ");
	return 0;
}

---------
cat ../hisham/mergeSort/msplot.txt
set title 'Merge Plot'
set xrange [8:9000]
set yrange [10:100000]
set xlabel 'Input'
set ylabel 'Count'
set style data linespoints
plot 'MergeSortTime.txt' u 1:2 w lp,'MergeSortTime.txt' u 1:3 w lp

pause -1 "Hit any Key to Continue"
----------cat ../hisham/mergeSort/MergeSortTime.txt
8	12	17
16	32	49
32	80	129
64	192	321
128	448	769
256	1024	1793
512	2304	4097
1024	5120	9217
2048	11264	20481
4096	24576	45057
8192	53248	98305


