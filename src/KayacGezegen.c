#include "KayacGezegen.h"
#include "Gezegen.h"
#include "Zaman.h"
#include <stdlib.h>
#include <string.h>

KAYAC_GEZEGEN *new_KayacGezegen(char *ad, char *tarih, int gunSayisi)
{
    KAYAC_GEZEGEN *this = (KAYAC_GEZEGEN *)malloc(sizeof(KAYAC_GEZEGEN));

    this->super.setAd = &setAd;
    this->super.setTarih = &setTarih;
    this->super.setTur = &setTur;
    this->super.setGunSayisi = &setGunSayisi;
    this->super.toStringGezegen = &toStringGezegen;

    this->super.setAd(&this->super, ad);
    this->super.setTarih(&this->super, tarih);
    this->super.setGunSayisi(&this->super, gunSayisi);
    this->super.setTur(&this->super, 0);

    this->super.zaman = new_Zaman();
    this->super.nufus = 0;

    return this;
}