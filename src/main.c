#include <stdio.h>
#include <stdlib.h>
#include "habitat.h"

int main()
{
    Habitat habitat = new_Habitat();
    habitat->readFile(habitat, "doc/Veri.txt");
    showHabitat(habitat);
    habitat->eatOperations(habitat);
    return 0;
}