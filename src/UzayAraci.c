#include "UzayAraci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setIsimUzayAraci(UZAYARACI *this, const char *isim)
{
    this->isim = strdup(isim);
}
void setCikisGezegeni(UZAYARACI *this, const char *cikisGezegeni)
{
    this->cikisGezegeni = strdup(cikisGezegeni);
}
void setVarisGezegeni(UZAYARACI *this, const char *varisGezegeni)
{
    this->varisGezegeni = strdup(varisGezegeni);
}
void setCikisTarihi(UZAYARACI *this, const char *cikisTarihi)
{
    this->cikisTarihi = strdup(cikisTarihi);
}
void setMesafeSaat(UZAYARACI *this, int mesafeSaat)
{
    this->mesafeSaat = mesafeSaat;
    this->toplamMesafe = mesafeSaat;
}

char *toStringUzayAraci(UZAYARACI *this)
{
    char *result = (char *)malloc(256);
    snprintf(result, 256, "\n[UZAY ARACI]\nIsim: %s\nCikis: %s\nVaris: %s\nTarih: %s\nMesafe: %d\nDurum: %s",
             this->isim, this->cikisGezegeni, this->varisGezegeni, this->cikisTarihi, this->mesafeSaat, this->durum);
    return result;
}

UZAYARACI *new_UzayAraci(const char *isim, const char *cikis, const char *varis, const char *tarih, int mesafeSaat)
{
    UZAYARACI *this = (UZAYARACI *)malloc(sizeof(UZAYARACI));

    this->setIsimUzayAraci = &setIsimUzayAraci;
    this->setCikisGezegeni = &setCikisGezegeni;
    this->setVarisGezegeni = &setVarisGezegeni;
    this->setCikisTarihi = &setCikisTarihi;
    this->setMesafeSaat = &setMesafeSaat;
    this->toStringUzayAraci = &toStringUzayAraci;

    this->setIsimUzayAraci(this, isim);
    this->setCikisGezegeni(this, cikis);
    this->setVarisGezegeni(this, varis);
    this->setCikisTarihi(this, tarih);
    this->setMesafeSaat(this, mesafeSaat);
    this->durum = strdup("BEKLIYOR");

    return this;
}
