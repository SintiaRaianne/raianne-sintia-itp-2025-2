#include <stdio.h>
#include <string.h> // Utilizado para manipulacao de strings

int main() {
    char campo[21];
    int id;

    scanf("%20s", campo);
    scanf("%i", &id);

    // Verifica se a posicao indicada possui uma bomba    
    if (campo[id] == 'x'){
        printf("BUM!\n");
    }
    else
    {
        int bombas = 0;

        int tamanho = strlen(campo);

        // Verifica se ha bombas nas posicoes esquerda
        if (id - 1 >= 0 && campo[id - 1] == 'x'){

            bombas++;
        }

        // Verifica se ha bombas nas posicoes direita
        if (id + 1 < tamanho && campo[id + 1] == 'x'){

            bombas++;
        }

        printf("%i\n", bombas); // Exibe a quantidade de bombas encontradas ao redor

    return 0;
    }   
}