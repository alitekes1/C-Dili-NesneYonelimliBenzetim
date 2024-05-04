#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ekranaBas(int *dizi, int boyut)
{
    for (int i = 0; i < boyut * boyut; i++)
    {
        if (i % boyut == 0)
        {
            printf("\n");
        }
        // int sayi = dizi[i];
        // if (sayi > 0 && sayi < 10)
        // {
        //     dizi[i] = 0;
        // }
        // else if (sayi > 9 && sayi < 21)
        // {
        //     dizi[i] = 1;
        // }
        // else if (sayi > 20 && sayi < 51)
        // {
        //     dizi[i] = 2;
        // }
        // else if (sayi > 50 && sayi < 100)
        // {
        //     dizi[i] = 3;
        // }
        printf("%d ", dizi[i]);
    }
}
int main()
{
    int boyut = 0;
    printf("dizi boyutu:");
    scanf("%d", &boyut);
    srand(time(NULL));
    int *dizi = malloc(sizeof(int) * boyut * boyut);
    for (int i = 0; i < boyut * boyut; i++)
    {
        dizi[i] = rand() % 100;
    }
    ekranaBas(dizi, boyut);
    int *pointer = dizi + 1; // dizinin 2.elemanını temsil ediyor.
    int counter = 0;
    // int dizisayac = 0;
    while (counter != boyut * boyut)
    {
        // printf("\n %d) pointer in degeri:%d dizinin degeri: %d\n", counter, *pointer, dizi[counter]);
        // karar verme kısmı burası bunu ödevde farklı bir karar verme algoritmasıyla yapacağız. ondan sonrası basit.
        if (*pointer > dizi[counter])
        {
            dizi[counter] = -1;
        }
        else
        {
            *pointer = -1;
            pointer = &dizi[counter];
        }
        counter++;
        ekranaBas(dizi, boyut);
        system("cls");
    }
    printf("\n-------\n");
    ekranaBas(dizi, boyut);
    free(dizi);
    return 0;
}