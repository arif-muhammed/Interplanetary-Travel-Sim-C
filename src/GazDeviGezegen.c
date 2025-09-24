#include "GazDeviGezegen.h"
#include "Gezegen.h"
#include "Zaman.h"
#include <stdlib.h>
#include <string.h>

GAZ_DEVI_GEZEGEN *new_GazDeviGezegen(char *ad, char *tarih, int gunSayisi)
{
    GAZ_DEVI_GEZEGEN *this = (GAZ_DEVI_GEZEGEN *)malloc(sizeof(GAZ_DEVI_GEZEGEN));

    this->super.setAd = &setAd;
    this->super.setTarih = &setTarih;
    this->super.setTur = &setTur;
    this->super.setGunSayisi = &setGunSayisi;
    this->super.toStringGezegen = &toStringGezegen;

    this->super.setAd(&this->super, ad);
    this->super.setTarih(&this->super, tarih);
    this->super.setGunSayisi(&this->super, gunSayisi);
    this->super.setTur(&this->super, 1);

    this->super.zaman = new_Zaman();
    this->super.nufus = 0;
    this->super.kisiler = (KISI **)malloc(100 * sizeof(KISI *));

    return this;
}

char *toString_GazDeviGezegen(GAZ_DEVI_GEZEGEN *this)
{
    return toStringGezegen(&this->super);
}
