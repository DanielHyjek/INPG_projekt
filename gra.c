e robi#include <stdio.h>
#include <stdlib.h>
#include "gra.h"
#include "array.h"

char sprawdz(char** tab,char ***ntab,int x,int y)
{
    int i,k,m,n;
    int suma=0;
    for(i=1;i<(x-1);i++){
        for(k=1;k<(y-1);k++) {
            for(m=(i-1);m<(i+2);m++) {
                for(n=(k-1);n<(k+2);n++){
                    if(tab[m][n]=='*' ) suma++;
                }
            }
            if(tab[i][k]=='*') suma--;
            if(tab[i][k]=='*'){
                if(suma<2||suma>3) (*ntab)[i][k]=' ';
            }
            if(tab[i][k]==' ' && suma==3) (*ntab)[i][k]='*';
            suma=0;
        }
    }
}
