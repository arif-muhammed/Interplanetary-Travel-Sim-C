#include "Zaman.h"
#include <stdio.h>
#include <stdlib.h>

void setTime(ZAMAN *this, int gun, int ay, int yil, int saat, int dakika, int saniye)
{
    this->gun = gun;
    this->ay = ay;
    this->yil = yil;
    this->saat = saat;
    this->dakika = dakika;
    this->saniye = saniye;
}

void updateTime(ZAMAN *this)
{
    this->saniye++;
    if (this->saniye == 60)
    {
        this->saniye = 0;
        this->dakika++;
        if (this->dakika == 60)
        {
            this->dakika = 0;
            this->saat++;
            if (this->saat == 24)
            {
                this->saat = 0;
                this->gun++;
            }
        }
    }
}

char *toStringZaman(ZAMAN *this)
{
    char *result = (char *)malloc(100 * sizeof(char));
    sprintf(result, "%02d-%02d-%04d %02d:%02d:%02d",
            this->gun, this->ay, this->yil, this->saat, this->dakika, this->saniye);
    return result;
}

ZAMAN *new_Zaman(int gun, int ay, int yil, int saat)
{
    ZAMAN *this = (ZAMAN *)malloc(sizeof(ZAMAN));
    if (this == NULL)
    {
        printf("Hata: ZAMAN icin bellek ayrilamadi.\n");
        exit(1);
    }

    this->gun = gun;
    this->ay = ay;
    this->yil = yil;
    this->saat = saat;
    this->dakika = 0;
    this->saniye = 0;

    this->setTime = &setTime;
    this->updateTime = &updateTime;
    this->toStringZaman = &toStringZaman;

    return this;
}
