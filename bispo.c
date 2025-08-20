#include <stdio.h>
#include <ctype.h>

int main(){

    /* BISPO */
    /*
        Especificação das variaveis:

        - coluna: são as orientações verticais delimitadas no tabuleiro de xadrez, recebe os valores de A até H;
        - direcao: seleciona para qual sentido a peça irá andar;
        - continuar: determina se o jogo continuará ou será encerrado;
        - linha: são as orientações horizontais delimitadas no tabuleiro de xadrez, recebe os valores de 1 a 8;
        - casas: determina a quantidade de movimentos da peça;
        - novaColuna: armazena o valor anterior de coluna para que o proximo movimento sejá a partir dele;
        - novaLinha: armazena o valor anterior de linha para que o proximo movimento sejá a partir dele;
        - contador: contabiliza o movimento das peças.

    */
    char coluna, direcao, continuar; 
    int  linha, casas; 
    
        printf("--------------------------------------------------------------------\n");
        printf("                            >>> BISPO <<<                           \n");
        printf("--------------------------------------------------------------------\n");
        printf(" !!! O bispo se move nas linha diagonais, referente a sua cor !!!\n \n");
        printf("Digite a posição inicial do bispo (Ex.: A1)\n");
        printf(" - Primeiro a coluna: ");
        scanf("%c", &coluna); // recebe coluna
        coluna = toupper(coluna); // deixa a letra em maiusculo, caso a entrada seja minuscula
        
        printf(" - Agora a linha: ");
        scanf("%d", &linha); // recebe linha

    do {
        char novaColuna = coluna;
        int novaLinha = linha, contador = 0;

        printf("\nDigite a direção (D = diagonal direita para cima, E = diagonal esquerda para cima, C = diagonal direita para baixo, B = diagonal esquerda para baixo):  ");
        scanf(" %c", &direcao);

        printf(" - Quantas casa vai andar: "); // quantidade de casas que vai andar
        scanf("%d", &casas);

        // Validação inicial
        if (coluna < 'A' || coluna > 'H' || linha < 1 || linha > 8 || casas < 1 || casas > 7) {
            printf("\nPosição inicial inválida.\n");
        } else {
            printf("Bispo: casa inicial %c%d \n", coluna, linha);
            // move a peça
            switch (toupper(direcao))
            {
            case 'D': //move para a diagonal direita para cima

                while (contador < casas) {
                    if (novaColuna >= 'H' || novaLinha >= 8 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    novaColuna++;
                    novaLinha++;
                    printf("%c%d ... ", novaColuna, novaLinha);
                    contador++;
                }   
                coluna = novaColuna;
                linha = novaLinha;
                
                printf("\nPosição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'E': // move para a diagonal esquerda para cima 
                
                while (contador < casas) {
                    if (novaColuna <= 'A' || novaLinha >= 8 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    novaColuna--;
                    novaLinha++;
                    printf("%c%d ... ", novaColuna, novaLinha);
                    contador++;
                }   
                coluna = novaColuna;
                linha = novaLinha;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'C': // move para diagonal direita para baixo
                
                while (contador < casas) {
                    if (novaColuna >= 'H' || novaLinha <= 1 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    novaColuna++;
                    novaLinha--;
                    printf("%c%d ... ", novaColuna, novaLinha);
                    contador++;
                }   
                coluna = novaColuna;
                linha = novaLinha;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'B': // move para diagonal esquerda para baixo
                
                while (contador < casas) {
                    if (novaColuna <= 'A' || novaLinha <= 1 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n"); 
                        break;
                    }
                    novaColuna--;
                    novaLinha--;
                    printf("%c%d ... ", novaColuna, novaLinha);
                    contador++;
                }   
                coluna = novaColuna;
                linha = novaLinha;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
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