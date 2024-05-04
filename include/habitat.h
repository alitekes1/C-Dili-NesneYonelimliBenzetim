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
    int size;
    int *values;
    Alive **allAlives;
    void (*setCol)(struct HABITAT *, int col);
    void (*setRow)(struct HABITAT *, int row);
    void (*setSize)(struct HABITAT *, int size);
    void (*showHabitat)(struct HABITAT *); // Fonksiyon işaretçisi tanımı düzeltilmiş
    void (*delete_Habitat)(struct HABITAT *);
    void (*readFile)(struct HABITAT *, char *filepath);
    void (*yemeIslemleri)(struct HABITAT *);
    void (*assignAliveToHabitat)(struct HABITAT *);
    void (*deneme)(struct HABITAT *, char, char, Alive *, Alive *, char, char);
    // sadece buraya eğer bir fonksiyon eklersek (aşağıya değil) soyut sınıf benzetmesi olur.
};
typedef struct HABITAT *Habitat;
// eğer private benzetmesi yapmak istiyorsak sadece burada ilgili fonksiyonu tanımlayabiliriz.
Habitat new_Habitat();
void setRow(const Habitat, int row);
void setCol(const Habitat, int col);
void setSize(const Habitat, int size);
void delete_Habitat(const Habitat);
void showHabitat(const Habitat);
void assignAliveToHabitat(const Habitat);
void readFile(const Habitat, char *filepath);
void yemeIslemleri(const Habitat);
void deneme(const Habitat this, char pointerSymbol, char currentSymbol, Alive *pointer, Alive *currentAlive, char yiyebildikleri1, char yiyebildikleri2);

#endif
