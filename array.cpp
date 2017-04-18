#include <iostream>
#include <new>

using namespace std;

void copy(int*** nowa, int** old, int rows, int cols)
{
    int i,j;
    *nowa = new int *[rows];

    if(*nowa == NULL)
    {
        cout<<"Blad alokacji tablicy";
        return;
    }

    for(i=0;i<rows;i++)
    {
        (*nowa)[i] = new int [cols];

        if((*nowa)[i] == NULL)
        {
            cout<<"Blad alokacji tablicy";
            return;
        }
    }

    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            (*nowa)[i][j]=old[i][j];
    return;
}


