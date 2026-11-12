#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {

    char mapa[5][30];
    char comando;

    int bob_x = 2;
    int bob_andar = 4;

    int guarda_x[3] = {22, 14, 8};
    int guarda_andar[3] = {2, 1, 3};

    int dinheiro_x[3] = {14, 10, 20};
    int dinheiro_andar[3] = {1, 3, 2};
    int dinheiro_coletado[3] = {0, 0, 0};

    int saida_x = 27;
    int saida_andar = 4;

    int movimento;

    int jogo_ativo = 1;

    int i, j, k;

    int dificuldade;
    int quantidade;
    int fase_concluida;

    srand(time(NULL));
    printf("================================\n");
    printf("        BOB THE ROBBER\n");
    printf("================================\n");

    printf("\n             BEM-VINDO!\n\n");
    printf("Ajude Bob a coletar todo o dinheiro e encontrar\n");
    printf("a saida sem ser capturado pelos guardas.\n");

    printf("\n--------------- REGRAS ---------------------\n");
    printf("1. Colete todos os dinheiros da fase.\n");
    printf("2. Encontre a saida para concluir a fase.\n");
    printf("3. Nao deixe os guardas capturarem Bob.\n");
    printf("4. Complete as 3 fases para vencer o jogo.\n");

    printf("\n-------------- CONTROLES ------------------\n");
    printf("W - Subir\n");
    printf("S - Descer\n");
    printf("A - Esquerda\n");
    printf("D - Direita\n");
    printf("X - Sair do jogo\n");

    printf("\n--------------- LEGENDA -------------------\n");
    printf("B = Bob (jogador)\n");
    printf("G = Guarda\n");
    printf("$ = Dinheiro\n");
    printf("S = Saida\n");
    printf("# = Parede\n");

    printf("\n============================================\n");
    printf("       BOA SORTE E BOM JOGO, BOB!           \n");
    printf("============================================\n");

    system("pause");

    system("cls");

    printf("================================\n");
    printf("       BOB THE ROBBER\n");
    printf("================================\n");

    printf("\nEscolha a dificuldade:\n");
    printf("1 - Facil\n");
    printf("2 - Medio\n");
    printf("3 - Dificil\n");

    printf("\nOpcao: ");
    scanf("%d", &dificuldade);

    while (dificuldade < 1 || dificuldade > 3){
        printf("\nOpcao invalida!");
        printf("Opcao: ");
        scanf("%d", &dificuldade);
    }

    if (dificuldade == 1) {
        tentativas = 1;
    }
    else if (dificuldade == 2) {
        tentativas = 2;
    }
    else {
        tentativas = 3;
    }

    for (fase = 0; fase < 3 && jogo_ativo == 1; fase++) {

        quantidade = fase + 1;
        fase_concluida = 0;

        bob_x = 2;
        bob_andar = 4;

        for (i = 0; i < quantidade; i++) {
            dinheiro_coletado[i] = 0;
        }

        for (i = 0; i < 5; i++) {
            for (j = 0; j < 30; j++) {

                if (j == 0 || j == 29) {
                    mapa[i][j] = '#';
                }
                else {
                    mapa[i][j] = ' ';
                }
            }
        }
    
    return 0;
}
