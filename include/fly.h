#ifndef FLY_H
#define FLY_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "alive.h"

struct FLY
{
    Alive super; // alive.h de typedef var. bu yüzden Alive oldu
    void (*delete_Fly)(struct FLY *);
};
typedef struct FLY *Fly;
Fly new_Fly(int value, char *symbol, int location);
void delete_Fly(const Fly);

#endif