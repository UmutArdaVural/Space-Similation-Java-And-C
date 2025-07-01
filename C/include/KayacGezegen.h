/**
* @file kayacgezgen.h
* @description kayacgezgen.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/



#ifndef KayacGezegen_H
#define KayacGezegen_H

#include "Zaman.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

struct KayacGezegen{
    gezegen super;
    double gezegendeAzalanOmur;
    // fonksiyon isaretcileri 
            void (*delete_KayacAndGezegen)(struct KayacGezegen*);

};

typedef struct KayacGezegen* kayacGezegen ; 

kayacGezegen newKayacGezegen(int,char*,int,int,int,int); // zaman için ay gun yıl paremetlerini alıcaz son 3 onun için 
// ikinci paremetre isim 

// geekli fonksiyonlara 
double kgetgezegendeAzalanOmur(const kayacGezegen);
void delete_KayacAndGezegen(kayacGezegen );

#endif