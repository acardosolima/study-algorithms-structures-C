#include<stdio.h>

int powerRecursive(int n, int x){
    if(x == 0){
        return 1;
    }
    else return powerRecursive(n, x-1)*n;
}

int powerRecursiveOptimized(int n, int x){
    if(x == 0){
        return 1;
    }
    
    if(x%2 == 0){
        return powerRecursiveOptimized(n*n, x/2);
    }
    else return powerRecursiveOptimized(n*n, (x-1)/2)*n;
}

int powerIterative(int n, int x){
    int pow = 1;
    for (int i=0; i<x; i++){
        pow *= n;
    }

    return pow;
}

int main(char* argv[]){
    printf("%d\n", powerRecursive(13,6));
    printf("%d\n", powerRecursiveOptimized(13,6));
    printf("%d\n", powerIterative(13,6));
}