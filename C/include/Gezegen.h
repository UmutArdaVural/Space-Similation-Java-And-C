/**
* @file gezegen.h
* @description gezegen.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#ifndef Gezegen_H
#define Gezegen_H

#include "Zaman.h"
#include <stdio.h>
#include <stdlib.h>

struct Gezegen{
    zaman gezegenZamani;
    int gezegentur;
    char* isim;
    int gunKacSaat;
    
     // burada zaman yapısını kullandık  
    int gezegenNufusu;

    // fonksiyon isaretcileri 
    void    (*gezegenNufusSifirla)(struct Gezegen*);
    char*   (*getGezegenAdi)(struct Gezegen*);
    void    (*setGezegenNufusu)(struct Gezegen*);
    int     (*getGunKacSaat)(struct Gezegen*);
    int     (*getGezegenNufusu)(struct Gezegen*);
    double (*getgezegendeAzalanOmur)(); // soyu sınıf benzetmesi için boş bırakıldı 
    double  (*cikarilcakOmur)(struct Gezegen*,void *);
    void (*deleteGezegen)(struct Gezegen*);
};

typedef struct Gezegen*gezegen ; 

gezegen newGezegen(int,char*,int,int,int,int); // zaman için ay gun yıl paremetlerini alıcaz son 3 onun için 

// geekli fonksiyonlara 
// 1 gezegen nufusu sıfırla 
// 2 get gezegen adı 
// 3 get gezegende geçen zaman 

void gezegenNufusSifirla(const gezegen);
char* getGezegenAdi(const gezegen);
void setGezegenNufusu(const gezegen);
int getGunKacSaat(const gezegen);
int getGezegenNufusu(const gezegen);
double cikarilcakOmur(const gezegen, void*);
void deleteGezegen(gezegen);

#endif