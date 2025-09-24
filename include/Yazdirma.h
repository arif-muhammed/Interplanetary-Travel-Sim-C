#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include "Kisi.h"
#include "UzayAraci.h"
#include "Gezegen.h"
#include "Zaman.h"

void printKisiler(KISI **kisiler, int kisiSayisi);

void printGezegenler(GEZEGEN **gezegenler, int gezegenSayisi);

void printUzayAraclari(UZAYARACI *araclar, int aracSayisi);

void printUzayAraclari(UZAYARACI *araclar, int adet);

void printGezegenler(GEZEGEN **gezegenler, int adet);

#endif
