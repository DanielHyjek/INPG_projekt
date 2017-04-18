#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "array.h"


void load(int*** tab){
	int row,col;
	FILE* we;
	if((we=fopen("danewe.txt","r"))==NULL){
		printf("Blad owarcia pliku");
		return;
	}

	while(!feof(we)){
        fscanf(we,"%d %d",&row,&col);
        if(row<ROWS && col<COLS){
			(*tab)[row][col]=1;
        }
	}

	if(fclose(we)!=NULL){
		printf("Blad zamkniecia pliku");
		return;
	}
}

void save(int*** tab){
	int row,col;
	FILE* wy;

	if((wy=fopen("danewy.txt","w"))==NULL){
		printf("Blad owarcia pliku");
		return;
	}
	for(row=0;row<ROWS;row++){
        for(col=0;col<COLS;col++){
        	if((*tab)[row][col]==1){
				fprintf(wy,"%d %d\n",row,col);
        	}
        }
	}

	if(fclose(wy)!=NULL){
		printf("Blad zamkniecia pliku");
		return;
	}

}
