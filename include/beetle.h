#ifndef BEETLE_H
#define BEETLE_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "alive.h"

struct BEETLE
{
    Alive super; // alive.h de typedef var. bu yüzden Alive oldu
    void (*delete_Beetle)(struct BEETLE *);
};
typedef struct BEETLE *Beetle;
Beetle new_Beetle(int value, char *symbol);
void delete_Beetle(const Beetle);

#endif