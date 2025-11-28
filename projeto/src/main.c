#include <stdio.h>
#include <string.h> // Utilizado para manipulacao de strings
#include <stdlib.h> // Utilizado para limpar a tela
#include <ctype.h>  // Utilizado para conveter caracteres para minusculo

// Constantes para definir limite (livros)
#define maximo_livros 5
#define maximo_titulo 100
#define maximo_autor 50
#define maximo_busca 100
#define maximo_status 15

// Constantes para definir limite (usuarios)
#define maximo_usuarios 5
#define maximo_nome 50

// Constantes para definir limite (emprestimos)
#define maximo_emprestimos 3


// Vetores e variaveis globais para os livros
char titulo_livro[maximo_livros][maximo_titulo];        // Armazena os titulos dos livros
char autor_livro[maximo_livros][maximo_autor];          // Armazena os autores dos livros
int disponivel_livro[maximo_livros];                    // Disponivel = 1 e Emprestado = 0
char status_livro[maximo_status];                       // Armazena o status do livro para exibicao
int numero_livros = 0;                                  // Contador de livros cadastrados

// Vetores e variaveis globais para os usuários
char nome_usuario[maximo_usuarios][maximo_nome];        // Armazena os nomes dos usuarios
int matricula_usuario[maximo_usuarios];                 // Armazena as matriculas dos usuarios
int numero_usuarios = 0;                                // Contador de usuarios cadastrados

// Vetores e variaveis globais para os emprestimos
int numero_emprestimo_usuario[maximo_usuarios];                    // Conta livros por usuario
int emprestimos_usuario[maximo_usuarios][maximo_emprestimos];      // Livros emprestados por usuario


// Limpa o terminal/console para uma visualizacao mais organizada
void limparTela() {                                     
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux ou Mac
    #endif
}

void menuBiblioteca() {
    printf("///////// SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ////////\n");

    printf("\n1. Cadastrar Livros\n");
    printf("2. Listar Livros\n");
    printf("3. Cadastrar Usuario\n");
    printf("4. Listar Usuarios\n");
    printf("5. Emprestimo de Livros\n");
    printf("6. Devolucao de Livros\n");
    printf("7. Buscar Livro\n");
    printf("8. Relatorio de Emprestimos\n");
    printf("0. Sair\n");
}

void cadastrarLivro(){

    // Verifica se a quantidade maxima de livros foi atingida ou nao
    if (numero_livros < maximo_livros){ 
        printf("\n================= CADASTRAR NOVO LIVRO ====================\n");

        printf("\nTitulo: ");
        scanf(" %[^\n]",titulo_livro[numero_livros]);

        printf("Autor: ");
        scanf(" %[^\n]",autor_livro[numero_livros]);

        getchar(); // Limpa buffer do teclado

        disponivel_livro[numero_livros] = 1; // Configura o livro cadastrado como disponível
        numero_livros++; // Incrementa o contador de livros

        printf("\nLivro cadastrado com sucesso!\n");
        printf("ID Livro: %i", numero_livros);
    }
    else {
        printf("\nErro. Limite de livro(s) atingindo!\n");
        printf("Nao e possivel cadastrar mais livros.\n");
        return;
    }
}

void listarLivros(){

    // Verifica se algum livro foi cadastrado para listar ou nao
    if (numero_livros > 0){ 
        printf("\n================= LISTAGEM DE LIVROS ====================\n");

        for (int i = 0; i < numero_livros; i++){
            if (disponivel_livro[i] == 1){  // Verifica se o livro esta disponivel ou nao
                strcpy(status_livro, "Disponivel");
            }
            else {
                strcpy(status_livro, "Emprestado");
            }
            
            printf("\nID: %i | Titulo: %s | Autor: %s | Status: %s\n", i + 1, titulo_livro[i], autor_livro[i], status_livro);
        }
    }
    else {
        printf("\nNao existem livros cadastrados no sistema.\n");
    }
}

void buscarLivros(){
    char busca[maximo_busca];
    char titulo_minusculo[maximo_titulo];
    char autor_minusculo[maximo_autor];

    int encontrado = 0;

    // Verifica se algum livro foi cadastrado para buscar ou nao
    if (numero_livros > 0){

    printf("\n=================== BUSCAR LIVROS ====================\n");

    printf("\nDigite autor, titulo ou palavra-chave: ");
    scanf(" %[^\n]", busca);

    getchar(); // Limpa buffer do teclado

    for (int i = 0; i < busca[i]; i++){    // Converte a palavra de busca para letras minúsculas
        busca[i] = tolower(busca[i]);
    }
        
    printf("\nBuscando por: '%s'\n", busca);

    for (int i = 0; i < numero_livros; i ++){

        int j, k;

        for (j = 0; titulo_livro[i][j]; j++){  // Converte o titulo do livro para letras minúsculas
            titulo_minusculo[j] = tolower(titulo_livro[i][j]);
        }

        titulo_minusculo[j] = '\0';  // Adiciona caractere nulo ao final da string

        for (k = 0; autor_livro[i][k]; k++){   // Converte o autor do livro para letras minúsculas
            autor_minusculo[k] = tolower(autor_livro[i][k]);
        }

        autor_minusculo[k] = '\0';  // Adiciona caractere nulo ao final da string 

        // Verifica se a palavra de busca corresponde ao titulo ou autor
        if (strstr(titulo_minusculo, busca) != NULL || strstr(autor_minusculo, busca) != NULL){ 
            
            if (disponivel_livro[i] == 1){  // Verifica se o livro esta disponivel ou nao
                strcpy(status_livro, "Disponivel");
            }
            else {
                strcpy(status_livro, "Emprestado");
            }

            printf("\nID: %i\n", i+1);
            printf("Titulo: %s\n", titulo_livro[i]);
            printf("Autor:  %s\n", autor_livro[i]);
            printf("Status: %s\n", status_livro);

            encontrado++;  // Incrementa contador de livros encontrados
        }
    }

    if (encontrado == 0) {
        printf("\nNenhum livro encontrado! Verifique a ortografia\n");
    } 
    else {
        printf("\nTotal de livros encontrados: %d livro(s)\n", encontrado);
    }
}

    else {
        printf("\nNao existem livros cadastrados no sistema.\n");
    }
}

void cadastrarUsuario(){

    // Verifica se a quantidade maxima de usuarios foi atingida ou nao
    if (numero_usuarios < maximo_usuarios){ 
        printf("\n================= CADASTRAR NOVO USUARIO ====================\n");

        printf("\nNome: ");
        scanf(" %[^\n]",nome_usuario[numero_usuarios]);

        printf("Matricula (apenas numeros): ");
        scanf("%i",&matricula_usuario[numero_usuarios]);

        getchar(); // Limpa buffer do teclado

        // Inicia o vetor de emprestimos do usuario vazio
        for (int i = 0; i < maximo_emprestimos; i ++){
            emprestimos_usuario[numero_usuarios][i] = -1;
        }

        // O usuario ao ser cadastrado inicia com 0 livros
        numero_emprestimo_usuario[numero_usuarios] = 0;

        numero_usuarios++; // Incrementa o contador de usuario
        
        printf("\nUsuario cadastrado com sucesso!\n");
        printf("ID Usuario: %i", numero_usuarios);
    }
    else {
        printf("\nErro. Limite de usuarios atingindo!\n");
        printf("Nao e possivel cadastrar mais usuarios.\n");
        return;
    }
}

void listarUsuarios(){

    // Verifica se algum usuario foi cadastrado para listar  ou nao
    if (numero_usuarios > 0){ 
        printf("\n================= LISTAGEM DE USUARIOS ====================\n");

        for (int i = 0; i < numero_usuarios; i++){
            
            printf("\nID: %i | Nome: %s | Matricula: %i\n", i + 1, nome_usuario[i], matricula_usuario[i]);
        }
    }
    else {
        printf("\nNao existem usuarios cadastrados no sistema.\n");
    }
}

void realizarEmprestimo(){
    int id_livro_emprestimo, id_usuario_emprestimo;

    printf("\n================= EMPRESTIMO DE LIVRO ====================\n");

    // Verifica se existe livros e/ou usuarios cadastrados ou nao
    if (numero_livros == 0 && numero_usuarios == 0) {
        printf("\nNenhum livro e usuario cadastrados!\n");
        printf("Voce precisa cadastrar livros e usuarios primeiro, para realizar emprestimos.\n");
        return;
    }
    if (numero_livros == 0) {
        printf("\nNenhum livro cadastrado!\n");
        return;
    }
    if (numero_usuarios == 0) {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    printf("\nID do livro do emprestimo: ");
    scanf("%i", &id_livro_emprestimo);

    getchar(); // Limpa buffer do teclado

    // Verifica se os IDs informados sao validos
    if (id_livro_emprestimo < 1 || id_livro_emprestimo > numero_livros){
        printf("\nID de livro invalido!\n");
        printf("ID dos livros existentes: 1 ate %i\n", numero_livros);
        return;
    }

    printf("ID do usuario do emprestimo: ");
    scanf("%i", &id_usuario_emprestimo);

    getchar(); // Limpa buffer do teclado

    if (id_usuario_emprestimo < 1 || id_usuario_emprestimo > numero_usuarios){
        printf("\nID de usuario invalido!\n");
        printf("ID dos usuarios existentes: 1 ate %i\n", numero_usuarios);
        return;
    }

    // Ajusta os indices. O usuario digita 1, mas, no vetor seria 0
    id_livro_emprestimo--;
    id_usuario_emprestimo--;

    // Verifica se usuario atingiu limite de emprestimos
    if (numero_emprestimo_usuario[id_usuario_emprestimo] >= maximo_emprestimos){
        printf("\nUsuario ja tem %i livros emprestados. O limite eh de %i por usuario", numero_emprestimo_usuario[id_usuario_emprestimo], maximo_emprestimos);
        return;
    }

    // Verifica se o livro esta disponivel
    if (disponivel_livro[id_livro_emprestimo] == 0){
        printf("\nLivro ja esta emprestado! Escolha outro livro.");
        return;
    }

    // Procura posicao livre no vetor de emprestimos do usuario para alocar o livro
    for (int i = 0; i < maximo_emprestimos; i++){
        if (emprestimos_usuario[id_usuario_emprestimo][i] == -1){
            emprestimos_usuario[id_usuario_emprestimo][i] = id_livro_emprestimo;  // Coloca o ID do livro na posicao livre
            numero_emprestimo_usuario[id_usuario_emprestimo]++; // Incrementa o contador de emprestimos do usuario

            disponivel_livro[id_livro_emprestimo] = 0; // Coloca livro como emprestado

            printf("\nEmprestimo cadastrado com sucesso!\n");

            printf("\nInformacoes do emprestimo realizado:\n");
            printf("Livro: %s\n", titulo_livro[id_livro_emprestimo]);
            printf("Usuario: %s\n", nome_usuario[id_usuario_emprestimo]);
            break;
        }
    }
 }

 void realizarDevolucao(int* id_livro_dev, int* id_usuario_dev){
    int id_livro_devolucao, id_usuario_devolucao;

    printf("\n================= DEVOLUCAO DE LIVRO ====================\n");

    // Verifica se existe livros e/ou usuarios cadastrados ou nao
    if (numero_livros == 0 && numero_usuarios == 0) {
        printf("\nNenhum livro e usuario cadastrados!\n");
        printf("Voce precisa cadastrar livros e usuarios primeiro, para realizar emprestimos.\n");
        return;
    }
    if (numero_livros == 0) {
        printf("\nNenhum livro cadastrado!\n");
        return;
    }
    if (numero_usuarios == 0) {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    printf("\nID do livro do emprestimo: ");
    scanf("%i", &id_livro_devolucao);

    getchar(); // Limpa buffer do teclado

    // Verifica se os IDs informados sao validos
    if (id_livro_devolucao < 1 || id_livro_devolucao > numero_livros){
        printf("\nID de livro invalido!\n");
        printf("ID dos livros existentes: 1 ate %i\n", numero_livros);
        return;
    }

    printf("ID do usuario do emprestimo: ");
    scanf("%i", &id_usuario_devolucao);

    getchar(); // Limpa buffer do teclado

    if (id_usuario_devolucao < 1 || id_usuario_devolucao > numero_usuarios){
        printf("\nID de usuario invalido!\n");
        printf("ID dos usuarios existentes: 1 ate %i\n", numero_usuarios);
        return;
    }

    // Ajusta os indices. O usuario digita 1, mas, no vetor seria 0
    *id_livro_dev = id_livro_devolucao - 1;
    *id_usuario_dev = id_usuario_devolucao - 1;
     
    int posicao = -1;

    // Verifica se o livro esta emprestado para o usuario
    for (int i = 0; i < maximo_emprestimos; i++){
        if (emprestimos_usuario[*id_usuario_dev][i] == *id_livro_dev){
            posicao = i;
            break;
        }
    }
    if (posicao != -1){
        emprestimos_usuario[*id_usuario_dev][posicao] = -1;  // Remove o ID do livro do vetor de emprestimos do usuario
        numero_emprestimo_usuario[id_usuario_devolucao]--;   // Decrementa o contador de emprestimos do usuario

        disponivel_livro[*id_livro_dev] = 1;           // Coloca livro como disponivel

        printf("\nDevolucao cadastrada com sucesso!\n");

        printf("\nInformacoes da devolucao realizada:\n");
        printf("Livro: %s\n", titulo_livro[*id_livro_dev]);
        printf("Usuario: %s\n", nome_usuario[*id_usuario_dev]);
    }
    else {
        printf("\nO usuario nao possui esse livro emprestado!\n");
    }
 }

 void relatorioEmprestimoUsuario() {
    
    printf("\n=============== RELATORIO DE EMPRESTIMOS POR USUARIOS ==================\n");
    
    // Verifica se existe livros e/ou usuarios cadastrados ou nao
    if (numero_livros == 0 && numero_usuarios == 0) {
        printf("\nNenhum livro e usuario cadastrados!\n");
        printf("Voce precisa cadastrar livros e usuarios primeiro, para realizar emprestimos.\n");
        return;
    }
    if (numero_livros == 0) {
        printf("\nNenhum livro cadastrado!\n");
        return;
    }
    if (numero_usuarios == 0) {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    // Ponteiro para matriz dinamica
    int** relatorio = (int**)malloc(numero_usuarios * sizeof(int*));

    // Cria matriz que se adapta ao numero de usuarios
    for (int i = 0; i < numero_usuarios; i++) {
        relatorio[i] = (int*)malloc(2 * sizeof(int));
    }

    // Conta emprestimos ativos por usuario
    for (int i = 0; i < numero_usuarios; i++){
        int emprestimos_ativos = 0;

        for (int j = 0; j < maximo_emprestimos; j++){
            if (emprestimos_usuario[i][j] != -1){

                emprestimos_ativos++;
            }
        }

        relatorio[i][0] = emprestimos_ativos;    // Total de emprestimos ativos
        relatorio[i][1] = (maximo_emprestimos - emprestimos_ativos);   // Saldo de emprestimos disponiveis  }
    }

    for (int i = 0; i < numero_usuarios; i++) {
        printf("\n------------------------------------------------------------------------\n");

        printf("\nID: %i | Usuario: %s | Emprestimos Ativos: %i | Saldo Disponivel: %i\n", i + 1, nome_usuario[i], relatorio[i][0], relatorio[i][1]);  

        if (relatorio[i][0] > 0){
            printf("\nLivros emprestados:\n\n");

            for (int j = 0; j < maximo_emprestimos; j++){
                if (emprestimos_usuario[i][j] != - 1){
                    
                    int livro_id = emprestimos_usuario[i][j];

                     printf("ID: %i - Titulo: %s\n", livro_id + 1, titulo_livro[livro_id]);
                }
            }
        }
        else {
            printf("\nLivros emprestados: 0\n");
        }
    }

    // Libera a memoria alocada dinamicamente
    for (int i = 0; i < numero_usuarios; i++) {
        free(relatorio[i]);
    }

    free(relatorio);
}

int main() {
    int opcao;
    int id_livro, id_usuario;

    do {

        // Limpa terminal para exibir novamente
        limparTela();

        // Chama o menu biblioteca
        menuBiblioteca();

        printf("\nSelecione a opcao que deseja: ");
        scanf("%i", &opcao);
        getchar(); // Limpa buffer depois de ler a opcao

        // Limpa terminal antes de exibir a opcao escolhida
        limparTela(); 

        // Executa a funcao correspondente a opcao escolhida
        switch (opcao){
            case 1:
                cadastrarLivro();
                break;

            case 2:
                listarLivros();
                break;

            case 3:
                cadastrarUsuario();
                break;

            case 4:
                listarUsuarios();
                break;

            case 5:
                realizarEmprestimo();
                break;

            case 6:
                realizarDevolucao(&id_livro, &id_usuario);
                break;
                
            case 7:
                buscarLivros();
                break;
            
            case 8:
                relatorioEmprestimoUsuario();
                break;

            case 0:
                printf("\nSaindo do sistema...\n\n");
                break;

            default: 
                printf("Opcao Invalida! Tente Novamente.\n"); // Caso o usuario insira uma opcao diferentea das disponiveis no switch
        }

        // Pausa para usuario visualizar resultados antes de voltar ao menu
        if (opcao != 0) {
            printf("\n\nPressione Enter para voltar ao Menu.....");
            getchar(); // Espera o usuário pressionar Enter
        }

    // Repete até usuário escolher sair
    } while (opcao != 0);
    
    return 0;
}
