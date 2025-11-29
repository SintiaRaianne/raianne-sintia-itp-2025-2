#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[11];
    scanf("%10s", placa);

    int tamanho = strlen(placa); // Recebe o tamanho da string da placa
    
    // Verificar se esta no padrão brasileiro (LLL-AAAA)
    if (tamanho == 8 && 
        isalpha(placa[0]) && isupper(placa[0]) &&
        isalpha(placa[1]) && isupper(placa[1]) &&
        isalpha(placa[2]) && isupper(placa[2]) &&
        placa[3] == '-' &&
        isdigit(placa[4]) &&
        isdigit(placa[5]) &&
        isdigit(placa[6]) &&
        isdigit(placa[7])) {

        printf("brasileiro\n");
    }
    // Verificar se esta no padrão mercosul (LLLALAA)
    else if (tamanho == 7 &&
        isalpha(placa[0]) && isupper(placa[0]) &&
        isalpha(placa[1]) && isupper(placa[1]) &&
        isalpha(placa[2]) && isupper(placa[2]) &&
        isdigit(placa[3]) &&
        isalpha(placa[4]) && isupper(placa[4]) &&
        isdigit(placa[5]) &&
        isdigit(placa[6])) {

        printf("mercosul\n");
    }
    else {

        printf("invalido\n");
    }
    
    return 0;
}