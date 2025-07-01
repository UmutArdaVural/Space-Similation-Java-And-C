/**
* @file dosyaokuma.h
* @description dosyaokuma.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/

#ifndef GazDeviGezegen_H
#define GazDeviGezegen_H

#include "Zaman.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

struct GazDeviGezegen{
    gezegen super;
    double gezegendeAzalanOmur;
    // fonksiyon isaretcileri 
        void (*delete_GazAndGezegen)(struct GazDeviGezegen*);

};

typedef struct GazDeviGezegen* gazDeviGezegen ; 

gazDeviGezegen newGazDeviGezegen(int,char*,int,int,int,int); // zaman için ay gun yıl paremetlerini alıcaz son 3 onun için 
// ikinci paremetre isim 

// geekli fonksiyonlara 
double ggetgezegendeAzalanOmur(const gazDeviGezegen);
void delete_GazAndGezegen(gazDeviGezegen);

#endif