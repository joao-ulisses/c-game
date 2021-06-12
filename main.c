#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHA 10
#define MAX_COLUNA 40

int main() {
    srand(time(NULL));
    int ox = MAX_COLUNA-2, oy = MAX_LINHA-2
        ,px , py
        ,sx , sy
        ,cx , cy
        ,dificuldade = 1
        ,chaveObtida = 0
        ,chaveDefinida = 0
        ,vitoria = 1;
    int x,y
        ,controle
        ,direcao;
    int parede[5] = {20, 39, 0, 9, 4};
    int caracteres[7] = {186, 177, 241, 207, 219, 189, 196};

    printf("Voce eh um cacador de fantasmas e descobriu um fantasma do tipo Wraith, \ne precisa fugir da torre assombrada em que se encontra... \n\n");
    system("PAUSE");
    for(;;) {

        if (vitoria == 1) {
            px = 1;
            py = 1;
            sx = (int)(MAX_COLUNA * 0.4);
            sy = (int)(MAX_LINHA * 0.8);
            vitoria = 0;
            chaveObtida = 0;
            chaveDefinida = 0;
        }
        if (chaveObtida == 0) {
            while (cx == parede[0] || cx == parede[1]|| cx == parede[2] || cy == parede[2] || cy == parede[3]) {
                cx = (int)(rand() % MAX_COLUNA);
                cy = (int)(rand() % MAX_LINHA);
            }
            chaveDefinida = 1;
        }
        controle = 0;
        system("CLS");
        printf("Torre Assombrada - Furia da Wraith: %d\n\n", dificuldade);
        printf("Chave obtida: %i\n\n", chaveObtida);
        for(y = 0; y < MAX_LINHA; y++) {
            for(x = 0; x < MAX_COLUNA; x++) {

                if (x == parede[0] && y != parede[2] && y != parede[3] && y != parede[4]) {
                    printf("%c", caracteres[0]);
                } else if(y == 0 || x == 0 || x == MAX_COLUNA - 1 || y == MAX_LINHA - 1) {
                    printf("%c", caracteres[1]);
                } else if (x == px && y == py) {
                    printf("%c", caracteres[2]);
                } else if (x == sx && y == sy) {
                    printf("%c", caracteres[3]);
                } else if (x == ox && y == oy) {
                    printf("%c", caracteres[4]);
                } else if (x == cx && y == cy){
                    printf("%c", caracteres[5]);
                } else {
                    printf("%c", caracteres[6]);
                }
            }
            printf("\n");
        }
        printf("\n");

        printf("Controles: 8 (cima)\t6 (direita)\t5 (baixo)\t4 (esquerda)\n\n");
        printf("Fantasma - %c \nPlayer - %c \nChave - %c \nPorta - %c \n\n", caracteres[3], caracteres[2], caracteres[5], caracteres[4]);
        printf("Sua vez! Digite um controle: ");
        scanf("%i", &controle);
        setbuf(stdin, NULL);
        switch(controle) {

            case 8:
                py -= 1;
                if(py < 1) {
                    py = 1;
                } else if (px == 20) {
                    py = 4;
                }
                break;

            case 5:
                py += 1;
                if(py >= MAX_LINHA - 1) {
                    py = MAX_LINHA -2;
                } else if (px == 20) {
                    py = 4;
                }
                break;

            case 4:
                px -= 1;
                if (px < 1) {
                    px = 1;
                } else if (py != 4) {
                    if (px == 20) {
                        px = 21;
                    }
                }
                break;

            case 6:
                px += 1;
                if(px >= MAX_COLUNA - 1) {
                    px = MAX_COLUNA -2;
                } else if (py != 4) {
                    if (px == 20) {
                        px = 19;
                    }
                }
                break;

            default:
                printf("\nComando invalido!\n");
                system("PAUSE");
        }

        if (py == cy && px == cx) {
            chaveObtida = 1;
            cy = 0, cx = 0;
        }

        if (py == sy) {
            if (px > sx) {
                direcao = 3;
            } else if (px == sx) {
                direcao = 4;
            } else {
                direcao = 2;
            }
        } else if (px == sx) {
            if (py > sy) {
                direcao = 1;
            } else {
                direcao = 0;
            }
        } else {
            direcao = rand() % 4;
        }

        switch(direcao) {

            case 0:
                sy -= dificuldade;
                if (sy < 1) {
                    sy = 1;
                }
                break;

            case 1:
                sy += dificuldade;
                if (sy >= MAX_LINHA - 1) {
                    sy = MAX_LINHA - 2;
                }
                break;

            case 2:
                sx -= dificuldade;
                if (sx < 1) {
                    sx = 1;
                }
                break;

            case 3:
                sx += dificuldade;
                if (sx >= MAX_COLUNA - 1) {
                    sx = MAX_COLUNA - 2;
                }
                break;

            case 4:
                sx = sx;
                break;

        }

        if (px == sx && py == sy) {
            printf("\n\nO fantasma te alcancou na torre\n");
            break;
        } else if (px == ox && py == oy && chaveObtida == 1) {
            printf("\n\nVoce desceu mais um andar\n");
            system("PAUSE");
            dificuldade++;
            vitoria = 1;
        }
    }
    system("PAUSE");
    return 0;
}
