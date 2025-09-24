#include "DosyaOkuma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kisileriOku(const char *dosyaAdi, KISI ***kisiler, int *kisiSayisi, UZAYARACI *araclar, int aracSayisi)
{
    FILE *fp = fopen(dosyaAdi, "r");
    if (!fp)
    {
        printf("Dosya acilamadi: %s\n", dosyaAdi);
        exit(1);
    }

    char satir[256];
    int kapasite = 10;
    *kisiler = (KISI **)malloc(kapasite * sizeof(KISI *));
    *kisiSayisi = 0;

    while (fgets(satir, sizeof(satir), fp))
    {
        char isim[50], uzayAraciAdi[50];
        int yas, kalanOmur;
        sscanf(satir, "%[^#]#%d#%d#%[^#\n]", isim, &yas, &kalanOmur, uzayAraciAdi);

        if (*kisiSayisi >= kapasite)
        {
            kapasite *= 2;
            *kisiler = (KISI **)realloc(*kisiler, kapasite * sizeof(KISI *));
        }

        UZAYARACI *bagliArac = NULL;
        for (int i = 0; i < aracSayisi; i++)
        {
            if (strcmp(araclar[i].isim, uzayAraciAdi) == 0)
            {
                bagliArac = &araclar[i];
                break;
            }
        }

        (*kisiler)[*kisiSayisi] = new_Kisi(isim, yas, kalanOmur, bagliArac);
        (*kisiSayisi)++;
    }

    fclose(fp);
}

void uzayAraclariniOku(const char *dosyaAdi, UZAYARACI **araclar, int *aracSayisi)
{
    FILE *fp = fopen(dosyaAdi, "r");
    if (!fp)
    {
        printf("Dosya acilamadi: %s\n", dosyaAdi);
        exit(1);
    }

    char satir[256];
    int kapasite = 10;
    *araclar = (UZAYARACI *)malloc(kapasite * sizeof(UZAYARACI));
    *aracSayisi = 0;

    while (fgets(satir, sizeof(satir), fp))
    {
        char isim[50], cikis[50], varis[50], tarih[50];
        int mesafe;
        sscanf(satir, "%[^#]#%[^#]#%[^#]#%[^#]#%d", isim, cikis, varis, tarih, &mesafe);

        if (*aracSayisi >= kapasite)
        {
            kapasite *= 2;
            *araclar = (UZAYARACI *)realloc(*araclar, kapasite * sizeof(UZAYARACI));
        }

        (*araclar)[*aracSayisi] = *new_UzayAraci(isim, cikis, varis, tarih, mesafe);
        (*aracSayisi)++;
    }

    fclose(fp);
}

void gezegenleriOku(const char *dosyaAdi, GEZEGEN **gezegenler, int *gezegenSayisi)
{
    FILE *fp = fopen(dosyaAdi, "r");
    if (!fp)
    {
        printf("Dosya acilamadi: %s\n", dosyaAdi);
        exit(1);
    }

    char satir[256];
    int kapasite = 10;
    *gezegenler = (GEZEGEN *)malloc(kapasite * sizeof(GEZEGEN));
    *gezegenSayisi = 0;

    while (fgets(satir, sizeof(satir), fp))
    {
        char ad[50], tarih[50];
        int tur, gunSayisi;
        sscanf(satir, "%[^#]#%d#%d#%[^#\n]", ad, &tur, &gunSayisi, tarih);

        GEZEGEN *yeniGezegen = NULL;
        switch (tur)
        {
        case 0:
            yeniGezegen = (GEZEGEN *)new_KayacGezegen(ad, tarih, gunSayisi);
            break;
        case 1:
            yeniGezegen = (GEZEGEN *)new_GazDeviGezegen(ad, tarih, gunSayisi);
            break;
        case 2:
            yeniGezegen = (GEZEGEN *)new_BuzDeviGezegen(ad, tarih, gunSayisi);
            break;
        case 3:
            yeniGezegen = (GEZEGEN *)new_CuceGezegen(ad, tarih, gunSayisi);
            break;
        default:
            printf("Bilinmeyen gezegen turu: %d\n", tur);
            continue;
        }

        if (*gezegenSayisi >= kapasite)
        {
            kapasite *= 2;
            *gezegenler = (GEZEGEN *)realloc(*gezegenler, kapasite * sizeof(GEZEGEN));
        }

        (*gezegenler)[*gezegenSayisi] = *yeniGezegen;
        (*gezegenSayisi)++;
    }

    fclose(fp);
}
