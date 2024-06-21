# Torres de Hanoi
Este é um projeto para o jogo das Torres de Hanoi implementado em C. 

Ele foi desenvolvido por Camila Mendes Osterno e está hospedado no Replit.

### Arquivos
torres_de_hanoi.h: Contém as definições e declarações das funções e estruturas utilizadas no jogo.

torres_de_hanoi.c: Contém a implementação das funções declaradas no arquivo de cabeçalho.
### Como Compilar e Executar
Requisitos:
GCC (GNU Compiler Collection)
Compilação
Para compilar o projeto, você pode usar o seguinte comando:

sh
Copiar código
gcc torres_de_hanoi.c -o torres_de_hanoi

### Execução
Após a compilação, você pode executar o programa com o comando:

sh
Copiar código
./torres_de_hanoi
### Instruções do Jogo
Digite o número de discos (1 a 6).

Siga as instruções para mover os discos entre as torres.

O objetivo é mover todos os discos da torre A para a torre C seguindo as regras do jogo.
### Estrutura do Código
torres_de_hanoi.h: Contém definições de estruturas e declarações de funções.

torres_de_hanoi.c: Contém a implementação das funções, incluindo a lógica principal do jogo.
### Funções Principais
inicializarTorre: Inicializa uma torre com discos.

empilharDisco: Empilha um disco na torre.

desempilharDisco: Desempilha um disco da torre.

mostrarTorres: Mostra o estado atual das torres.
moverDisco: Move um disco de uma torre para outra.
telaDeBoasVindas: Exibe a tela de boas-vindas.
