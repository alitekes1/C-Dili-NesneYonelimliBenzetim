#ifndef PLANT_H
#define PLANT_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "alive.h"
// typedef enum Bool{false, true}boolean;
struct PLANT
{
    Alive super;                          // bu sayede kalıtım işlemini yapmış olduk.
    void (*delete_plant)(struct PLANT *); // fonksiyon göstericisi
    // Plant new_plant(char *symbol);// yapıcı fonksiyon burada tanımlanmaz.
};
typedef struct PLANT *Plant;

void delete_plant(const Plant);
Plant new_plant(int value, char *symbol);
// eğer soyut sınıflar varsa sadece burada tanımlanır.
#endif