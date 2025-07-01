/**
* @file KISI.c
* @description KISI.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "KISI.h"
#include <string.h>
#include "UzayAraci.h"
#include <stdio.h>
#include <stdlib.h>

// Yapıcı fonksiyon
Kisi newKisi(const char* isim, double yas, double kalanOmur, uzayAraci arac) {
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    if (this == NULL) return NULL;

    // Alan atamaları
    this->isim = strdup(isim);
    this->yas = yas;
    this->kalan_omur = kalanOmur;
    this->bulunduguArac = arac;

    // Fonksiyon işaretçileri
    this->getIsim = &getIsim;
    this->getYas = &getYas;
    this->getKalanOmur = &getKalanOmur;
    this->getBulunduguArac = &getBulunduguArac;

    this->delete_Kisi=&delete_Kisi;
    this->setIsim = &setIsim;
    this->setYas = &setYas;
    this->setKalanOmur = &setKalanOmur;
    this->setBulunduguArac = &setBulunduguArac;
    printf("isim : %s",this->isim);
    return this;
}

// Getter fonksiyonlar
char* getIsim(const Kisi this) {
    return this->isim;
}

double getYas(const Kisi this) {
    return this->yas;
}

double getKalanOmur(const Kisi this) {
    return this->kalan_omur;
}

uzayAraci getBulunduguArac(const Kisi this) {
    return this->bulunduguArac;
}

// Setter fonksiyonlar
void setIsim(Kisi this, const char* isim) {
    free(this->isim);  // Eski ismi serbest bırak
    this->isim = strdup(isim);  // Yeni isimi ata
}

void setYas(Kisi this, double yas) {
    this->yas = yas;
}

void setKalanOmur(Kisi this, double kalanOmur) {
    this->kalan_omur = kalanOmur;
}

void setBulunduguArac(Kisi this, uzayAraci arac) {
    this->bulunduguArac = arac;
}
void delete_Kisi(Kisi this)
{
    if (this == NULL) return;

    if (this->isim != NULL) {
        free(this->isim);
        this->isim = NULL;
    }

    free(this);
}