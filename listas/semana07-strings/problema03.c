#include <stdio.h>
#include <string.h>

int main() {
    char nome[11];
    char frequencias[1001];
    int ausencias = 0;
    int total_aulas = 0;
    
    scanf("%10s", nome);

    getchar(); // Limpa buffer do teclado

    fgets(frequencias, 1001, stdin);
    
    // Remove o \n do final se existir na listagem de frequencias
    frequencias[strcspn(frequencias, "\n")] = '\0';
    
    char *token = strtok(frequencias, " ");
    
    while (token != NULL) {

        // Verifica se realmente é uma data mo formato DD/MM
        if (strchr(token, '/') != NULL) {

            total_aulas++;

            // Próximo token deve ser o primeiro aluno desta data
            token = strtok(NULL, " ");

            int presente = 0;
            
            // Verifica todos os alunos até a próxima data ou o fim
            while (token != NULL && strchr(token, '/') == NULL) {

                if (strcmp(token, nome) == 0) {

                    presente = 1;
                }
                token = strtok(NULL, " ");
            }
            
            // Se não encontrou o aluno, conta como uma ausência
            if (!presente) {

                ausencias++;
            }
        } else {
            token = strtok(NULL, " ");
        }
    }
    
    printf("%i\n", ausencias);
    
    return 0;
}