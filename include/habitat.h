#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "alive.h"
#include "beetle.h"
#include "fly.h"
#include "flea.h"
#include "plant.h"
struct HABITAT
{
    int row;
    int col;
    int *values;
    Alive **allAlives;
    void (*setCol)(struct HABITAT *, int col);
    void (*setRow)(struct HABITAT *, int row);
    void (*showHabitat)(struct HABITAT *); // Fonksiyon işaretçisi tanımı düzeltilmiş
    void (*delete_Habitat)(struct HABITAT *);
    void (*readFile)(struct HABITAT *, char *filepath);
    // sadece buraya eğer bir fonksiyon eklersek (aşağıya değil) soyut sınıf benzetmesi olur.
};
typedef struct HABITAT *Habitat;
// eğer private benzetmesi yapmak istiyorsak sadece burada ilgili fonksiyonu tanımlayabiliriz.
Habitat new_Habitat();
void setRow(const Habitat, int row);
void setCol(const Habitat, int col);
void delete_Habitat(const Habitat);
void showHabitat(const Habitat);
void assignAliveToHabitat(const Habitat);
void readFile(const Habitat, char *filepath);
#endif
