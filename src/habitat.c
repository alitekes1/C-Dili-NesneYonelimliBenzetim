#include "habitat.h"

Habitat new_Habitat()
{
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));

    this->setRow = &setRow;
    this->setCol = &setCol;
    this->showHabitat = &showHabitat;
    this->delete_Habitat = &delete_Habitat;
    this->readFile = &readFile;
    return this;
}
void setRow(const Habitat this, int row)
{
    this->row = row;
}
void setCol(const Habitat this, int col)
{
    this->col = col;
}
void delete_Habitat(const Habitat this)
{
}
void yemeIslemleri(const Habitat this)
{
    Alive *currentAlive = this->allAlives[0];

    printf("deger:%d - sembol:%s", (*currentAlive)->value, (*currentAlive)->symbol);
    
}
void showHabitat(const Habitat this)
{
    for (int i = 0; i < this->row * this->col; i++)
    {
        Alive *currentAlive = this->allAlives[i];
        if (i % (this->col) == 0)
        {
            printf("\n");
        }
        printf("%s ", (*currentAlive)->symbol);
    }
    yemeIslemleri(this);
}
void assignAliveToHabitat(const Habitat this)
{
    for (int i = 0; i < this->row * this->col; i++)
    {
        int number = this->values[i];
        if (number > 0 && number < 10)
        {
            Plant plant = new_plant(number, "B");
            this->allAlives[i] = (Alive *)plant;
        }
        else if (number > 9 && number < 21)
        {
            Beetle beetle = new_Beetle(number, "C");
            this->allAlives[i] = (Alive *)beetle;
        }
        else if (number > 20 && number < 51)
        {
            Fly fly = new_Fly(number, "S");
            this->allAlives[i] = (Alive *)fly;
        }
        else if (number > 50 && number < 100)
        {
            Flea flea = new_Flea(number, "P");
            this->allAlives[i] = (Alive *)flea;
        }
        else
        {
            printf("Sayi 100 den kucuk olmali");
            i--;
        }
    }
}

void readFile(Habitat this, char *filepath)
{
    FILE *file;

    file = fopen(filepath, "r");
    char ch;
    int row = 0;
    while (!feof(file))
    {
        ch = getc(file);
        if (ch == '\n')
        {
            row++;
        }
    }
    fclose(file);

    file = fopen(filepath, "r");
    int number;
    int counterNumber = 0;
    while (fscanf(file, "%d", &number) == 1)
    {
        counterNumber++; // toplam sayı adedini aldık
    }
    fclose(file);
    //
    this->values = (int *)malloc(sizeof(int) * counterNumber); // toplam sayı kadar bellekten yer aldık
    file = fopen(filepath, "r");
    int i = 0;
    while (fscanf(file, "%d", &number) == 1)
    {
        this->values[i++] = number; // dosyadaki değerleri habitat taki değerleri dizisine aktardık.
    }
    fclose(file);

    setRow(this, row);
    setCol(this, counterNumber / row);
    printf("toplam sayi adedi: %d", counterNumber);

    this->allAlives = (Alive **)malloc(this->row * this->col * sizeof(Alive *));
    assignAliveToHabitat(this);
}