#ifndef KISI_H
#define KISI_H

#include "UzayAraci.h"

typedef struct KISI
{
    char *isim;
    int yas;
    int kalanOmur;
    struct UZAYARACI *bulunduguUzayAraci;
    struct KISI *next;

    void (*setIsimKisi)(struct KISI *, const char *);
    void (*setYas)(struct KISI *, int);
    void (*setKalanOmur)(struct KISI *, int);
    void (*setUzayAraci)(struct KISI *, struct UZAYARACI *);
    char *(*toStringKisi)(struct KISI *);
} KISI;

void setIsimKisi(KISI *this, const char *isim);
void setYas(KISI *this, int yas);
void setKalanOmur(KISI *this, int kalanOmur);
void setUzayAraci(KISI *this, struct UZAYARACI *uzayAraci);
char *toStringKisi(KISI *this);

KISI *new_Kisi(const char *isim, int yas, int kalanOmur, struct UZAYARACI *uzayAraci);

#endif
