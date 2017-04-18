#include<stdio.h>
#include<stdlib.h>
#include "array.h"

char **create(int wiersze, int kolumny){
	char **tab;
	tab=(char**)malloc(wiersze*sizeof(char*));
	if (tab==NULL){
		cout<<"Blad przydzielania pamieci.";
		return NULL;
	}
	int i;
	for(i=0; i<wiersze; i++){
		tab[i]=(char*)malloc(kolumny*sizeof(char));
		if (tab[i]==NULL){
		cout("Blad przydzielania pamieci dla %d-tego wiersza.", i);
		destroy(&tab, i);
		return NULL;
	}}
	return tab;
}

char **resize(char **tab, int *pwiersze, int *pkolumny, int powiekszenie){
	char **tab_new;
	tab_new=create(*pwiersze+powiekszenie, *pkolumny+powiekszenie);
	int i,j;
	for(i=0; i<*pwiersze; i++)
			 for(j=0; j<*pkolumny; j++)
			 		  tab_new[i][j]=tab[i][j];
	destroy(&tab, *pwiersze);
	*pwiersze=*pwiersze+powiekszenie;
	*pkolumny=*pkolumny+powiekszenie;
	return tab_new;
}

char at(char **tab, int x, int y){
	return tab[x][y];
}

char **inserd(char **tab, int x, int y, char element){
	tab[x][y]=element;
	return tab;
}

void destroy(char ***ptab, int wiersze){
	int i;
	for(i=0; i<wiersze; i++){
		free(*ptab[i]);
		*ptab[i]=NULL;
	}
	free(*ptab);
	*ptab=NULL;
}
