#ifndef ZAMAN_H
#define ZAMAN_H

#include <time.h>

typedef struct ZAMAN
{
    int gun;
    int ay;
    int yil;
    int saat;
    int dakika;
    int saniye;
    int gunSayisi;

    void (*setTime)(struct ZAMAN *, int gun, int ay, int yil, int saat, int dakika, int saniye);
    void (*updateTime)(struct ZAMAN *);
    char *(*toStringZaman)(struct ZAMAN *);
} ZAMAN;

void setTime(ZAMAN *this, int gun, int ay, int yil, int saat, int dakika, int saniye);
void updateTime(ZAMAN *this);
char *toStringZaman(ZAMAN *this);

ZAMAN *new_Zaman();

#endif
