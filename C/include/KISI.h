/**
* @file kisi.h
* @description kisi.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/



#ifndef KISI_H
#define KISI_H

#include "Zaman.h"
#include "Gezegen.h"
#include "UzayAraci.h"

#include <stdio.h>
#include <stdlib.h>

struct KISI{
   char* isim;
    double yas; 
    double kalan_omur;
    uzayAraci bulunduguArac;
    // fonksiyon isaretcileri 
        char* (*getIsim)(struct KISI*);
        double (*getYas)(struct KISI*);
        double (*getKalanOmur)(struct KISI*);
        uzayAraci (*getBulunduguArac)(struct KISI*);

        void (*setIsim)(struct KISI*, const char*);
        void (*setYas)(struct KISI*, double);
        void (*setKalanOmur)(struct KISI*, double);
        void (*setBulunduguArac)(struct KISI*, uzayAraci);
        void (*delete_Kisi)(struct KISI*);

};

typedef struct KISI* Kisi ; 

 // zaman için ay gun yıl paremetlerini alıcaz son 3 onun için 
// ikinci paremetre isim 
Kisi newKisi(const char* isim, double yas, double kalanOmur, uzayAraci arac);

    // Getter fonksiyon prototipleri
    char* getIsim(const Kisi);
    double getYas(const Kisi);
    double getKalanOmur(const Kisi);
    uzayAraci getBulunduguArac(const Kisi);

    // Setter fonksiyon prototipleri
    void setIsim(Kisi, const char*);
    void setYas(Kisi, double);
    void setKalanOmur(Kisi, double);
    void setBulunduguArac(Kisi, uzayAraci);
    
    void delete_Kisi(Kisi);
#endif