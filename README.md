# Introdução a Técnicas de Programação - Unidade 02

**Aluno**: Síntia Raianne Bezerra de Souza

**Matrícula**: 20250052970

**Período**: 2025.2

## 📂 Estrutura do Projeto
- `listas/`: Soluções das listas de exercícios
- `projeto/`: Projeto principal da unidade
- `relatorios/`: Relatórios de cada unidade
- `videos/`: Link dos videos de demonstração de cada unidade
- `README.md`: Este arquivo
  
## 🏛️ Projeto: Sistema de Gerenciamento de Biblioteca

**Descrição**: Sistema para gerenciar as operações de uma biblioteca, permitindo o cadastro de livros e usuários, listagem dos itens registrados, realização de empréstimos e devoluções, buscar livros no acervo e gerar relatórios de empréstimos por usuários.

**Repositório**: 

**Vídeo de Demonstração**: 

### Funcionalidades Implementadas:
- **Cadastro de Livros**: Permite ao usuário adicionar novos livros ao sistema, informando o título e o autor. O sistema define o status inicial do livro como "Disponível".
- **Listagem de Livros**: Exibe todos os livros cadastrados, mostrando o ID, título, autor e o status atual.
- **Cadastro de Usuários**: Permite o registro de novos usuários, solicitando nome e matrícula. 
- **Listagem de Usuários**: Mostra todos os usuários cadastrados no sistema com seus respectivos IDs, nomes e matrículas.
- **Realização de Empréstimos**: Realiza o empréstimo, verificando a disponibilidade do livro e garantindo que o usuário não tenha ultrapassado o limite permitido de empréstimos ativos.
- **Menu Interativo**: Exibe o menu principal, permitindo que o usuário o selecione a operação desejada.
- **Limpeza de Tela**: Limpa o terminal a cada nova interação no menu, oferecendo uma interface mais organizada e agradável.
- **Devolução de Livros**: Realiza a devolução de livros emprestados, verificando se o usuário realmente possui aquele livro. Além disso, atualiza o status para “Disponível” e libera o espaço no vetor de empréstimos.
- **Busca de Livros**: Permite buscar livros por título, autor ou palavra-chave. A busca ignora maiúsculas/minúsculas (case-insensitive).
- **Relatório de Empréstimos por Usuário**: Gera relatório detalhado, mostrando todos os empréstimos ativos, livros emprestados e saldo disponível por usuário.

  
### Conceitos da U2 Aplicados:
- Estruturas condicionais: Utilizadas para validar opções do menu, verificar disponibilidade de livros, controlar limites de empréstimos e validar IDs de usuários e livros.
- Estruturas de repetição: Implementadas no menu principal, na listagem de livros e usuários, e na busca por posições livres no vetor de empréstimos
- Vetores: Usados para armazenar informações referentes aos livros (título, autor e status), aos usuários (nome e matrícula) e aos empréstimos (associação entre usuário e livro).
- Strings: Utilizadas para armazenar e manipular textos como títulos de livros, nomes de autores e usuários.
- Matrizes: Empregadas para organizar a relação entre usuários e livros emprestados, permitindo registrar múltiplos empréstimos por usuário em uma estrutura bidimensional.
- Ponteiros: Usados para passar referências de variáveis entre funções, permitindo modificação direta dos valores nos vetores de livros, usuários e empréstimos.
- Alocação dinâmica: Implementada ao criar a matriz de relatórios de empréstimos conforme o número de usuários cadastrados.
- Estruturas de repetição aninhadas: Utilizadas para percorrer matrizes durante a contagem de empréstimos, busca por posições livres e geração do relatório de cada usuário.
- Funções: Além da função main(), também estão sendo utilizadas outras sete funções, sendo elas: 
  - `limparTela()` → Limpa o terminal para melhor visualização e experiência
  - `menuBiblioteca()` → Exibe o menu principal de opções
  - `cadastrarLivro()` → Adiciona novos livros ao sistema
  - `listarLivros()` → Mostra todos os livros cadastrados
  - `buscarLivros()` → Busca livros por título, autor ou palavra-chave
  - `cadastrarUsuario()` → Registra novos usuários
  - `listarUsuarios()` → Exibe usuários cadastrados
  - `realizarEmprestimo()` → Controla o processo de empréstimo de livros
  - `realizarDevolucao()` → Gerencia o processo de devolução de livros
  - `relatorioEmprestimoUsuario()` → Gera relatório detalhado dos empréstimos por usuários
  
## 📚 Listas de Exercícios

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-11: Implementações

### Semana 5 - Funções:
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial
  
### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings:
- ✅ Problema 1: 
- ✅ Problema 2: 
- ✅ Problema 3: 

### Semana 8 - Repetições Aninhadas:
- ✅ Problema 1: 
- ✅ Problema 2: 
- ✅ Problema 3: 

### Semana 9 - Matrizes:
- ✅ Problema 1: 
- ✅ Problema 2: 
- ✅ Problema 3: 
- ✅ Problema 4: 

### Semana 10 - Ponteiros e Alocação:
- ✅ Problema 1: 
- ✅ Problema 2: 
- ✅ Problema 3: 


## 🎯 Principais Aprendizados
- Configuração e uso do ambiente de desenvolvimento com GCC
- Declaração e manipulação de variáveis
- Utilização de estruturas condicionais e laços de repetição
- Modularização do código por meio de funções
- Manipulação de strings e arrays multidimensionais
- Tratamento de entrada e saída de dados com printf e scanf
- Implementação de busca textual utilizando case-insensitive
- Manipulação de matrizes 
- Utilização de ponteiros 
- Gerenciamento de alocação dinâmica 
- Utilização de estruturas de repetição aninhadas 


## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão 15.2.0
- **Editor**: Visual Studio Code 
