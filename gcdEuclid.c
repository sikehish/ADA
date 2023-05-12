//gcd.c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int euclid(int a,int b)
{
	int r=0,ct=0;
	while(b>0)	
	{
		ct++;
		r=a%b;
		a=b;
		b=r;
	}
	return ct;
}
int consint(int a,int b)
{
	int i,ct=0;
	if(a==0 && b!=0) return b;
	if(b==0 && a!=0) return a;
	if(a==0 && b==0) return -1;
	for(i=(a>b)?b:a;i>=1;i--)
	{
		ct++;
		if(a%i==0 && b%i==0) return ct;
	}
	return ct;
}
long *fibogen(long *a,int n)
{
	int i=0;
	a[0]=0,a[1]=1;
	for(i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a;
}
void main()
{
	int c,i=2;
	long *a;
	FILE  *fp,*fp1;
	a=malloc(sizeof(long)*100);
	fp=fopen("euclid.dat","a");
	fp1=fopen("consint_time.txt","a");
	while(i<50)
	{
		a=fibogen(a,i);
		c=euclid(a[i-1],a[i-2]);
		printf("for numbers: %ld\t%ld\t euclid count: %d\t for i: %d\n",a[i-1],a[i-2],c,i);
          fprintf(fp,"%d\t%d\n",(int)(log(a[i-1])+1),c);
		c=consint(a[i-1],a[i-2]);
		printf("for numbers: %ld\t%ld\t consint count: %d\t for i: %d\n",a[i-1],a[i-2],c,i);
          fprintf(fp1,"%d\t%d\n",(int)(log(a[i-1]])+1),c);
		if(i>=30)
		{
			i=i+2;
		}
		else
		{
			i=i+8;
		}
	}
	fclose(fp);
     fclose(fp1);
}

//gcdplot.txt
set title 'GCD Plot'
set xrange [0:25]
set yrange [0:100]
set xlabel 'Input'
set ylabel 'Count'
set style data linespoints
plot 'euclid_time.txt' u 1:2 w lp,'consint_time.txt' u 1:2 w lp


//euclid.dat
1	0
3	7
3	15
4	23
4	31
4	33
4	35
4	37
4	39
4	41
4	43


