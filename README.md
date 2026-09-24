# Bob the robber

## 1.Descrição do Sistema

O projeto consiste em uma versão adaptada do jogo "Bob the Robber" desenvolvida para execução via terminal (CMD). O sistema permite ao usuário guiar o personagem Bob em uma missão de invasão a um prédio, na qual deve coletar o dinheiro espalhado pelos andares e alcançar a saída sem ser capturado pela segurança. O mapa é composto por andares delimitados por paredes e conectados por passagens, exigindo que o jogador utilize estratégias para traçar rotas eficientes, desviar da patrulha do guarda e cumprir os objetivos da fase.

O cenário e os elementos do jogo , como o próprio Bob, o guarda e os tesouros , são representados utilizando ASCII art. Os comandos de movimentação do personagem são mapeados para as teclas  W A S D do teclado, oferecendo uma jogabilidade intuitiva e sem limite de tempo. O foco principal do sistema é aplicar conceitos de lógica de programação, mapeamento o ambiente e o tratamento de entradas de usuário em tempo real em um ambiente de linha de comando.





## 2.Fluxo de utilização esperado para o sistema





## 3.Fluxograma da lógica do sistema

[Fluxograma](https://drive.google.com/file/d/1aFcGseEMWyP4mLJdGP-KYJg86lIVWs_0/view?usp=sharing)



## 4.Estrutura de dados

1. Estrutura de dados inical

   ```c
   //Posição Bob
   int bob_x;
   int bob_andar;

   //Posição Guarda
   int guarda_x;
   int guarda_andar;

   //Posição dinheiro
   int dinheiro_x;
   int dinheiro_andar;

   //Posição saída
   int saida_x;
   int saida_andar;

   //Estado do jogo
   int dinheiro_coletado;
   int jogo_ativo;

   //Comando jogador
   char comando;




3. Representação inicial do sistema (o código abaixo é uma representação inicial de como o jogo poderá ser estruturado no CMD):

   ```c
   #include <stdio.h>
   #include <stdlib.h>

   int main(){

    printf("========================================\n");
    printf("          BOB THE ROBBER                \n");
    printf("========================================\n\n");

    printf("ANDAR 2########################\n");
    printf("       #                      #\n");
    printf("       #          $           #\n");
    printf("       #----------------------#\n");
    printf("ANDAR 1#                      #\n");
    printf("       #                      #\n");
    printf("       #   B              G   #\n");
    printf("       #                    S #\n");
    printf("       ########################\n");

   return 0;
   }
