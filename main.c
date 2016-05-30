#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "array.h"
#include "gra.h"
#include "file.h"

int main()
{
    int **tab, **tab_copy;
    int row,col,kom,licznik=1,loop, key;


    tab=create(ROWS, COLS);
    tab_copy=create(ROWS, COLS);

	load(&tab); //odczyt danych z pliku
	save(&tab); //zapis danych do pliku
	printf("Ile cykli chcesz wyswietlic? ");
	scanf("%d",&loop);
    print(tab);
    Sleep(1000);

    do{
		copy(&tab_copy,tab,ROWS, COLS); //kopia stanu tablicy
		for(row=0;row<ROWS;row++){
			for(col=0;col<COLS;col++){
				kom=0;
				kom=otocenie(tab_copy,row,col);
				cykl(&tab,tab_copy,row,col,kom);
			}
		}
		print(tab);
		save(&tab);  //zapis generacji do pliku
		printf("Cykl: %d",licznik++);
		Sleep(200);
		loop--;
		if(loop==0){
			printf("\nAby wyswietlic kolejne 10 cykli wcisniej 1, aby zakonczyc wcisnij 2 ");
			scanf("%d",&key);
			if(key==1) loop=10;
			if(key==2) return 1;
		}
	}while(loop);

}
