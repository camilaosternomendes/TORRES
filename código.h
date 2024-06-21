#ifndef TORRES_DE_HANOI_H
#define TORRES_DE_HANOI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_DISCOS 6

// Define os discos como retângulos
#define DISCO1 "\u2581"
#define DISCO2 "\u2582"
#define DISCO3 "\u2583"
#define DISCO4 "\u2584"
#define DISCO5 "\u2585"
#define DISCO6 "\u2586"

// Define as cores dos discos
#define ANSI_RESET "\x1b[0m"
#define ANSI_VERMELHO "\x1b[38;5;196m"       // vermelho
#define ANSI_LARANJA "\x1b[38;5;208m"        // laranja
#define ANSI_VERDE "\x1b[38;5;118m"          // verde
#define ANSI_AMARELO "\x1b[38;5;227m"        // amarelo
#define ANSI_ROSA "\x1b[38;5;213m"           // rosa
#define ANSI_AZUL "\x1b[38;5;75m"            // azul
#define ANSI_ROXO "\x1b[38;5;141m"           // roxo

// Estrutura para cada torre
typedef struct {
    int discos[MAX_DISCOS];
    int topo;
} Torre;

// Funções
void inicializarTorre(Torre *torre, int numDiscos);
void empilharDisco(Torre *torre, int disco);
int desempilharDisco(Torre *torre);
void mostrarTorres(Torre *A, Torre *B, Torre *C, int numDiscos);
bool moverDisco(Torre *origem, Torre *destino);
void telaDeBoasVindas();

#endif // TORRES_DE_HANOI_H
