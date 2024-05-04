#ifndef ALIVE_H
#define ALIVE_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

struct ALIVE
{
    int value;
    char *symbol;
    int location;
    void (*delete_Alive)(struct ALIVE *);
    char *(*getAliveSymbol)(struct ALIVE *);              // canlinin sembolunu dondurur
    void (*setAliveSymbol)(struct ALIVE *, char *symbol); // canlinin sembolunu set eder.
};
typedef struct ALIVE *Alive;
// eğer private benzetmesi yapmak istiyorsak buraya yazmamak gerekir. gövdelerin olduğu .c dosyasına yazmak gerekir.
Alive new_Alive(int value, char *symbol, int location); // yapıcı fonksiyon. canlinin değerini ve sembolunu atar.

char *getAliveSymbol(const Alive);              // canlinin sembolunu geri dondurur.
void setAliveSymbol(const Alive, char *symbol); // canlinin sembolunu X olarak ayarlar.
void delete_Alive(const Alive);                 // canlinin yokedicisi

#endif