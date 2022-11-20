# PPM Sorts 

### About
This project produces one .ppm for each step of the selected sorting algorithm.

Inspired by videos like [this one](https://www.youtube.com/watch?v=8MsTNqK3o_w&t=2775s&ab_channel=Musicombo).

Don't take this Repo too serious, its just a compile from my first year at college.


## How to install and Execute

```bash

# install GCC
$ sudo apt install build-essential
$ sudo apt-get install manpages-dev

# Clone repo
$ git clone https://github.com/viniFiedler/PPM-sorts.git

# Compile
$ gcc projeto.c -o projeto

# Execute
$ ./projeto



```
## Usage

Just #include "image.h"

## Example

```C
#include <stdio.h>
#include "image.h"


// Example of use Selection Sort

void selection_sort(int *array, int arraySize) 
{ 
  int i, j, min, aux,ppmNumber = 0;

    process(array,arraySize,i,ppmNumber++);

  for (i = 0; i < (arraySize-1); i++) 
  {
     min = i;

     for (j = (i+1); j < arraySize; j++) {
       if(array[j] < array[min]) 
         min = j;
     }
     if (i != min) {
       aux = array[i];
       array[i] = array[min];
       array[min] = aux;

     }
    process(array,arraySize,i,ppmNumber++);


  }

    process(array,arraySize,i,ppmNumber++);

}

int main()
{   

    int columns[5] = {9,4,5,6,8};
        
    double duracao;
    int j;
    

    selection_sort(columns,5);
        
    
   return 0;
}
```


