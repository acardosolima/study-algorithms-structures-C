#include<stdio.h>

double factorial(int n){
    if (n <= 1){
        return 1;
    }
    else return factorial(n-1)*n;
}

double ncr(int n, int r){
    //nCr = n! / (r!(n-r)!)
    double numerator = factorial(n);
    double denominator1 = factorial(r);
    double denominator2 = factorial(n-r);

    return numerator / (denominator1*denominator2);
}

double ncrRecursive(int n, int r){
    if(r ==0 || n == r){//first and last columns are always 1
        return 1;
    }
    else return ncrRecursive(n-1, r-1)+ncrRecursive(n-1, r);
}

int main(char* argv[]){
    printf("%0.f\n", ncr(11, 2));
    printf("%0.f\n", ncrRecursive(11, 2));
}