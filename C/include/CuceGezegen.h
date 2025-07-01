/**
* @file cucegezegen.h
* @description cucegezegen.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/

#ifndef CuceGezegen_H
#define CuceGezegen_H

#include "Zaman.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

struct CuceGezegen{
    gezegen super;
    double gezegendeAzalanOmur;
    // fonksiyon isaretcileri 
    void (*delete_CuceAndGezegen)(struct CuceGezegen*);

};

typedef struct CuceGezegen* cuceGezegen ; 

cuceGezegen newCuceGezegen(int,char*,int,int,int,int); // zaman için ay gun yıl paremetlerini alıcaz son 3 onun için 
// ikinci paremetre isim 

// geekli fonksiyonlara 
double cgetgezegendeAzalanOmur(const cuceGezegen);
void delete_CuceAndGezegen( cuceGezegen);

#endif