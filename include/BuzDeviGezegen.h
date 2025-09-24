#ifndef BUZ_DEVI_GEZEGEN_H
#define BUZ_DEVI_GEZEGEN_H

#include "Gezegen.h"

typedef struct BUZ_DEVI_GEZEGEN
{
    GEZEGEN super;
} BUZ_DEVI_GEZEGEN;

BUZ_DEVI_GEZEGEN *new_BuzDeviGezegen(char *ad, char *tarih, int gunSayisi);
char *toString_BuzDeviGezegen(BUZ_DEVI_GEZEGEN *this);

#endif
