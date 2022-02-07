#include<stdio.h>

int sumRecursive(int n){
    if(n == 0)
        return 0;
    else  
        return sumRecursive(n-1)+n;
}

int sumFormula(int n){
    return (n*(n+1))/2;
}

int main(char* argv[]){
    printf("%d\n", sumRecursive(5000));
    printf("%d\n", sumFormula(5000));
}