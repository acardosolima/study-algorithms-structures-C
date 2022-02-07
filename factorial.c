#include<stdio.h>

int factorialRecursive(int n){
    if(n < 0)
        return -1;

    if(n == 0){
        return 1;
    }
    else return factorialRecursive(n-1)*n;
}



int main(char* argv[]){
    printf("%d", factorialRecursive(9));
}