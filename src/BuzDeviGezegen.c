#include "BuzDeviGezegen.h"
#include "Gezegen.h"
#include "Zaman.h"
#include <stdlib.h>
#include <string.h>

BUZ_DEVI_GEZEGEN *new_BuzDeviGezegen(char *ad, char *tarih, int gunSayisi)
{
    BUZ_DEVI_GEZEGEN *this = (BUZ_DEVI_GEZEGEN *)malloc(sizeof(BUZ_DEVI_GEZEGEN));

    this->super.setAd = &setAd;
    this->super.setTarih = &setTarih;
    this->super.setTur = &setTur;
    this->super.setGunSayisi = &setGunSayisi;
    this->super.toStringGezegen = &toStringGezegen;

    this->super.setAd(&this->super, ad);
    this->super.setTarih(&this->super, tarih);
    this->super.setGunSayisi(&this->super, gunSayisi);
    this->super.setTur(&this->super, 2); // كوكب جليدي

    this->super.zaman = new_Zaman();
    this->super.nufus = 0;
    this->super.kisiler = (KISI **)malloc(100 * sizeof(KISI *));

    return this;
}

char *toString_BuzDeviGezegen(BUZ_DEVI_GEZEGEN *this)
{
    return toStringGezegen(&this->super);
}
