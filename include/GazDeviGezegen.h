#ifndef GAZ_DEVI_GEZEGEN_H
#define GAZ_DEVI_GEZEGEN_H

#include "Gezegen.h"

typedef struct GAZ_DEVI_GEZEGEN
{
    GEZEGEN super;
} GAZ_DEVI_GEZEGEN;

GAZ_DEVI_GEZEGEN *new_GazDeviGezegen(char *ad, char *tarih, int gunSayisi);
char *toString_GazDeviGezegen(GAZ_DEVI_GEZEGEN *this);

#endif
