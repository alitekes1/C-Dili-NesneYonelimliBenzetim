#include "beetle.h"
Beetle new_Beetle(int value, char *symbol, int location)
{
    Beetle this;
    this = (Beetle)malloc(sizeof(struct BEETLE));
    this->super = new_Alive(value, symbol, location);
    return this;
}
void delete_Beetle(const Beetle this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->delete_Alive(this->super); // burada ilk once canli için aldığımız alanı geri iade ettik.
    free(this);                             // burada bocek için alınan alanı iade ettik.
}
