#include "Kisi.h"
#include "UzayAraci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setUzayAraci(KISI *this, struct UZAYARACI *uzayAraci)
{
    this->bulunduguUzayAraci = uzayAraci;
}

KISI *new_Kisi(const char *isim, int yas, int kalanOmur, struct UZAYARACI *uzayAraci)
{
    KISI *this = (KISI *)malloc(sizeof(KISI));
    this->isim = strdup(isim);
    this->yas = yas;
    this->kalanOmur = kalanOmur;
    this->bulunduguUzayAraci = uzayAraci;
    this->setUzayAraci = setUzayAraci;
    return this;
}

char *toStringKisi(KISI *this)
{
    char *result = (char *)malloc(200 * sizeof(char));
    snprintf(result, 200, "\n[KISI]\nIsim: %s\nYas: %d\nKalan Omur: %d\nUzay Araci: %s",
             this->isim, this->yas, this->kalanOmur, this->bulunduguUzayAraci ? this->bulunduguUzayAraci->isim : "None");
    return result;
}
