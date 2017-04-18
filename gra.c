#include <stdio.h>
#include <stdlib.h>
#include "gra.h"
#include "array.h"



int otocenie(int **tab_copy, int row, int col){
int tmp=0;
if(row!=0){
	if(col!=0) if(tab_copy[row-1][col-1]==1) tmp++;
	if(tab_copy[row-1][col]==1) tmp++;
	if(col<(COLS-1)) if(tab_copy[row-1][col+1]==1) tmp++;
}
if(row!=(ROWS-1)){
	if(col!=0) if(tab_copy[row+1][col-1]==1) tmp++;
	if(tab_copy[row+1][col]==1) tmp++;
	if(col<(COLS-1)) if(tab_copy[row+1][col+1]==1) tmp++;
}

	if(col!=0) if(tab_copy[row][col-1]==1) tmp++;
	if(col<(COLS-1)) if(tab_copy[row][col+1]==1) tmp++;
return tmp;
}

void cykl(int ***tab, int **tab_copy, int row, int col, int kom){
	if(tab_copy[row][col]==1){
		if(kom>3 || kom<2) (*tab)[row][col]=0;
	}
	if(tab_copy[row][col]==0 && kom==3){
		(*tab)[row][col]=1;
	}
}
