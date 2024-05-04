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
    this->setSize = &setSize;
    this->yemeIslemleri = &yemeIslemleri;
    this->assignAliveToHabitat = &assignAliveToHabitat;
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
void setSize(const Habitat this, int size)
{
    this->size = size;
}
void delete_Habitat(const Habitat this)
{
}
void deneme(const Habitat this, char *pointerSymbol, char *currentSymbol, Alive *pointer, Alive *currentAlive, char *yiyebildikleri1, char *yiyebildikleri2)
{
    if (pointerSymbol == yiyebildikleri1 || pointerSymbol == yiyebildikleri2)
    {
        // bitki yeme hakkına sahip
        (*pointer)->setAliveSymbol("X");
    }
    else if (pointerSymbol == currentSymbol)
    {
        // benzer türde eleman geldi. diğer koşullara bakmak gerekiyor.
        if ((*currentAlive)->value > (*pointer)->value)
        {
            (*pointer)->setAliveSymbol("X");
        }
        else if ((*currentAlive)->value < (*pointer)->value)
        {
            (*currentAlive)->setAliveSymbol("X");
        }
        else
        {
            // konumlarına bakılacak.
        }
    }
    else
    {
        (*currentAlive)->setAliveSymbol("X");
        // bitki yeme hakkına sahip değil. yani böcek geldi.bitki yenilecek.
        currentAlive = pointer;
    }
}
void yemeIslemleri(const Habitat this)
{
    Alive *currentAlive = this->allAlives[0];
    Alive *pointer = this->allAlives[1];
    int counter = 0;
    while (counter != this->size)
    {
        if ((*currentAlive)->symbol == "X")
        {
            currentAlive++;
        }
        char *currentSymbol = (*currentAlive)->symbol;
        switch (currentSymbol)
        {
            char *pointerSymbol = (*pointer)->symbol;
        case "B":
            deneme(this, pointerSymbol, currentSymbol, pointer, currentAlive, "P", "S");
            break;
        case "C":
            deneme(this, pointerSymbol, currentSymbol, pointer, currentAlive, "B", "P");
            break;
        case "S":
            deneme(this, pointerSymbol, currentSymbol, pointer, currentAlive, "P", "C");
            break;
        case "P":
            deneme(this, pointerSymbol, currentSymbol, pointer, currentAlive, "A", "A");
            break;
        default:
            break;
        }
        pointer++;
    }
}

void showHabitat(const Habitat this)
{
    for (int i = 0; i < this->size; i++)
    {
        Alive *currentAlive = this->allAlives[i];
        if (i % (this->col) == 0)
        {
            printf("\n");
        }
        printf("%s(%d) ", (*currentAlive)->symbol, (*currentAlive)->value);
    }
}
void assignAliveToHabitat(const Habitat this)
{
    for (int i = 0; i < this->size; i++)
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

    this->setRow(this, row);
    this->setCol(this, counterNumber / row);
    this->setSize(this, counterNumber);

    printf("toplam sayi adedi: %d\n", counterNumber);

    this->allAlives = (Alive **)malloc(this->size * sizeof(Alive *));
    this->assignAliveToHabitat(this);
}