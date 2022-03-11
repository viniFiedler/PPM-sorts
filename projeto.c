#include <stdio.h>
#include "image.h"
#define BLACK 0, 0, 0
#define WHITE 255, 255, 255

struct Pixel image[HEIGHT_IMG][WIDHT_IMG];


//Make images's background black
void doBackgroundPPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG])
{
    int i,j;
    struct Pixel black = {BLACK};
    
    for(i = 0; i < HEIGHT_IMG; i++)
        {
            for(j = 0; j < WIDHT_IMG; j++)
            {
                image[i][j] = black;
            }
        }
}

//Make a white square from a giving point
void makeSquarePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG],int sizeOfEachSquares, int coord_x, int coord_y)
{
    int i =coord_x,j = coord_y;

    struct Pixel white = {WHITE};

    for(i = coord_x; i < coord_x+sizeOfEachSquares; i++ )
        for(j = coord_y; j < coord_y+sizeOfEachSquares; j++)
        {
            image[i][j] = white;
        }
}

//Put white Squares on background. Each node at numberBlock is a colunm and it's value represent the number of Square in that colunm. 
void doSquarePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG], int numberOfSquares[],int quantiyOfNodes)
{
    quantiyOfNodes = 10;
    int spaceHeight = HEIGHT_IMG/10;
    int spaceWIDHT = WIDHT_IMG/20;

}


int main()
{   
    doBackgroundPPM(image);
    makeSquarePPM(image,100,50,50);
    createPPM("Teste Preto",image);
}