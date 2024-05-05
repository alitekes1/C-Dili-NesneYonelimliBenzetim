#include "Fly.h"
Fly new_Fly(int value, char *symbol, int location)
{
    Fly this;
    this = (Fly)malloc(sizeof(Fly));
    this->super = new_Alive(value, symbol, location);
    return this;
}
void delete_Fly(const Fly this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->delete_Alive(this->super); // burada ilk once canli için aldığımız alanı geri iade ettik.
    free(this);                             // burada bocek için alınan alanı iade ettik.
}
