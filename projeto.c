#include <stdio.h>
#include "image.h"
#define BLACK 0, 0, 255
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
void makeColumnPPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG],int quantityOfSquares, int sizeOfEachSquare,struct Coord pos)
{
    int i;
    int j;
    pos.y = HEIGHT_IMG - pos.y;
    for(i = 0; i < quantityOfSquares && pos.y < WIDHT_IMG - 100; i++)
        {
        
            makeSquarePPM(image, sizeOfEachSquare, pos);

            // Number of pixels will be jumped between each square
            pos.y += sizeOfEachSquare - (5) - 2 * sizeOfEachSquare;
        }
    
}
// Put white Squares on background. Each node at numberBlock is a colunm and it's value represent the number of Square in that colunm. 
void doTablePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG], int quantityOfSquaresInEachColumn[],int quantityOfcolumns)
{
    struct Coord pos;
    int i;
    int biggestColumn = 0;
    int sizeOfEachSquare;

    for(i = 0; i < quantityOfcolumns; i++)
    {

        if(quantityOfSquaresInEachColumn[i] > biggestColumn)
            biggestColumn = quantityOfSquaresInEachColumn[i];
            
    }
    

    if(biggestColumn >= quantityOfcolumns)
        {
            sizeOfEachSquare = (HEIGHT_IMG - (biggestColumn * 5))/(biggestColumn);
        }
    else
        {
             sizeOfEachSquare = (HEIGHT_IMG - (quantityOfcolumns * 5))/(quantityOfcolumns);
        }

        pos.y = sizeOfEachSquare;
        
        int increasX = (WIDHT_IMG)/quantityOfcolumns;
        pos.x = (WIDHT_IMG - (increasX * quantityOfcolumns) + increasX - sizeOfEachSquare)/2 ;

    
    for(i = 0; i < quantityOfcolumns; i++)
    {
        makeColumnPPM(image,quantityOfSquaresInEachColumn[i],sizeOfEachSquare,pos);
        pos.x += increasX;
    }
    
}





int main()
{   

    int columns[21] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,7};
    doBackgroundPPM(image);
    doTablePPM(image,columns,5);
    createPPM("Teste Imagem",image);
}