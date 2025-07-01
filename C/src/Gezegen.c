/**
* @file gezegen.c
* @description gezegen.c için gerekli kodların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>
#include "Zaman.h"
#include <string.h>


gezegen newGezegen(int gunKacSaat,char* isim,int gun,int ay ,int yil,int tur )
{
    gezegen this;
    this = (gezegen)malloc(sizeof(struct Gezegen));
    this->gezegenZamani = newZaman(gun,ay,yil);
    if (this->gezegenZamani == NULL) {
        printf("Zaman oluşturulamadı!\n");
        free(this);
        return NULL;
    }
    this->gunKacSaat = gunKacSaat;
    this->isim = (char*)malloc(strlen(isim) + 1);  // +1 null karakter için
    strcpy(this->isim, isim);
    this->gezegenNufusu=0;
    this->gezegentur=tur;

    // fonksiyon göstericiler  
    this->gezegenNufusSifirla = &gezegenNufusSifirla;
    this->getGezegenAdi = &getGezegenAdi;
    this->setGezegenNufusu = &setGezegenNufusu;
    this->getGunKacSaat = &getGunKacSaat;
    this->getGezegenNufusu = &getGezegenNufusu;
    this->cikarilcakOmur =&cikarilcakOmur;
    this->deleteGezegen = &deleteGezegen;
    printf("Gezegen oluşturuldu:\n");
    printf("İsim: %s\n", this->isim);
    printf("Tür: %d\n", this->gezegentur);
    printf("GünKacSaat: %d\n", this->gunKacSaat);
    printf("Gezegen Nüfusu: %d\n", this->gezegenNufusu);
    printf("Zaman - Gün: %d, Ay: %d, Yıl: %d\n", this->gezegenZamani->gun, this->gezegenZamani->ay, this->gezegenZamani->yil);
    printf("Zaman - Saat: %d\n", this->gezegenZamani->saat);

    return this;
}
void deleteGezegen(gezegen this)
{
    if (this == NULL) return;

    // 1. Zaman nesnesini serbest bırak
    if (this->gezegenZamani != NULL) {
        this->gezegenZamani->Yoket(this->gezegenZamani);
    }

    // 2. İsim için ayrılan belleği serbest bırak
    if (this->isim != NULL) {
        free(this->isim);
    }

    // 3. Gezegen yapısının kendisini serbest bırak
    free(this);
}
//public fonksiyonlar 
void gezegenNufusSifirla(const gezegen this)
{
    this->gezegenNufusu = 0;
}

char* getGezegenAdi(const gezegen this)
{
    return this->isim;
}

void setGezegenNufusu(const gezegen this)
{
    this->gezegenNufusu++;
}

int getGunKacSaat(const gezegen this)
{
    return this->gunKacSaat;
}

int getGezegenNufusu(const gezegen this)
{
    return this->gezegenNufusu;
}
double cikarilcakOmur(const gezegen this , void*p)
{
    return this->getgezegendeAzalanOmur(p);
}
