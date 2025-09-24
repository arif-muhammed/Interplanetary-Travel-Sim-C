#ifndef SIMULASYON_H
#define SIMULASYON_H

#include "Zaman.h"
#include "Kisi.h"
#include "UzayAraci.h"
#include "Gezegen.h"

typedef struct SIMULASYON
{
    ZAMAN *zaman;
    KISI **kisiler;
    int kisiSayisi;

    UZAYARACI *uzayAraclari;
    int uzayAracSayisi;

    GEZEGEN **gezegenler;
    int gezegenSayisi;

    void (*baslat)(struct SIMULASYON *);
    void (*guncelle)(struct SIMULASYON *);
} SIMULASYON;

SIMULASYON *new_Simulasyon();
void baslat(SIMULASYON *this);
void guncelle(SIMULASYON *this);

GEZEGEN *findGezegenByName(GEZEGEN **gezegenler, int gezegenSayisi, const char *gezegenAdi);

#endif
