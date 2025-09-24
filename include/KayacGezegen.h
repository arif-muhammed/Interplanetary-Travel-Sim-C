#ifndef KAYAC_GEZEGEN_H
#define KAYAC_GEZEGEN_H

#include "Gezegen.h"

typedef struct KAYAC_GEZEGEN
{
    GEZEGEN super;
} KAYAC_GEZEGEN;

KAYAC_GEZEGEN *new_KayacGezegen(char *ad, char *tarih, int gunSayisi);
char *toString_KayacGezegen(KAYAC_GEZEGEN *this);

#endif
