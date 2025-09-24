#ifndef UZAYARACI_H
#define UZAYARACI_H

typedef struct UZAYARACI
{
    char *isim;
    char *cikisGezegeni;
    char *varisGezegeni;
    char *cikisTarihi;
    int mesafeSaat;
    int toplamMesafe;
    char *durum;

    void (*setIsimUzayAraci)(struct UZAYARACI *, const char *);
    void (*setCikisGezegeni)(struct UZAYARACI *, const char *);
    void (*setVarisGezegeni)(struct UZAYARACI *, const char *);
    void (*setCikisTarihi)(struct UZAYARACI *, const char *);
    void (*setMesafeSaat)(struct UZAYARACI *, int);
    char *(*toStringUzayAraci)(struct UZAYARACI *);
} UZAYARACI;

void setIsimUzayAraci(UZAYARACI *this, const char *isim);
void setCikisGezegeni(UZAYARACI *this, const char *cikisGezegeni);
void setVarisGezegeni(UZAYARACI *this, const char *varisGezegeni);
void setCikisTarihi(UZAYARACI *this, const char *cikisTarihi);
void setMesafeSaat(UZAYARACI *this, int mesafeSaat);
char *toStringUzayAraci(UZAYARACI *this);

UZAYARACI *new_UzayAraci(const char *isim, const char *cikis, const char *varis, const char *tarih, int mesafeSaat);

#endif
