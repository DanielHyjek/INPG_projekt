#ifndef ARRAY_H
#define ARRAY_H

char **create(int wiersze, int kolumny);
char **resize(char **tab, int *wiersze, int *kolumny, int powiekszenie);
char at(char **tab, int x, int y);
char **inserd(char **tab, int x, int y, char element);
void destroy(char ***ptab, int wiersze);

#endif
