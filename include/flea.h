#ifndef FLEA_H
#define FLEA_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "alive.h"

struct FLEA
{
    Alive super; // alive.h de typedef var. bu yüzden Alive oldu
    void (*delete_Flea)(struct FLEA *);
};
typedef struct FLEA *Flea;
Flea new_Flea(int value, char *symbol,int location);
void delete_Flea(const Flea);

#endif