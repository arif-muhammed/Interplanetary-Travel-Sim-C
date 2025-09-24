#include "Yazdirma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 16

int getDaysInMonth(int ay, int yil)
{
    switch (ay)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if ((yil % 4 == 0 && yil % 100 != 0) || (yil % 400 == 0))
            return 29;
        else
            return 28;
    default:
        return 30;
    }
}

void printGezegenler(GEZEGEN **gezegenler, int adet)
{
    printf("Gezegenler:\n\n");

    printf("%-*s", WIDTH, "");
    for (int i = 0; i < adet; i++)
    {
        printf("--- %-*s", WIDTH - 8, gezegenler[i]->ad);
    }
    printf("\n");

    printf("%-*s", WIDTH, "Tarih");
    for (int i = 0; i < adet; i++)
    {
        printf("%-*s", WIDTH, gezegenler[i]->tarih);
    }
    printf("\n");

    printf("%-*s", WIDTH, "Nufus");
    for (int i = 0; i < adet; i++)
    {
        printf("%-*d", WIDTH, gezegenler[i]->nufus);
    }
    printf("\n\n");
}

void printUzayAraclari(UZAYARACI *araclar, int adet)
{
    printf("Uzay Araclari:\n\n");

    printf("%-*s%-*s%-*s%-*s%-*s%s\n",
           WIDTH, "Arac Adi",
           WIDTH, "Durum",
           WIDTH, "Cikis",
           WIDTH, "Varis",
           WIDTH, "Hedefe Kalan Saat",
           "Hedefe Varacagi Tarih");

    for (int i = 0; i < adet; i++)
    {
        UZAYARACI a = araclar[i];

        const char *tarih = (strcmp(a.durum, "IMHA") == 0) ? "--" : a.cikisTarihi;

        char kalanBuffer[12];
        if (strcmp(a.durum, "IMHA") == 0)
            strcpy(kalanBuffer, "--");
        else
            sprintf(kalanBuffer, "%d", a.mesafeSaat);

        printf("%-*s%-*s%-*s%-*s%-*s%s\n",
               WIDTH, a.isim,
               WIDTH, a.durum,
               WIDTH, a.cikisGezegeni,
               WIDTH, a.varisGezegeni,
               WIDTH, kalanBuffer,
               tarih);
    }

    printf("\n");
}
