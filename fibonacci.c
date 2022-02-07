#include<stdio.h>
#include <stdlib.h>

double fibonacci(int n){
    //O(2^n) approximately
    if(n <= 1){
        return n;
    }
    else return fibonacci(n-2) + fibonacci(n-1);
}

double fibonacciMemoization(int n){
    double* values = (double *)malloc(n * sizeof(double));

    for(int i = 0; i < n; i++)
        values[i] = -1;

    if (n <= 1){
        values[n] = n;
        return n;
    }
    else{
        if(values[n-2] == -1)
            values[n-2] = fibonacciMemoization(n-2);

        if(values[n-1] == -1)
            values[n-1] = fibonacciMemoization(n-1);

        return values[n-2] + values[n-1];
    }
}

double fibonacciIterative(int n){
    double t0=0, t1=1, s=0;

    if(n <= 1){
        return n;
    }

    for (int i = 2; i <= n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int main(char* argv[]){
    //printf("%f\n", fibonacci(50));
    printf("%f\n", fibonacciIterative(30));
    printf("%f\n", fibonacciMemoization(30));
}