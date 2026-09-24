# Bob the robber

## 1.Descrição do Sistema

O projeto consiste em uma versão adaptada do jogo "Bob the Robber" desenvolvida para execução via terminal (CMD). O sistema permite ao usuário guiar o personagem Bob em uma missão de invasão a um prédio, na qual deve coletar o dinheiro espalhado pelos andares e alcançar a saída sem ser capturado pela segurança. O mapa é composto por andares delimitados por paredes e conectados por passagens, exigindo que o jogador utilize estratégias para traçar rotas eficientes, desviar da patrulha do guarda e cumprir os objetivos da fase.

O cenário e os elementos do jogo , como o próprio Bob, o guarda e os tesouros , são representados utilizando ASCII art. Os comandos de movimentação do personagem são mapeados para as teclas  W A S D do teclado, oferecendo uma jogabilidade intuitiva e sem limite de tempo. O foco principal do sistema é aplicar conceitos de lógica de programação, mapeamento o ambiente e o tratamento de entradas de usuário em tempo real em um ambiente de linha de comando.



## 2.Fluxo de utilização esperado para o sistema

1. Ao iniciar o programa, o usuário visualizará todos os andares de um prédio, é um visão simplificada, como se o e difício fosse cortado ao meio

2. Sobre os componentes do mapa:
   - As paredes, que serão representadas por "#"
   - O personagem Bob, representado pela letra "B"
   - O guarda, representado pela letra "G"
   - A saída, representada pela letra "S"
   - O dinheiro, representado por "$"
   - Haverá 2 adares e será posicionado um caractere representando o dinheiro dentro do mapa

3. O usuário poderá controlar o personagem por meio de comandos inseridos pelo teclado. Cada tecla realizará uma ação específica no jogo:

   - A → movimenta Bob para a esquerda;
   - D → movimenta Bob para a direita;
   - W → faz Bob subir para o andar superior;
   - S → faz Bob descer para o andar inferior
     
4. Se o guarda e o Bob se encontrarem o jogoo acaba, ou se o Bob chegar à saída com o dinheiro o jogo também acaba

5. Não é possivel atravessar as paredes, não existe um limite de tempo e só é possivel um movimento por vez




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

   if (comando == 'd') {
      bob_x++;
   }
   
   else if (comando == 'a') {
      bob_x--;
   }
   
   else if (comando == 'w') {
      bob_andar++;
   }
   
   else if (comando == 's') {
      bob_andar--;
   }
   
   //limites do cenário
   
   //limite horizontal
   if (bob_x < 1) {
      bob_x = 1;
   }
   
   else if (bob_x > 50) {
      bob_x = 50;
   }
   
   //limite vertical
   if (bob_andar < 1) {
      bob_andar = 1;
   }
   
   else if (bob_andar > 2) {
      bob_andar = 2;
   }
   
   //coleta do dinheiro
   if (bob_x == dinheiro_x && bob_andar == dinheiro_andar) {
      dinheiro_coletado = 1;
   }
   
   else {
      dinheiro_coletado = 0;
   }
   
   //movimentação do guarda
   if (guarda_x < 50) {
      guarda_x++;
   }
   
   else if (guarda_x >= 50) {
      guarda_x--;
   }
   
   //guarda encontrar o Bob
   if (bob_x == guarda_x && bob_andar == guarda_andar) {
      jogo_ativo = 0;
      printf("Bob foi capturado pelo guarda!\n");
   }
   
   else {
      jogo_ativo = 1;
   }
   
   //condição de vitória
   if (dinheiro_coletado == 1 && bob_x == saida_x && bob_andar == saida_andar) {
      jogo_ativo = 0;
   
   printf("Bob conseguiu escapar!\n");
   }



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
