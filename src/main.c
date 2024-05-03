#include <stdio.h>
#include <stdlib.h>
#include "habitat.h"

int main()
{
    Habitat habitat = new_Habitat();
    Alive alive = new_Alive(15, "A");    // canli
    Fly fly = new_Fly(20, "S");          // sinek
    Flea flea = new_Flea(18, "P");       // pire
    Beetle beetle = new_Beetle(15, "C"); // böcek
    habitat->readFile(habitat, "C://Users//acerr//Desktop//Veri.txt");
    habitat->showHabitat(habitat);

    return 0;
}