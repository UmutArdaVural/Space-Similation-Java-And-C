/**
* @file uzayaraci.h
* @description uzayaraci.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/



#ifndef UzayAraci_H
#define UzayAraci_H

#include "Zaman.h"
#include "Gezegen.h"

#include <stdio.h>
#include <stdlib.h>

struct UzayAraci{
   
    gezegen  kalkisgezgeni;
    int kalkisGezegenTur;
    gezegen  varisgezgeni;
    int varisgezgeniTur;

        char* uzayAraciAdi;
        char* cikisTarihi;
        int mesafeSaatOlarak;
       
	     char* Durum;
	     char* Konum;
	     char* varisTarihi;

    // fonksiyon isaretcileri 
       
        gezegen (*getKalkisGezgeni)(struct UzayAraci*);
        int     (*getKalkisGezegenTur)(struct UzayAraci*);
        gezegen (*getVarisGezgeni)(struct UzayAraci*);
        int     (*getVarisGezegenTur)(struct UzayAraci*);
        char*   (*getUzayAraciAdi)(struct UzayAraci*);
        char*   (*getCikisTarihi)(struct UzayAraci*);
        int     (*getMesafeSaatOlarak)(struct UzayAraci*);
        char*   (*getDurum)(struct UzayAraci*);
        char*   (*getKonum)(struct UzayAraci*);
        char*   (*getVarisTarihi)(struct UzayAraci*);
    
        void    (*setMesafeSaatOlarak)(struct UzayAraci*, int);
        void    (*setDurum)(struct UzayAraci*, const char*);
        void    (*setKonum)(struct UzayAraci*, const char*);
        void (*deleteUzayAraci)(struct UzayAraci*);

};

typedef struct UzayAraci* uzayAraci ; 

uzayAraci newUzayAraci(); 
// ikinci paremetre isim 


gezegen getKalkisGezgeni(const uzayAraci);
int getKalkisGezegenTur(const uzayAraci);
gezegen getVarisGezgeni(const uzayAraci);
int getVarisGezegenTur(const uzayAraci);
char* getUzayAraciAdi(const uzayAraci);
char* getCikisTarihi(const uzayAraci);
int getMesafeSaatOlarak(const uzayAraci);
char* getDurum(const uzayAraci);
char* getKonum(const uzayAraci);
char* getVarisTarihi(const uzayAraci);

void setMesafeSaatOlarak(uzayAraci, int);
void setDurum(uzayAraci, const char*);
void setKonum(uzayAraci, const char*);
// geekli fonksiyonlara 

// yıkıcı 
void deleteUzayAraci(uzayAraci);
#endif