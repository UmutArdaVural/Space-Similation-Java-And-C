/**
* @file buzdevigezegen.h
* @description buzdevigezegen.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#ifndef BuzDeviGezegen_H
#define BuzDeviGezegen_H

#include "Zaman.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

struct BuzDeviGezegen{
    gezegen super;
    double gezegendeAzalanOmur;
    // fonksiyon isaretcileri 
    void (*delete_BuzAndGezegen)(struct BuzDeviGezegen*);

};

typedef struct BuzDeviGezegen* buzDeviGezegen ; 

buzDeviGezegen  newBuzDeviGezegen(int,char*,int,int,int,int ); // zaman için ay gun yıl paremetlerini alıcaz son 3 onun için 
// ikinci paremetre isim 

// geekli fonksiyonlara 
double bgetgezegendeAzalanOmur(const buzDeviGezegen);
void delete_BuzAndGezegen(buzDeviGezegen);
#endif