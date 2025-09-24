#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H

#include "Kisi.h"
#include "UzayAraci.h"
#include "Gezegen.h"
#include "KayacGezegen.h"
#include "GazDeviGezegen.h"
#include "BuzDeviGezegen.h"
#include "CuceGezegen.h"

void kisileriOku(const char *dosyaAdi, KISI ***kisiler, int *kisiSayisi, UZAYARACI *araclar, int aracSayisi);
void uzayAraclariniOku(const char *dosyaAdi, UZAYARACI **araclar, int *aracSayisi);
void gezegenleriOku(const char *dosyaAdi, GEZEGEN **gezegenler, int *gezegenSayisi);

#endif