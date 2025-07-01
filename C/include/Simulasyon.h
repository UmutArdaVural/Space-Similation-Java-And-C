/**
* @file simulasyon.h
* @description simulasyon.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#ifndef Simulasyon_H
#define Simulasyon_H

#include "Zaman.h"
#include "Gezegen.h"
#include "DosyaOkuma.h"
#include "BuzDeviGezegen.h"
#include "CuceGezegen.h"
#include "GazDeviGezegen.h"
#include "KayacGezegen.h"

#include <stdio.h>
#include <stdlib.h>

struct Simulasyon{
   
    char* durum1Imha  ;
    char* durum2ImhaDegil  ;
    dosyaOkuma dosya;
      char* konum1  ;
      char* konum2  ;
      char* konum3 ;

    buzDeviGezegen buz;
    cuceGezegen cuce;
    gazDeviGezegen gaz;
    kayacGezegen kayac;

    // fonksiyon isaretcileri 
    void (*eventSimilation)( struct Simulasyon* ); // her döngüde çalışacak ana fonksiyon diğer fonksiyonlar bunu altında olucak 
void (*saatArtisi)( struct Simulasyon*);
void (*yaslariAzalt)(struct Simulasyon*);
void (*AraclariKontrolEt)(struct Simulasyon*);
void (*konumIslemleri)(struct Simulasyon*);
void (*gezegenNufusuAyarla)(struct Simulasyon*);
void (*ekranaYaz)( struct Simulasyon*);
int (*programBittimi)(struct Simulasyon*);
void (*delete_Simulation)(struct Simulasyon*);

};
typedef struct Simulasyon* simulasyon ; 

simulasyon newSimulasyon(dosyaOkuma );

void eventSimilation( simulasyon ); // her döngüde çalışacak ana fonksiyon diğer fonksiyonlar bunu altında olucak 
void saatArtisi( simulasyon);
void yaslariAzalt( simulasyon);
void AraclariKontrolEt( simulasyon);
void konumIslemleri( simulasyon);
void gezegenNufusuAyarla( simulasyon);
void ekranaYaz( simulasyon);
int programBittimi( simulasyon);
void delete_Simulation(simulasyon);
// gerekli fonksiyonlar 

#endif