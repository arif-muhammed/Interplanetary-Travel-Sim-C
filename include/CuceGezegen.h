#ifndef CUCE_GEZEGEN_H
#define CUCE_GEZEGEN_H

#include "Gezegen.h"

typedef struct CUCE_GEZEGEN
{
    GEZEGEN super;
} CUCE_GEZEGEN;

CUCE_GEZEGEN *new_CuceGezegen(char *ad, char *tarih, int gunSayisi);
char *toString_CuceGezegen(CUCE_GEZEGEN *this);

#endif
