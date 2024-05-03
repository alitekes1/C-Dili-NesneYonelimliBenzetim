#include "alive.h"

// eğer private benzetmesi yapmak istiyorsak sadece burada ilgili fonksiyonu tanımlayabiliriz.
Alive new_Alive(int value, char *symbol)
{
    Alive this;
    this = (Alive)(malloc(sizeof(struct ALIVE)));
    this->symbol = symbol;
    this->value = value;
    this->getAliveSymbol = &getAliveSymbol;
    this->setAliveSymbol = &setAliveSymbol;
    this->delete_Alive = &delete_Alive;
    return this;
}
void setAliveSymbol(const Alive this, char *symbol)
{
    this->symbol = symbol;
}
char *getAliveSymbol(const Alive this)
{
    return this->symbol;
}
void delete_Alive(const Alive this)
{
    if (this == NULL)
    {
        return;
    }
    free(this);
}

/*
eğer sadece buraya bir fonksiyon tanımlarsak private tanımlaması olur.
*/