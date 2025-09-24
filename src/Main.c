#include <stdio.h>
#include <stdlib.h>
#include "Simulasyon.h"
#include "DosyaOkuma.h"
#include "Yazdirma.h"

int main()
{
    SIMULASYON *simulasyon = new_Simulasyon();

    UZAYARACI *araclar = NULL;
    int aracSayisi = 0;
    uzayAraclariniOku("Araclar.txt", &araclar, &aracSayisi);
    simulasyon->uzayAraclari = araclar;
    simulasyon->uzayAracSayisi = aracSayisi;

    KISI **kisiler = NULL;
    int kisiSayisi = 0;
    kisileriOku("Kisiler.txt", &kisiler, &kisiSayisi, araclar, aracSayisi);
    simulasyon->kisiler = kisiler;
    simulasyon->kisiSayisi = kisiSayisi;

    GEZEGEN *gezegenler = NULL;
    int gezegenSayisi = 0;
    gezegenleriOku("Gezegenler.txt", &gezegenler, &gezegenSayisi);
    simulasyon->gezegenler = (GEZEGEN **)malloc(gezegenSayisi * sizeof(GEZEGEN *));
    for (int i = 0; i < gezegenSayisi; i++)
    {
        simulasyon->gezegenler[i] = &gezegenler[i];
    }
    simulasyon->gezegenSayisi = gezegenSayisi;

    simulasyon->baslat(simulasyon);

    for (int i = 0; i < kisiSayisi; i++)
        free(kisiler[i]);
    free(kisiler);
    free(araclar);
    free(gezegenler);
    free(simulasyon->zaman);
    free(simulasyon);

    return 0;
}
