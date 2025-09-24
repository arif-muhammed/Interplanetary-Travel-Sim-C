#ifndef GEZEGEN_H
#define GEZEGEN_H

#include "Zaman.h"
#include "Kisi.h"

typedef struct GEZEGEN
{
    char *ad;
    char *tarih;
    int tur;
    int gunSayisi;
    int nufus;
    KISI **kisiler;
    ZAMAN *zaman;

    void (*setAd)(struct GEZEGEN *, const char *);
    void (*setTarih)(struct GEZEGEN *, const char *);
    void (*setTur)(struct GEZEGEN *, int);
    void (*setGunSayisi)(struct GEZEGEN *, int);
    char *(*toStringGezegen)(struct GEZEGEN *);
} GEZEGEN;

void setAd(GEZEGEN *this, const char *ad);
void setTarih(GEZEGEN *this, const char *tarih);
void setTur(GEZEGEN *this, int tur);
void setGunSayisi(GEZEGEN *this, int gunSayisi);
char *toStringGezegen(GEZEGEN *this);
GEZEGEN *new_Gezegen(char *ad, char *tarih, int gunSayisi);

#endif
