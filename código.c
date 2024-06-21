#include "torres_de_hanoi.h"

void inicializarTorre(Torre *torre, int numDiscos) {
    torre->topo = -1;
    for (int i = 0; i < numDiscos; i++) {
        torre->discos[i] = numDiscos - i;
        torre->topo++;
    }
}

void empilharDisco(Torre *torre, int disco) {
    torre->discos[++torre->topo] = disco;
}

int desempilharDisco(Torre *torre) {
    return torre->discos[torre->topo--];
}

void mostrarTorres(Torre *A, Torre *B, Torre *C, int numDiscos) {
    system("clear"); // Limpa a tela (no Windows, use "cls")

    printf("\n");

    // Mostra os discos de cima para baixo
    for (int i = numDiscos - 1; i >= 0; i--) {
        // Torre A
        printf("\t");
        if (i <= A->topo) {
            switch (A->discos[i]) {
                case 1: printf(ANSI_VERMELHO DISCO1 ANSI_RESET); break;
                case 2: printf(ANSI_LARANJA DISCO2 ANSI_RESET); break;
                case 3: printf(ANSI_VERDE DISCO3 ANSI_RESET); break;
                case 4: printf(ANSI_AMARELO DISCO4 ANSI_RESET); break;
                case 5: printf(ANSI_ROSA DISCO5 ANSI_RESET); break;
                case 6: printf(ANSI_AZUL DISCO6 ANSI_RESET); break;
            }
        } else {
            printf("|");
        }

        // Torre B
        printf("\t");
        if (i <= B->topo) {
            switch (B->discos[i]) {
                case 1: printf(ANSI_VERMELHO DISCO1 ANSI_RESET); break;
                case 2: printf(ANSI_LARANJA DISCO2 ANSI_RESET); break;
                case 3: printf(ANSI_VERDE DISCO3 ANSI_RESET); break;
                case 4: printf(ANSI_AMARELO DISCO4 ANSI_RESET); break;
                case 5: printf(ANSI_ROSA DISCO5 ANSI_RESET); break;
                case 6: printf(ANSI_AZUL DISCO6 ANSI_RESET); break;
            }
        } else {
            printf("|");
        }

        // Torre C
        printf("\t");
        if (i <= C->topo) {
            switch (C->discos[i]) {
                case 1: printf(ANSI_VERMELHO DISCO1 ANSI_RESET); break;
                case 2: printf(ANSI_LARANJA DISCO2 ANSI_RESET); break;
                case 3: printf(ANSI_VERDE DISCO3 ANSI_RESET); break;
                case 4: printf(ANSI_AMARELO DISCO4 ANSI_RESET); break;
                case 5: printf(ANSI_ROSA DISCO5 ANSI_RESET); break;
                case 6: printf(ANSI_AZUL DISCO6 ANSI_RESET); break;
            }
        } else {
            printf("|");
        }

        printf("\n");
    }

    // Base das torres
    printf("\t|\t|\t|\n");
    printf("\t\u2570\u2500\u2500\u2500\u256C\u2500\u2500\u2500\u256C\u2500\u2500\u2500\u256F\n\n");
}

bool moverDisco(Torre *origem, Torre *destino) {
    if (origem->topo == -1) {
        printf("Torre vazia! Movimento inválido.\n");
        return false;
    } else if (destino->topo != -1 && origem->discos[origem->topo] > destino->discos[destino->topo]) {
        printf("Movimento inválido! Disco maior sobre menor.\n");
        return false;
    } else {
        int disco = desempilharDisco(origem);
        empilharDisco(destino, disco);
        return true;
    }
}

void telaDeBoasVindas() {
    printf("\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*  \x1b[38;5;196mBem-vindo ao jogo das Torres de Hanoi!\x1b[0m  *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*       \x1b[38;5;208mUm jogo de lógica e estratégia\x1b[0m       *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*      \x1b[38;5;118mPressione ENTER para iniciar\x1b[0m       *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");

    // Aguarda o usuário pressionar Enter
    while (getchar() != '\n');
}

int main() {
    bool jogoAtivo = true;

    while (jogoAtivo) {
        system("clear");
        telaDeBoasVindas();

        // Solicitação do número de discos
        int numDiscos;
        printf("\nDigite o número de discos (1 a %d): ", MAX_DISCOS);
        scanf("%d", &numDiscos);

        if (numDiscos < 1 || numDiscos > MAX_DISCOS) {
            printf("Número de discos inválido! Tente novamente.\n");
            continue;
        }

        // Inicialização das torres
        Torre A, B, C;
        inicializarTorre(&A, numDiscos);
        inicializarTorre(&B, 0);
        inicializarTorre(&C, 0);

        // Mostra as torres inicialmente
        mostrarTorres(&A, &B, &C, numDiscos);

        // Jogo manual das Torres de Hanoi
        char origemInput[10], destinoInput[10];
        while (C.topo != numDiscos - 1) {
            printf("Digite a torre de origem (1, 2, 3 ou 'F' para finalizar): ");
            scanf("%s", origemInput);
            if (origemInput[0] == 'F' || origemInput[0] == 'f') {
                break;
            }
            printf("Digite a torre de destino (1, 2, 3 ou 'F' para finalizar): ");
            scanf("%s", destinoInput);
            if (destinoInput[0] == 'F' || destinoInput[0] == 'f') {
                break;
            }

            int origem = atoi(origemInput);
            int destino = atoi(destinoInput);

            Torre *torreOrigem, *torreDestino;
            switch (origem) {
                case 1: torreOrigem = &A; break;
                case 2: torreOrigem = &B; break;
                case 3: torreOrigem = &C; break;
                default:
                    printf("Torre de origem inválida! Tente novamente.\n");
                    continue;
            }
            switch (destino) {
                case 1: torreDestino = &A; break;
                case 2: torreDestino = &B; break;
                case 3: torreDestino = &C; break;
                default:
                    printf("Torre de destino inválida! Tente novamente.\n");
                    continue;
            }

            if (!moverDisco(torreOrigem, torreDestino)) {
                printf("Movimento inválido! Tente novamente.\n");
            }

            mostrarTorres(&A, &B, &C, numDiscos);
        }

        // Pergunta se deseja jogar novamente
        char jogarNovamente;
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);

        if (jogarNovamente != 's' && jogarNovamente != 'S') {
            jogoAtivo = false;
        }
    }

    printf("\nObrigado por jogar!\n");

    return 0;
}
