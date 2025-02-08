#include <stdio.h>
 
int main() {
 
    int ano, mes, dia, resto;
    
    scanf("%d", &dia);
    
    ano = dia / 365;
    resto = dia % 365;
    mes = resto / 30;
    resto = resto % 30;
    
    printf("%d ano(s)\n", ano);
    printf("%d mes(es)\n", mes);
    printf("%d dia(s)\n", resto);

    return 0;
}