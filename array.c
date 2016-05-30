#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int** create(int rows, int cols){
  int i,**tmp;
  tmp=(int**) calloc(rows, sizeof(int*));
  if(tmp==NULL){
	printf("Blad alokacji tablicy");
	return NULL;
  }
  for(i=0;i<rows;i++){
    tmp[i]=(int*)calloc(cols, sizeof(int));
    if(tmp[i]==NULL){
		printf("Blad alokacji tablicy");
		return NULL;
	}
  }
  return tmp;
}

void delete(int** tab, int rows){
  int i;
  for(i=0;i<rows;i++) free(tab[i]);
  free(tab);
}

void copy(int*** nowa, int** old, int rows, int cols){
    int i,j;
    *nowa = create(rows, cols);
    if(*nowa == NULL){
        printf("Blad alokacji tablicy");
        return;
    }
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++)
            (*nowa)[i][j]=old[i][j];
    }
    return;
}

void resize(int*** tab, int rows, int cols, int rows_new, int cols_new){
	int i,j,**tmp;
	tmp=create(rows_new,cols_new);
	for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            tmp[i][j]=(*tab)[i][j];
	delete(*tab, rows);
	*tab=tmp;
	return;
}

void insert(int*** tab, int element, int rows, int cols){
	(*tab)[rows][cols]=element;
	return;
}

int at(int** tab, int numer){
	int i,x=0,y=0;
	for(i=numer; i<numer; i++){
		if(i==COLS){
			i=0;
			numer-=COLS;
			y++;
		}
		x=i;
	}
	return tab[y][x];
}

void zerowanie(int***tab){
	int i,j;
	for(i=0;i<ROWS;i++)
        for(j=0;j<COLS;j++)
            (*tab)[i][j]=0;
}

void print(int**tab){
	int i,j;
	system("cls");
	for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(tab[i][j]==1){
				printf("%c",219);
            }
            if(tab[i][j]==0){
				printf("%c",255);
            }
        }
		printf("\n");
	}

}
