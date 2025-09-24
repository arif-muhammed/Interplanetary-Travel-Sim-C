#include "Gezegen.h"
#include "Kisi.h"
#include "Zaman.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void setAd(GEZEGEN *this, const char *ad)
{
    this->ad = strdup(ad);
}

void setTarih(GEZEGEN *this, const char *tarih)
{
    this->tarih = strdup(tarih);
}

void setTur(GEZEGEN *this, int tur)
{
    this->tur = tur;
}

void setGunSayisi(GEZEGEN *this, int gunSayisi)
{
    this->gunSayisi = gunSayisi;
}

char *toStringGezegen(GEZEGEN *this)
{
    char *result = (char *)malloc(200 * sizeof(char));
    snprintf(result, 200, "Gezegen: %s, Tarih: %s, Nüfus: %d", this->ad, this->tarih, this->nufus);
    return result;
}

GEZEGEN *new_Gezegen(char *ad, char *tarih, int gunSayisi)
{
    GEZEGEN *gezegen = (GEZEGEN *)malloc(sizeof(GEZEGEN));
    gezegen->setAd = setAd;
    gezegen->setTarih = setTarih;
    gezegen->setTur = setTur;
    gezegen->setGunSayisi = setGunSayisi;
    gezegen->toStringGezegen = toStringGezegen;
    gezegen->setAd(gezegen, ad);
    gezegen->setTarih(gezegen, tarih);
    gezegen->setGunSayisi(gezegen, gunSayisi);
    gezegen->nufus = 0;
    return gezegen;
}

void kisiEkleGezegene(KISI *kisiler, GEZEGEN *gezegen)
{
    KISI *current = kisiler;
    while (current != NULL)
    {
        if (current->kalanOmur > 0)
        {
            gezegen->kisiler[gezegen->nufus++] = current;
        }
        current = current->next;
    }
}