#ifndef ARRAY_H_
#define ARRAY_H_

#define ROWS 80
#define COLS 22

int** create(int, int);
void delete(int**, int);
void copy(int***, int**, int, int);
void resize(int***, int, int, int, int);
void insert(int***, int, int, int);
int at(int**, int);
void zerowanie(int***);
void print(int**);

#endif
