#include "plant.h"

Plant new_plant(int value, char *symbol)
{
    Plant this;
    this = (Plant)malloc(sizeof(struct PLANT));
    this->delete_plant = &delete_plant;
    this->super = new_Alive(value, symbol);
    // eğer soyut sınıfımız olsaydı burada this/super/soyutsınıf a
    // aşağıda gövdesini yazdığımız fonksiyonu atardık.
    return this;
}
void delete_plant(const Plant this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->delete_Alive(this->super);
    free(this);
}