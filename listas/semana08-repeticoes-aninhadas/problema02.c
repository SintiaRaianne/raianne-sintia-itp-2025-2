#include <stdio.h>

int main() {
    char *meses[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    int chuva[12];
    
    // Verifica os valores de chuva para cada mês
    for (int i = 0; i < 12; i++) {
        scanf("%i", &chuva[i]);
    }
    
    // Ordenar do maior para o menor
    for (int i = 0; i < 11; i++) {

        int maior = i;

        for (int j = i + 1; j < 12; j++) {

            if (chuva[j] > chuva[maior]) {

                maior = j;
            }
        }
        
        // Altera os valores de chuva para o maior
        int temp_chuva = chuva[i];
        chuva[i] = chuva[maior];
        chuva[maior] = temp_chuva;
        
        // Aletra os nomes dos meses correspondentes para o maior
        char *temp_mes = meses[i];
        meses[i] = meses[maior];
        meses[maior] = temp_mes;
    }
    
    for (int i = 0; i < 12; i++) {
        printf("%s %i\n", meses[i], chuva[i]);
    }
    
    return 0;
}