#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHA 10
#define MAX_COLUNA 40

int main() {
    srand(time(NULL));
    int ox = MAX_COLUNA-2, oy = MAX_LINHA-2;
    int px = 1, py = 1;
    int sx = (int)(MAX_COLUNA * 0.4), sy = (int)(MAX_LINHA * 0.8);
    int x,y;
    int controle;
    int movimentoRealizado;
    int dificuldade = 1;
    int chaveObtida = 0;
    int cx = (int)(rand() % 40), cy = (int)(rand() % 10);
    while (cx == 20 || cx == 39 || cx == 0 || cy == 0 || cy == 9) {
        cx = (int)(rand() % 40);
        cy = (int)(rand() % 10);
    }
    for(;;) {
        system("CLS");
        printf("Torre Assombrada - Fúria da Wraith: %d\n\n", dificuldade);
        printf("Chave obtida: %i\n", chaveObtida);
        for(y = 0; y < MAX_LINHA; y++) {
            for(x = 0; x < MAX_COLUNA; x++) {
                if (x == 20 && y != 0 && y != 9 && y != 4) {
                    printf("|");
                } else if(y == 0 || x == 0 || x == MAX_COLUNA - 1 || y == MAX_LINHA - 1) {
                    printf("#");
                } else if (x == px && y == py) {
                    printf("P");
                } else if (x == sx && y == sy) {
                    printf("S");
                } else if (x == ox && y == oy) {
                    printf("@");
                } else if (x == cx && y == cy){
                    printf("C");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
        
        printf("Controles: 8 (cima)\t6 (direita)\t5 (baixo)\t4 (esquerda)\n");
        printf("Sua vez! Digite um controle: ");
        scanf("%i", &controle);
        
        movimentoRealizado = 1;
        switch(controle) {
            case 8:
                py -= 1;
                if(py < 1) {
                    py = 1;
                    movimentoRealizado = 0;
                } else if (px == 20) {
                    py = 4;
                    movimentoRealizado = 0;
                }
                break;
            case 5:
                py += 1;
                if(py >= MAX_LINHA - 1) {
                    py = MAX_LINHA -2;
                    movimentoRealizado = 0;
                } else if (px == 20) {
                    py = 4;
                    movimentoRealizado = 0;
                }
                break;
            case 4:
                px -= 1;
                if (px < 1) {
                    px = 1;
                    movimentoRealizado = 0 ;
                } else if (py != 4) {
                    if (px == 20) {
                        px = 21;
                        movimentoRealizado = 0;
                    }
                }
                break;
            case 6:
                px += 1;
                if(px >= MAX_COLUNA - 1) {
                    px = MAX_COLUNA -2;
                    movimentoRealizado = 0;
                } else if (py != 4) {
                    if (px == 20) {
                        px = 19;
                        movimentoRealizado = 0;
                    }
                }
                break;
                
            default:
                movimentoRealizado = 0;
                printf("\nComando invalido!\n");
                printf("Pressione qualquer tecla para continuar!\n");
                system("PAUSE");
        }
        
        if (py == cy && px == cx) {
            chaveObtida = 1;
            cy = 0, cx = 0;
        }
        if (movimentoRealizado == 1) {
            int direcao;
            if (py == sy) {
                if (px > sx) {
                    direcao = 3;
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
                    
            }
        }
        if (px == sx && py == sy) {
            printf("\n\nGAME OVER\n");
            break;
        } else if (px == ox && py == oy && chaveObtida == 1) {
            printf("\n\nYOU WIN\n");
            system("PAUSE");
            
            dificuldade++;
            
            px = 1;
            py = 1;
            chaveObtida = 0;
            cx = (int)(rand() % 40), cy = (int)(rand() % 10);
            while (cx == 20 || cx == 39 || cx == 0 || cy == 0 || cy == 9) {
                cx = (int)(rand() % 40);
                cy = (int)(rand() % 10);
            }
            sx = (int)(MAX_COLUNA * 0.7);
            sy = (int)(MAX_LINHA * 0.7);
        } 
    }
    system("PAUSE");
    return 0;
}
