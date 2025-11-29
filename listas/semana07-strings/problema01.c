#include <stdio.h>
#include <string.h> // Utilizado para manipulacao de strings

int main() {
    char campo[21];
    int indice;

    scanf("%20s", campo);
    scanf("%d", &indice);

    // Verifica se a posicao indicada possui uma bomba    
    if (campo[indice] == 'x'){
        printf("BUM!\n");
    }
    else
    {
        int bombas = 0;

        // Verifica se ha bombas nas posicoes esquerda
        if (indice - 1 >= 0 && campo[indice - 1] == 'x'){

            bombas++;
        }

        // Verifica se ha bombas nas posicoes direita
        if (indice + 1 < strlen(campo) && campo[indice + 1] == 'x'){

            bombas++;
        }

        printf("%d\n", bombas); // Imprime o numero de bombas nas posicoes 
    }

    return 0;
}