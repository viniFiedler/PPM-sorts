#include <stdio.h>
#include "image.h"
#define BLACK 0, 0, 0
#define WHITE 255, 255, 255

struct Pixel image[HEIGHT_IMG][WIDHT_IMG];

struct Coord
{
    int x;
    int y;
};


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
void makeSquarePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG],int sizeOfEachSquares,struct Coord pos)
{

    int i;
    int j;
    struct Pixel white = {WHITE};

    for(i = pos.y; i < pos.y+sizeOfEachSquares; i++ )
        for(j = pos.x; j < pos.x+sizeOfEachSquares; j++)
        {
            image[i][j] = white;
        }
}


// Make a column from a giving point
void makeColumnPPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG],int quantiyOfSquares, int sizeOfEachSquares,struct Coord pos)
{
    int i;
    int j;
    pos.y = HEIGHT_IMG - pos.y;
    for(i = 0; i < quantiyOfSquares && pos.y < WIDHT_IMG - 100; i++)
        {
        
            makeSquarePPM(image, sizeOfEachSquares, pos);
            pos.y += sizeOfEachSquares - (10) - 2 * sizeOfEachSquares;
        }
    
}
//Put white Squares on background. Each node at numberBlock is a colunm and it's value represent the number of Square in that colunm. 
void doSquarePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG], int numberOfSquares[],int quantiyOfSquares)
{
    quantiyOfSquares = 10;
    int spaceHeight = HEIGHT_IMG/10;
    int spaceWIDHT = WIDHT_IMG/20;

}


int main()
{   
    struct Coord pos;
    pos.x = 20;
    pos.y = 100;
    doBackgroundPPM(image);
    //makeSquarePPM(image,100,pos);
    makeColumnPPM(image,14,100,pos);
    pos.x += 120;
    makeColumnPPM(image,14,100,pos);
    pos.x += 120;
    makeColumnPPM(image,14,100,pos);
    pos.x += 120;
    makeColumnPPM(image,14,100,pos);
    pos.x += 120;
    makeColumnPPM(image,14,100,pos);
    pos.x += 120;
    makeColumnPPM(image,14,100,pos);
    pos.x += 120;
    makeColumnPPM(image,14,100,pos);
    createPPM("Teste Imagem",image);
}