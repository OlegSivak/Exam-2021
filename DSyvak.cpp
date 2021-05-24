#include <stdio.h>
#include <algorithm>
using namespace std; 
int A[50];
void B(int b, int max, int n){ 
    int i; 
    if (!n){ 
        printf("%d", A[0]); 
        for (i = 1; i < b; i++) printf(" %d",A[i]); 
        printf("\n"); 
    } 
    else for (i = 1; i <= min(max,n); i++){ 
        A[b] = i; 
        B(b+1,i,n-i); 
        } 
}
int main(){ 
    int c; 
    scanf("%d",&c); 
    B(0,c,c);
}