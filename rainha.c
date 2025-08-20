#include <stdio.h>
#include <ctype.h>

int main(){

    /* RAINHA */
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
        printf("                            >>> RAINHA <<<                           \n");
        printf("--------------------------------------------------------------------\n");
        printf(" !!! A rainha se move nas linhas diagonais, e em linhas retas horizontais e verticais !!!\n \n");
        printf("Digite a posição inicial do bispo (Ex.: A1)\n");
        printf(" - Primeiro a coluna: ");
        scanf(" %c", &coluna); // recebe coluna
        coluna = toupper(coluna); // deixa a letra em maiusculo, caso a entrada seja minuscula

        printf(" - Agora a linha: ");
        scanf(" %d", &linha); // recebe linha

    do {
        char novaColuna = coluna;
        int novaLinha = linha, contador = 0;

        printf(" Y = diagonal direita para cima \n X = diagonal esquerda para cima \n M = diagonal direita para baixo \n N = diagonal esquerda para baixo \n C = cima \n B = baixo \n E = esquerda \n D = direita\n \n >>> Digite a direção: ");
        scanf(" %c", &direcao);

        printf(" - Quantas casa vai andar: "); // quantidade de casas que vai andar
        scanf(" %d", &casas);
    
        // Validação inicial
       if (coluna < 'A' || coluna > 'H' || linha < 1 || linha > 8 || casas < 1 || casas > 7) {
            printf("Posição inicial inválida.\n");
        } else {
            printf("Rainha: casa inicial %c%d \n", coluna, linha);
            // move a peça
            switch (toupper(direcao)) 
            {
            case 'Y': //move para a diagonal direita para cima
            
                do {
                    if (novaColuna >= 'H' || novaLinha >= 8 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    linha++; 
                    coluna++;
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("\nPosição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'X': // mover para a diagonal esquerda para cima
                
                do {
                    if (novaColuna <= 'A' || novaLinha >= 8 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    linha++; 
                    coluna--;
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'M': // mover para diagonal direita para baixo
                
                do {
                    if (novaColuna >= 'H' || novaLinha <= 1 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    linha--; 
                    coluna++;
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'N': // mover para diagonal esquerda para baixo
                
                do {
                    if (novaColuna <= 'A' || novaLinha <= 1 ) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    linha--; 
                    coluna--;
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'C': // mover para cima
                
                do {
                    if (novaLinha >= 8) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    } 
                    linha++; 
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;

            case 'B': // mover para baixo
                
                do {
                    if (novaLinha <= 1) { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    } 
                    linha--; 
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;
            
            case 'E': // mover para esquerda 
                
                do {
                    if (novaColuna <= 'A') { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    coluna--;
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
                printf("Posição atual: %c%d \n", coluna, linha); // mostra posição atual
                break;
                
            case 'D': // mover para direita
                
                do {
                    if (novaColuna >= 'H') { // não ultrapassa o limite do tabuleiro
                        printf("Não é possivel andar mais \n");
                        break;
                    }
                    coluna++;
                    printf("%c%d ... ", coluna, linha);
                    contador++;

                } while (contador < casas ) ;
                
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