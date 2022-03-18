#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK 0, 0, 0
#define GREY 200,200,200
#define WHITE 255, 255, 255
#define GREEN 0, 128, 0


#define WIDHT_IMG 2560
#define HEIGHT_IMG 1600



struct Pixel {
  unsigned char r, g, b;
};

struct PixelHSI {
  unsigned char h, s, i;
};


char *leLinha(FILE *f) {
  static char str[1000];
  unsigned char c;
  int j = 0;

  c = fgetc(f);
  while (c == '#') {
    do {
      c = fgetc(f);
    } while (c != '\n');
    while (isspace(c = fgetc(f)))
      ;
  }

  do {
    str[j] = c;
    j++;
  } while (!isspace(c = fgetc(f)));

  str[j] = 0;
  return str;
}

// function that builds .ppm
void createPPM(char fileName[], struct Pixel img[HEIGHT_IMG][WIDHT_IMG]) {
  int tam;

  FILE *f = fopen(fileName, "wb");
  fprintf(f, "P6\n%d %d\n255\n", WIDHT_IMG, HEIGHT_IMG);

  tam = WIDHT_IMG * HEIGHT_IMG;

  if (fwrite(&img[0][0], 3, tam, f) != tam) {
    printf("Error file wasn't properly recorded\n");
    exit(1);
  }
  fclose(f);
}

struct Pixel image[HEIGHT_IMG][WIDHT_IMG];

struct Coord
{
    int x;
    int y;
};


//Make images's background
void doBackgroundPPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG])
{
    int i,j;
    struct Pixel BackGroundColor = {GREY};
    
    for(i = 0; i < HEIGHT_IMG; i++)
        {
            for(j = 0; j < WIDHT_IMG; j++)
            {
                image[i][j] = BackGroundColor;
            }
        }
}

//Make a white square from a giving point
void makeSquarePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG],int sizeOfEachSquares,struct Coord pos, struct Pixel color)
{

    int i;
    int j;

    for(i = pos.y; i < pos.y+sizeOfEachSquares; i++ )
        for(j = pos.x; j < pos.x+sizeOfEachSquares; j++)
        {
            image[i][j] = color;
        }
}




// Make a column from a giving point
void makeColumnPPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG],int quantityOfSquares, int sizeOfEachSquare,struct Coord pos, struct Pixel color)
{
    int i;
    int j;
    pos.y = HEIGHT_IMG - pos.y;
    for(i = 0; i < quantityOfSquares && pos.y < WIDHT_IMG - 100; i++)
        {
        
            makeSquarePPM(image, sizeOfEachSquare, pos, color);

            // Number of pixels will be jumped between each square
            pos.y += sizeOfEachSquare - (5) - 2 * sizeOfEachSquare;
        }
    
}


/* Put white Squares on background. Each node at numberBlock is a colunm and it's value represent the number of Square in that colunm. 

*/
void doTablePPM(struct Pixel image[HEIGHT_IMG][WIDHT_IMG], int quantityOfSquaresInEachColumn[],int quantityOfcolumns, int pointerPosition )
{
    struct Coord pos;
    int i;
    int biggestColumn = 0;
    int sizeOfEachSquare;
    struct Pixel color = {BLACK};

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

        if(i != pointerPosition)
            {
                makeColumnPPM(image,quantityOfSquaresInEachColumn[i],sizeOfEachSquare,pos,color);
            }
        else
            { 
                struct Pixel pointer = {GREEN};
                makeColumnPPM(image,quantityOfSquaresInEachColumn[i],sizeOfEachSquare,pos,pointer);
            }
        pos.x += increasX;
    }
    
}

// process makes the graph and process everything
void process(int *array, int arraySize, int pointerPosition,int ppmNumber)
{   
    char fileName[10];
    sprintf(fileName, "%d", ppmNumber);
    doBackgroundPPM(image);
    doTablePPM(image,array,arraySize,pointerPosition);
    createPPM(fileName,image);
}

