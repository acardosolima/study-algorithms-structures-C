#include<stdio.h>

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else return factorial(n-1)*n;
}

int power(int n, int x){
    if(x == 0){
        return 1;
    }
    else return power(n, x-1)*n;
}

int sumSequence(int n){
    if(n == 0){
        return 0;
    }
    else return sumSequence(n-1)+n;
}

int eTaylorSeries(int x, int n){
    // e^x, with n terms
    if(n == 0){
        return 1;
    }
    else return sumSequence(power(x, n-1)/factorial(n-1));
}

float eTaylorIterative(int x, int n){
    int power = 1;
    int fact = 0;
    double value = 1;
    for (int i = 1; i <= n; i++){
        power *= x;
        fact = factorial(i);
        value += (float)power/fact;
    }

    return value;
}

float e(int x, int n){
    static int p=1, f=1;
    float r;

    if(n == 0)
        return 1;
    else{
        r = e(x, n-1);
        p = p*x;
        f = f*n;
        return r + (float)p/f;
    }
}

int eOptimized(int x, int n){
    static int s = 1;

    if(n == 0){
        return s;
    }
    else{
        s = 1 + x/n * s;
        return eOptimized(x, n-1);
    }
}

int main(char* argv[]){
    printf("%f\n", eTaylorIterative(1, 10));
    printf("%f\n", eTaylorSeries(1, 10));
    printf("%f\n", e(1, 10));
    printf("%f\n", eOptimized(1, 10));
}