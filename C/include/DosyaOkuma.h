/**
* @file dosyaokuma.h
* @description dosyaokuma.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/

#ifndef DosyaOkuma_H
#define DosyaOkuma_H

#include "Zaman.h"
#include "KISI.h"
#include "UzayAraci.h"
#include "BuzDeviGezegen.h"
#include "CuceGezegen.h"
#include "GazDeviGezegen.h"
#include "KayacGezegen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DosyaOkuma {
    // Gerekli dosya adlarını tutan alanlar
    char* dosyaGezegenler;
    char* dosyaAraclar;
    char* dosyaKisiler;

    


    int    satirSayisiGezegen;
    int    satirSayisiUzayAraci;
    int    satirSayisiKisiler;

    // Dizileri tutacak işaretçiler
    gezegen* gezegenler;  // Gezegen dizisi
    uzayAraci* araclar;    // Uzay aracı dizisi
    Kisi* kisiler;         // Kisi dizisi

    // alt gezegen sayilari 
    int    satirSayisiGezegen0;
    int    satirSayisiGezegen1;
    int    satirSayisiGezegen2;
    int    satirSayisiGezegen3;


    // alt gezegenlerin dizileri 
    buzDeviGezegen* dizibuzdevi;
    cuceGezegen* dizicuce;
    gazDeviGezegen* dizigaz;
    kayacGezegen* dizikayac;

    int (*satirSayisiniHesaplaAltGezegen)(struct DosyaOkuma*,const char* ,int);


    // Fonksiyon işaretçileri
    void (*dosyaOkumaBaslat)(struct DosyaOkuma*);
    void (*gezegenOku)(struct DosyaOkuma*);
    void (*aracOku)(struct DosyaOkuma*);
    void (*kisiOku)(struct DosyaOkuma*);
    
    int (*satirSayisiniHesapla)(struct DosyaOkuma*,const char* );

    void (*gezegenDizisiniOlustur)(struct DosyaOkuma*, int);
    void (*aracDizisiniOlustur)(struct DosyaOkuma*, int);
    void (*kisiDizisiniOlustur)(struct DosyaOkuma*, int);

    gezegen (*gezegenBul)(struct DosyaOkuma*, char*);
    uzayAraci (*uzayAraciBul)(struct DosyaOkuma*, char*);

    void (*gezegenDizisiniSerbestBirak)(struct DosyaOkuma*);
    void (*aracDizisiniSerbestBirak)(struct DosyaOkuma*);
    void (*kisiDizisiniSerbestBirak)(struct DosyaOkuma*);
    void (*delete_DosyaOkuma)(struct DosyaOkuma*);

};

typedef struct DosyaOkuma* dosyaOkuma; 
dosyaOkuma newDosyaOkuma();

// Fonksiyon imzaları
void dosyaOkumaBaslat(const dosyaOkuma); // Dosyaları başlatmak ve işlevleri çağırmak için
void gezegenOku(const dosyaOkuma);       // Gezegenleri okumak
void aracOku(const dosyaOkuma);          // Araçları okumak
void kisiOku(const dosyaOkuma);          // Kişileri okumak


int satirSayisiniHesapla(const dosyaOkuma,const char* );        // Dosyada kaç satır olduğunu hesaplamak

// Dizileri yönetme fonksiyonları
void gezegenDizisiniOlustur(const dosyaOkuma, int); // Gezegen dizisini oluştur
void aracDizisiniOlustur(const dosyaOkuma, int);    // Uzay aracı dizisini oluştur
void kisiDizisiniOlustur(const dosyaOkuma, int);    // Kisi dizisini oluştur

// bulma fonksiyonları 
gezegen gezegenBul(const dosyaOkuma,char* );
uzayAraci uzayAraciBul(const dosyaOkuma,char* );


// Bellek temizlik fonksiyonları
void gezegenDizisiniSerbestBirak(dosyaOkuma);
void aracDizisiniSerbestBirak(dosyaOkuma);
void kisiDizisiniSerbestBirak(dosyaOkuma);
void delete_DosyaOkuma(dosyaOkuma);

int satirSayisiniHesaplaAltGezegen( dosyaOkuma,const char* ,int);


#endif