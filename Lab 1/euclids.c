#include<stdio.h>
#include<stdlib.h>


int euclids(int m , int n){
    int r;
    while(n>0){
        r=m%n;
        m=n;
        n=r;
    }

    return m;
}

