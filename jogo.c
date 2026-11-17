#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void mensagemFase() {

    int mensagem = rand() % 3;

    if (mensagem == 0) {
        printf("\nMuito bem! Bob esta ficando rico!");
    }
    else if (mensagem == 1) {
        printf("\nMandou bem! Os guardas nao conseguiram pegar Bob!");
    }
    else {
        printf("\nMais uma fase concluida! Bob esta quase livre!");
    }
}

int escolherDificuldade() {

    int dificuldade;

    printf("================================\n");
    printf("       BOB THE ROBBER\n");
    printf("================================\n");

    printf("\nEscolha a dificuldade:\n");
    printf("1 - Facil\n");
    printf("2 - Medio\n");
    printf("3 - Dificil\n");

    printf("\nOpcao: ");
    scanf("%d", &dificuldade);

    while (dificuldade < 1 || dificuldade > 3) {
        printf("\nOpcao invalida!");
        printf("\nOpcao: ");
        scanf("%d", &dificuldade);
    }

    if (dificuldade == 1) {
        return 1;
    }
    else if (dificuldade == 2) {
        return 2;
    }
    else {
        return 3;
    }
}

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
    int bob_moveu;
    int encontrou;
    int tentativas;
    int fase;
    int novo_x;
    int novo_andar;
    int todos_dinheiros;

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
    tentativas = escolherDificuldade(); 

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

      while (jogo_ativo == 1 && fase_concluida == 0) {

            system("cls");

            printf("================================\n");
            printf("        BOB THE ROBBER\n");
            printf("             FASE %d\n", fase + 1);
            printf("================================\n");

            for (i = 0; i < 5; i++) {

                printf("ANDAR %d ", 5 - i);

                for (j = 0; j < 30; j++) {

                    if (bob_andar == i && bob_x == j) {
                        printf("B");
                    }
                    else {

                        encontrou = 0;

                        for (k = 0; k < quantidade; k++) {

                            if (guarda_andar[k] == i &&
                                guarda_x[k] == j) {

                                printf("G");
                                encontrou = 1;
                                break;
                            }
                        }

                        if (encontrou == 0) {

                            for (k = 0; k < quantidade; k++) {

                                if (dinheiro_coletado[k] == 0 &&
                                    dinheiro_andar[k] == i &&
                                    dinheiro_x[k] == j) {

                                    printf("$");
                                    encontrou = 1;
                                    break;
                                }
                            }
                        }

                        if (encontrou == 0) {

                            if (saida_andar == i && saida_x == j) {
                                printf("S");
                                encontrou = 1;
                            }
                        }

                        if (encontrou == 0) {
                            printf("%c", mapa[i][j]);
                        }
                    }
                }

                printf("\n");
            }

            printf("\nDinheiro: ");

            for (i = 0; i < quantidade; i++) {

                if (dinheiro_coletado[i] == 1) {
                    printf("[X] ");
                }
                else {
                    printf("[ ] ");
                }
            }

            printf("\n");

            printf("\nW = subir | S = descer");
            printf("\nA = esquerda | D = direita");
            printf("\nX = sair do jogo");

            printf("\n\nMovimento: ");
            scanf(" %c", &comando);

            comando = tolower(comando);

            bob_moveu = 0;

            if (comando == 'a') {
                novo_x = bob_x - 1;
                novo_andar = bob_andar;
                bob_moveu = 1;
            }
            else if (comando == 'd') {
                novo_x = bob_x + 1;
                novo_andar = bob_andar;
                bob_moveu = 1;
            }
            else if (comando == 'w') {
                novo_x = bob_x;
                novo_andar = bob_andar - 1;
                bob_moveu = 1;
            }
            else if (comando == 's') {
                novo_x = bob_x;
                novo_andar = bob_andar + 1;
                bob_moveu = 1;
            }
            else if (comando == 'x') {
                jogo_ativo = 0;
            }
            else {
                bob_moveu = 0;
            }

            if (bob_moveu == 1) {

                if (novo_x >= 1 && novo_x <= 28 &&
                    novo_andar >= 0 && novo_andar <= 4) {

                    if (mapa[novo_andar][novo_x] != '#') {
                        bob_x = novo_x;
                        bob_andar = novo_andar;
                    }
                }
            }
    for (i = 0; i < quantidade; i++) {

                if (bob_x == guarda_x[i] &&
                    bob_andar == guarda_andar[i]) {

                    jogo_ativo = 0;
                }
            }

            for (i = 0; i < quantidade; i++) {

                if (bob_x == dinheiro_x[i] &&
                    bob_andar == dinheiro_andar[i] &&
                    dinheiro_coletado[i] == 0) {

                    dinheiro_coletado[i] = 1;
                }
            }

            todos_dinheiros = 1;

            for (i = 0; i < quantidade; i++) {

                if (dinheiro_coletado[i] == 0) {
                    todos_dinheiros = 0;
                }
            }

            if (bob_x == saida_x &&
                bob_andar == saida_andar &&
                todos_dinheiros == 1) {

                fase_concluida = 1;
            }
if (bob_moveu == 1 && jogo_ativo == 1 &&
                fase_concluida == 0) {

                for (i = 0; i < quantidade; i++) {

                    for (k = 0; k < tentativas; k++) {

                        novo_x = guarda_x[i];
                        novo_andar = guarda_andar[i];

                        movimento = rand() % 4;

                        if (movimento == 0) {
                            novo_x--;
                        }
                        else if (movimento == 1) {
                            novo_x++;
                        }
                        else if (movimento == 2) {
                            novo_andar--;
                        }
                        else {
                            novo_andar++;
                        }

                        if (novo_x >= 1 && novo_x <= 28 &&
                            novo_andar >= 0 && novo_andar <= 4) {

                            guarda_x[i] = novo_x;
                            guarda_andar[i] = novo_andar;
                        }
                    }

                    if (bob_x == guarda_x[i] &&
                        bob_andar == guarda_andar[i]) {

                        jogo_ativo = 0;
                    }
                }
            }
        }
       if (jogo_ativo == 1 && fase_concluida == 1) {

            system("cls");

            printf("================================\n");
            printf("       FASE %d CONCLUIDA!\n", fase + 1);
            printf("================================\n");

            if (fase < 2) {
                system("pause");
            }
        }
    }

    system("cls");

    if (jogo_ativo == 0) {
        printf("\n================================\n");
        printf("            GAME OVER\n");
        printf("================================\n");
    }
    else {
        printf("\n================================\n");
        printf("       PARABENS! VOCE VENCEU!\n");
        printf("================================\n");
    }

    system("pause");

    return 0;
}
    

