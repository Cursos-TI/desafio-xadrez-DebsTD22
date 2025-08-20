#include <stdio.h>
#include <ctype.h>

int main(){

    /* Torre */
    /*
        Especificação das variaveis:

        - coluna: são as orientações verticais delimitadas no tabuleiro de xadrez, recebe os valores de A até H;
        - direcao: seleciona para qual sentido a peça irá andar;
        - continuar: determina se o jogo continuará ou será encerrado;
        - linha: são as orientações horizontais delimitadas no tabuleiro de xadrez, recebe os valores de 1 a 8;
        - casas: determina a quantidade de movimentos da peça;
        - novaColuna: armazena o valor anterior de coluna para que o proximo movimento sejá a partir dele;
        - novaLinha: armazena o valor anterior de linha para que o proximo movimento sejá a partir dele.

    */
    char coluna, direcao, continuar; 
    int  linha, casas; 
    
        printf("--------------------------------------------------------------------\n");
        printf("                            >>> TORRE <<<                           \n");
        printf("--------------------------------------------------------------------\n");
        printf("!!! A torre se move em linha reta para a vertical ou horizontal !!!\n \n");
        printf("Digite a posição inicial da torre (Ex.: A1)\n");
        printf(" - Primeiro a coluna: ");
        scanf("%s", &coluna); // recebe coluna
        coluna = toupper(coluna); // deixa a letra em maiusculo, caso a entrada seja minuscula

        printf(" - Agora a linha: ");
        scanf("%d", &linha); // recebe linha

    do {
        char novaColuna = coluna;
        int novaLinha = linha;

        printf("\nDigite a direção (D = direita, E = esquerda, C = cima, B = baixo): ");
        scanf(" %c", &direcao);

        printf(" - Quantas casa vai andar: "); // quantidade de casas vai andar
        scanf("%d", &casas);
        
        // Validação inicial
        if (coluna < 'A' || coluna > 'H' || linha < 1 || linha > 8 || casas < 1 || casas > 7) {
            printf("Posição inicial inválida.\n");
        } else {
            printf("Torre: casa atual >>> %c%d <<<\n", coluna, linha);
            // move a peça
            switch (toupper(direcao)) 
            {
            case 'D': //move para direita

                for (int i = 0; i < casas; i++) {
                    
                    if (novaColuna >= 'H') { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    novaColuna++;                   
                    printf("%c%d ... ", novaColuna, linha); // mostra os movimentos                
                }                
                coluna = novaColuna; 
                printf("Posição atual: >>> %c%d <<< \n", coluna, linha); // mostra posição atual
               
                break;

            case 'E': // move para a esquerda

                for (int i = 0; i < casas; i++) {
                    
                    if (novaColuna <= 'A') { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    novaColuna --;
                    printf("%c%d ... ", novaColuna, linha); // mostra os movimentos  
                }
                coluna = novaColuna;
                printf("Posição atual: >>> %c%d <<< \n", coluna, linha); // mostra posição atual

                break;

            case 'C': // move para cima

                for (int i = 0; i < casas; i++) {
                    
                    if (novaLinha >= 8) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    } 
                    novaLinha++;                                       
                    printf("%c%d ... ", coluna, novaLinha); // mostra os movimentos                
                }
                linha = novaLinha; 
                printf("Posição atual: >>> %c%d <<< \n", coluna, linha); // mostra posição atual

                break;

            case 'B': // move para baixo
                for (int i = 0; i < casas; i++) {
                    
                    if (novaLinha <= 1) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    } 
                    novaLinha--;                   
                    printf("%c%d ... ", coluna, novaLinha); // mostra os movimentos               
                }
                linha = novaLinha; 
                printf("Posição atual: >>> %c%d <<< \n", coluna, linha); // mostra posição atual

                break;
            
            default: // qualquer entrada diferente
                printf("Direção inválida.\n");
                break;
            }
        }
        printf("Deseja continuar (Y ou N): "); // para o jogo parar ou continuar
        scanf("%s", &continuar);

    } while (continuar == 'Y' || continuar == 'y');

    return 0;
}