#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void createPPM(char nomeArq[], struct Pixel img[HEIGHT_IMG][WIDHT_IMG]) {
  int tam;
  FILE *f = fopen(nomeArq, "wb");
  fprintf(f, "P6\n%d %d\n255\n", WIDHT_IMG, HEIGHT_IMG);
  tam = WIDHT_IMG * HEIGHT_IMG;
  if (fwrite(&img[0][0], 3, tam, f) != tam) {
    printf("O arquivo de imagem nao foi gravado corretamente.\n");
    exit(1);
  }
  fclose(f);
}
