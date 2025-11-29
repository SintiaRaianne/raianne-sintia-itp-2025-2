#include <stdio.h>

int main() {
    int m, n;
    
    scanf("%i %i", &m, &n);
    
    int sorteados[50];
    int aposta[50];
    
    // verifica os números sorteados
    for (int i = 0; i < m; i++) {
        scanf("%i", &sorteados[i]);
    }
    
    // Verifica os números da aposta
    for (int i = 0; i < n; i++) {
        scanf("%i", &aposta[i]);
    }
    
    // Conta quantos acertos houve
    int acertos = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (sorteados[i] == aposta[j]) {

                acertos++;

                break; 
            }
        }
    }
    
    printf("%i\n", acertos);
    
    return 0;
}