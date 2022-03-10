#include <stdio.h>
#include "image.h"
#define BLACK 0, 0, 0

struct Pixel image[ALTU_IMG][LARG_IMG];

void criaImagemEscura(struct Pixel image[ALTU_IMG][LARG_IMG])
{
    int i,j;
    struct Pixel fundo = {BLACK};
    
    for(i = 0; i < ALTU_IMG; i++)
        {
            for(j = 0; j < LARG_IMG; j++)
            {
                image[i][j] = fundo;
            }
        }
}

int main()
{   
    criaImagemEscura(image);
    createPPM("Teste Preto",image);
}