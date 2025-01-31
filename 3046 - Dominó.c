#include <stdio.h>
 
int main() {
 
    int N, total;
    
    scanf("%d", &N);
    
    if (N < 0 || N > 10000) {
        return 0;
    } else {
        total = ((N+1)*(N+2))/2;
    }
    
    printf("%d\n", total);
 
    return 0;
}