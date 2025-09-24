#include "Simulasyon.h"
#include "DosyaOkuma.h"
#include "Yazdirma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void hesaplaHedefTarihi(ZAMAN *zaman, int mesafeSaat)
{
    int gunSayisi = mesafeSaat / 24;
    int kalanSaat = mesafeSaat % 24;

    zaman->gun += gunSayisi;
    if (zaman->gun > 30)
    {
        zaman->ay += (zaman->gun / 30);
        zaman->gun = zaman->gun % 30;
    }
    if (zaman->ay > 12)
    {
        zaman->yil += (zaman->ay / 12);
        zaman->ay = zaman->ay % 12;
    }

    printf("Hedefe varis tarihi: %02d.%02d.%04d %02d:%02d\n",
           zaman->gun, zaman->ay, zaman->yil, kalanSaat, 0);
}

GEZEGEN *findGezegenByName(GEZEGEN **gezegenler, int gezegenSayisi, const char *gezegenAdi)
{
    for (int i = 0; i < gezegenSayisi; i++)
    {
        if (strcmp(gezegenler[i]->ad, gezegenAdi) == 0)
        {
            return gezegenler[i];
        }
    }
    return NULL;
}

void guncelle(SIMULASYON *this)
{
    this->zaman->gunSayisi++;

    for (int i = 0; i < this->gezegenSayisi; i++)
    {
        GEZEGEN *g = this->gezegenler[i];
        switch (g->tur)
        {
        case 0:
            this->zaman->gunSayisi += 1;
            break;
        case 1:
            this->zaman->gunSayisi += 0.1;
            break;
        case 2:
            this->zaman->gunSayisi += 0.5;
            break;
        case 3:
            this->zaman->gunSayisi += 0.01;
            break;
        }
        g->zaman->gunSayisi = this->zaman->gunSayisi;
    }

    // 2. تحديث حالة المركبات (الوصول + IMHA)
    for (int i = 0; i < this->uzayAracSayisi; i++)
    {
        UZAYARACI *arac = &this->uzayAraclari[i];

        if (arac->mesafeSaat > 0)
        {
            arac->mesafeSaat--;

            if (arac->mesafeSaat <= 0)
            {
                arac->mesafeSaat = 0;
                arac->durum = "Vardi";
                // printf("%s varis noktasina ulasti.\n", arac->isim);  // Debug only
            }
        }

        int yasayan = 0;
        for (int j = 0; j < this->kisiSayisi; j++)
        {
            KISI *kisi = this->kisiler[j];
            if (kisi->bulunduguUzayAraci == arac && kisi->yas > 0)
            {
                yasayan++;
            }
        }

        if (yasayan == 0)
        {
            arac->durum = "IMHA";
        }
    }

    for (int i = 0; i < this->kisiSayisi; i++)
    {
        KISI *kisi = this->kisiler[i];

        if (kisi->yas > 0 && kisi->bulunduguUzayAraci != NULL)
        {
            UZAYARACI *a = kisi->bulunduguUzayAraci;
            double agingFactor = 1.0;

            if (strcmp(a->durum, "Vardi") == 0)
            {
                GEZEGEN *g = findGezegenByName(this->gezegenler, this->gezegenSayisi, a->varisGezegeni);
                if (g != NULL)
                {
                    switch (g->tur)
                    {
                    case 0:
                        agingFactor = 1.0;
                        break;
                    case 1:
                        agingFactor = 0.1;
                        break;
                    case 2:
                        agingFactor = 0.5;
                        break;
                    case 3:
                        agingFactor = 0.01;
                        break;
                    }
                }
            }

            kisi->kalanOmur -= (int)(1.0 * agingFactor);
            if (kisi->kalanOmur <= 0)
            {
                kisi->kalanOmur = 0;
                kisi->yas = 0;
            }
        }
    }

    for (int i = 0; i < this->gezegenSayisi; i++)
    {
        this->gezegenler[i]->nufus = 0;
    }

    for (int i = 0; i < this->kisiSayisi; i++)
    {
        KISI *k = this->kisiler[i];
        if (k->yas > 0 && k->bulunduguUzayAraci != NULL)
        {
            UZAYARACI *a = k->bulunduguUzayAraci;
            if (strcmp(a->durum, "Vardi") == 0)
            {
                GEZEGEN *g = findGezegenByName(this->gezegenler, this->gezegenSayisi, a->varisGezegeni);
                if (g != NULL)
                {
                    g->nufus++;
                }
            }
        }
    }

    for (int i = 0; i < this->kisiSayisi; i++)
    {
        if (this->kisiler[i]->yas <= 0)
        {
            // printf("%s öldü.\n", kisi->isim);  // Debug only
        }
    }
}

void clearConsoleBuffer()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
    DWORD consoleSize;
    COORD topLeft = {0, 0};

    GetConsoleScreenBufferInfo(hConsole, &screen);
    consoleSize = screen.dwSize.X * screen.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &written);
    FillConsoleOutputAttribute(hConsole, screen.wAttributes, consoleSize, topLeft, &written);
    SetConsoleCursorPosition(hConsole, topLeft);
}

void baslat(SIMULASYON *this)
{
    while (1)
    {
        clearConsoleBuffer();

        guncelle(this);

        printGezegenler(this->gezegenler, this->gezegenSayisi);
        printf("\n");
        printUzayAraclari(this->uzayAraclari, this->uzayAracSayisi);
        printf("\n");

        int tamamlandi = 1;
        for (int i = 0; i < this->uzayAracSayisi; i++)
        {
            if (this->uzayAraclari[i].mesafeSaat > 0)
            {
                tamamlandi = 0;
                break;
            }
        }

        if (tamamlandi)
        {
            printf("Tum uzay araclari hedeflerine ulasmistir.\n");
            break;
        }
    }
}

SIMULASYON *new_Simulasyon()
{
    SIMULASYON *simulasyon = (SIMULASYON *)malloc(sizeof(SIMULASYON));
    simulasyon->zaman = (ZAMAN *)malloc(sizeof(ZAMAN));
    simulasyon->kisiler = NULL;
    simulasyon->uzayAraclari = NULL;
    simulasyon->gezegenler = NULL;

    simulasyon->kisiSayisi = 0;
    simulasyon->uzayAracSayisi = 0;
    simulasyon->gezegenSayisi = 0;

    simulasyon->baslat = baslat;
    simulasyon->guncelle = guncelle;

    return simulasyon;
}
