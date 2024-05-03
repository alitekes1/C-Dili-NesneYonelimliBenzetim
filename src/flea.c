#include "flea.h"
Flea new_Flea(int value, char *symbol)
{
    Flea this;
    this = (Flea)malloc(sizeof(Flea));
    this->super = new_Alive(value, symbol);
    return this;
}
void delete_Flea(const Flea this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->delete_Alive(this->super); // burada ilk once canli için aldığımız alanı geri iade ettik.
    free(this);                             // burada bocek için alınan alanı iade ettik.
}
