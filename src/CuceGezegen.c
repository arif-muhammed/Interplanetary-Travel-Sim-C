#include "CuceGezegen.h"
#include "Gezegen.h"
#include "Zaman.h"
#include <stdlib.h>
#include <string.h>

CUCE_GEZEGEN *new_CuceGezegen(char *ad, char *tarih, int gunSayisi)
{
    CUCE_GEZEGEN *this = (CUCE_GEZEGEN *)malloc(sizeof(CUCE_GEZEGEN));

    this->super.setAd = &setAd;
    this->super.setTarih = &setTarih;
    this->super.setTur = &setTur;
    this->super.setGunSayisi = &setGunSayisi;
    this->super.toStringGezegen = &toStringGezegen;

    this->super.setAd(&this->super, ad);
    this->super.setTarih(&this->super, tarih);
    this->super.setGunSayisi(&this->super, gunSayisi);
    this->super.setTur(&this->super, 3);

    this->super.zaman = new_Zaman();
    this->super.nufus = 0;

    return this;
}
