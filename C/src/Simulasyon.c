/**
* @file Simulasyon.c
* @description Simulasyon.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/

#include "Simulasyon.h"
#include "DosyaOkuma.h"
#include"Gezegen.h"
#include "BuzDeviGezegen.h"
#include "CuceGezegen.h"
#include "GazDeviGezegen.h"
#include "KayacGezegen.h"
#include <string.h>
typedef enum {false, true} bool; 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


simulasyon newSimulasyon(dosyaOkuma dosya)
{   
    simulasyon this;
    this = (simulasyon)malloc(sizeof(struct Simulasyon));
    this->durum1Imha = "imha" ;
    this->durum2ImhaDegil = "canli" ;
   
    this->konum1 = "kalkisbekleniyor";
    this->konum2 = "yolda" ;
    this->konum3 = "vardi";
    this->dosya = dosya;
    this->buz = newBuzDeviGezegen(10,"test",10,10,2010,0);
    this->cuce = newCuceGezegen(10,"test",10,10,2010,1);
    this->gaz = newGazDeviGezegen(10,"test",10,10,2010,2);
    this->kayac = newKayacGezegen(10,"test",10,10,2010,3);

    // fonksiyon işaretçileri 
    this->eventSimilation      = &eventSimilation;
    this->saatArtisi           = &saatArtisi;
    this->yaslariAzalt         = &yaslariAzalt;
    this->AraclariKontrolEt    = &AraclariKontrolEt;
    this->konumIslemleri       = &konumIslemleri;
    this->gezegenNufusuAyarla  = &gezegenNufusuAyarla;
    this->ekranaYaz            = &ekranaYaz;
    this->programBittimi       = &programBittimi;
    this->delete_Simulation  = &delete_Simulation;
    // gerekli değerlerin atanması 
   
    return this;
}
// gerekli fonksiyon tanımlamalrı 

void saatArtisi(simulasyon this){
    //printf("null geldi ");
    for(int i = 0 ; i< this->dosya->satirSayisiGezegen;i++)
    {
        if( this->dosya->gezegenler[i] == NULL)
        {         printf("null geldi ");
            continue;}
        zaman za = this->dosya->gezegenler[i]->gezegenZamani;
        this->dosya->gezegenler[i]->gezegenZamani->BirGunIlerle(za,this->dosya->gezegenler[i]->gunKacSaat);
       // printf("güncel .c deki saat %d",this->dosya->gezegenler[i]->gezegenZamani->saat);
    }
}
void yaslariAzalt(simulasyon this){
   
    for(int i = 0 ; i< this->dosya->satirSayisiKisiler; i++)
    {
        if( this->dosya->kisiler[i] == NULL)
            continue;

        // kisi'nin aracı yolda değilse kalkış gezegenine göre yaş azalacak, yolda ise bir azalacak, vardıysa varışa göre azalacak 
        if(this->dosya->kisiler[i]->kalan_omur > 0)
        {
            uzayAraci bulunduguArac = this->dosya->kisiler[i]->bulunduguArac;
            if(bulunduguArac== NULL)
            continue;
            // string karşılaştırması yaparken strcmp kullanıyoruz
            if(strcmp(bulunduguArac->Durum, this->durum1Imha) != 0)
            {   
                if(strcmp(bulunduguArac->Konum, this->konum2) == 0)
                {
                    // yolda olandan azaltılacak yaş 
                    this->dosya->kisiler[i]->setKalanOmur( this->dosya->kisiler[i], this->dosya->kisiler[i]->kalan_omur-1);
                }
                else {
                    // yolda olmayan, ömrü sıfırdan büyük ve aracı da imha olmayan
                    if(strcmp(bulunduguArac->Konum, this->konum1) == 0)
                    {    
                        

                        // bulunduğu araç üzerinden kalkış gezegeninin azalan ömrünü alacağız 
                        gezegen g = bulunduguArac->kalkisgezgeni;
                        if (g == NULL) {
                            printf("HATA: Kalkış gezegeni NULL\n");
                            continue;
                        }
                        
                        //printf("burda patladı ");
                        switch (g->gezegentur) {
                            case 0: {  // Kaya gezegeni
                                //printf(" burda patladı ");
                                
                            this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->kayac)
                             );                                
                            break;
                            }
                            case 1: {  // Gaz devi gezegeni
                                
                                 this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->gaz)
                             ); 
                                break;
                            }
                            case 2: {  // Buz devi gezegeni
                                
                                 this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->buz)
                             ); ;
                                break;
                            }
                            case 3: {  // Cüce gezegeni
                                
                                 this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->cuce)
                             ); 
                                break;
                            }
                            default:
                                // Bilinmeyen tür
                                break;
                        }
                    }
                    else if(strcmp(bulunduguArac->Konum, this->konum3) == 0)
                    {   
                        // bulunduğu araç üzerinden varış gezegeninin azalan ömrünü alacağız 
                        gezegen g = bulunduguArac->varisgezgeni;
                        if (g == NULL) {
                            printf("HATA: Kalkış gezegeni NULL\n");
                            continue;
                        }
                        switch (g->gezegentur) {
                           // printf("burda patladı ");

                            case 0: {  // Kaya gezegeni
                                 // burda fonksiyon isimleri aynı olabilmesi için videodaki gibi alt gezegen sınıfları içinde fonksiyon isimleri farklı ama üst sınıfta aynı isimde çağırabildim 
                                 this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->kayac)
                             ); 
                                break;
                            }
                            case 1: {  // Gaz devi gezegeni
                                this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->gaz)
                             ); 
                                break;
                            }
                            case 2: {  // Buz devi gezegeni
                                 this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->buz)
                             ); 

                                break;
                            }
                            case 3: {  // Cüce gezegeni
                                this->dosya->kisiler[i]->setKalanOmur(
                                this->dosya->kisiler[i],
                                this->dosya->kisiler[i]->kalan_omur - g->cikarilcakOmur(g, this->cuce)
                             ); 

                                break;
                            }
                            default:
                                // Bilinmeyen tür
                                break;
                        }
                    }
                }
            }
            else
            {
                // bulunduğu araç imha olmuş
            }
        }
        else {
            // kalan ömür zaten sıfır
        }
    }
}

void eventSimilation( simulasyon this ){
    this->saatArtisi(this);
    this->yaslariAzalt(this);
    this->AraclariKontrolEt(this);
    this->konumIslemleri(this);
    this->gezegenNufusuAyarla(this);
    this->ekranaYaz(this);
    
} // her döngüde çalışacak ana fonksiyon diğer fonksiyonlar bunu altında olucak 


void AraclariKontrolEt( simulasyon this){
    bool aracdakiHerkesSifirYas;

    for(int i =0;i<this->dosya->satirSayisiUzayAraci;i++)
    {       
        aracdakiHerkesSifirYas= true;

        if(this->dosya->araclar[i]==NULL)
        continue;

        for(int j = 0 ; j<this->dosya->satirSayisiKisiler;j++)
        {
            if(this->dosya->kisiler[j]==NULL)
            continue;
            // ikiside null değilse bvurda işlem yapılcak
            // canlı bir kişi bile varsa durumu değişmeyip bir sonraki döngüye gidicek
            if(strcmp(this->dosya->araclar[i]->uzayAraciAdi , this->dosya->kisiler[j]->bulunduguArac->uzayAraciAdi ) ==0 )
            {
                // uzay aracinda olan biri bulundu 
                if( this->dosya->kisiler[j]->getKalanOmur(this->dosya->kisiler[j]) > 0 )
               {
                  aracdakiHerkesSifirYas = false;
                  break;
               } 
               

            }
           
        }
        if(aracdakiHerkesSifirYas == true)
        this->dosya->araclar[i]->Durum = this->durum1Imha;
        else 
        this->dosya->araclar[i]->Durum = this->durum2ImhaDegil;

        // değişkeni sıfırlıyoruz 
        aracdakiHerkesSifirYas = false;
    }
    
}
void konumIslemleri( simulasyon this){
    for(int i =0;i<this->dosya->satirSayisiUzayAraci;i++)
    {
        if(this->dosya->araclar[i]==NULL)
        continue;

      // Durumu "imha" olmayan ve kalkış bekleyen araçlar için
        if( strcmp(this->dosya->araclar[i]->Konum,this->konum1)==0  && strcmp(this->dosya->araclar[i]->Durum,this->durum1Imha) !=0)
        {   // uzay aracıın tarihi ilk veride iki basamaklı yapmayı unutma !!!
            if(strcmp(this->dosya->araclar[i]->kalkisgezgeni->gezegenZamani->Dondur(this->dosya->araclar[i]->kalkisgezgeni->gezegenZamani),this->dosya->araclar[i]->cikisTarihi) ==0
             && strcmp(this->dosya->araclar[i]->Konum,this->konum1) == 0  )
            {
                this->dosya->araclar[i]->Konum = this->konum2;
            }
        }
        // yolda olanlar için 
        if(strcmp(this->dosya->araclar[i]->Konum,this->konum2)==0  && strcmp(this->dosya->araclar[i]->Durum,this->durum2ImhaDegil) ==0)
        {    
            if(this->dosya->araclar[i]->mesafeSaatOlarak > 0 )
            this->dosya->araclar[i]->mesafeSaatOlarak = this->dosya->araclar[i]->mesafeSaatOlarak-1;
            if(this->dosya->araclar[i]->mesafeSaatOlarak <= 0 )
            this->dosya->araclar[i]->Konum=this->konum3;
        }
    }
}
void gezegenNufusuAyarla( simulasyon this)
{
    for(int i = 0 ; i< this->dosya->satirSayisiGezegen;i++)
    {
        if( this->dosya->gezegenler[i] == NULL)
        {         
            continue;
        }
        this->dosya->gezegenler[i]->gezegenNufusSifirla(this->dosya->gezegenler[i]);
    }
 
        // nufuslar sıfırlandı şimdi ayarlanıcak 
        for(int j = 0 ; j < this->dosya->satirSayisiKisiler;j++)
        {
            if(this->dosya->kisiler[j] == NULL)
            continue;
            // null değilse yapılcak işlemer 
            if(this->dosya->kisiler[j]->kalan_omur > 0  )
            {
                if(this->dosya->kisiler[j]->bulunduguArac == NULL && strcmp(this->dosya->kisiler[j]->bulunduguArac->Durum , this->durum1Imha) == 0)
                    continue;
                
                    // bulunduğu arac null değil ve imha olmamış kısım 
                    //yolda değilse ve kalkış gezegeninde ise  oraya ekle varışdaysa oraya eklciez 
                    if( strcmp(this->dosya->kisiler[j]->bulunduguArac->Konum,this->konum1) == 0)
                    this->dosya->kisiler[j]->bulunduguArac->kalkisgezgeni->setGezegenNufusu(this->dosya->kisiler[j]->bulunduguArac->kalkisgezgeni);
                    else if (strcmp(this->dosya->kisiler[j]->bulunduguArac->Konum,this->konum3) == 0 )
                    this->dosya->kisiler[j]->bulunduguArac->varisgezgeni->setGezegenNufusu(this->dosya->kisiler[j]->bulunduguArac->varisgezgeni);

            }
        }
    
    
}

void ekranaYaz( simulasyon this)
{      

    int maxGezegenPerSatir = 4;
    int i, j;

    printf("Gezegenler:\n");
    for (i = 0; i < this->dosya->satirSayisiGezegen; i += maxGezegenPerSatir) {
        int endIndex = (i + maxGezegenPerSatir < this->dosya->satirSayisiGezegen) ? i + maxGezegenPerSatir : this->dosya->satirSayisiGezegen;

        // Gezegen isimleri
        printf("%-15s", " ");
        for (j = i; j < endIndex; j++) {
            gezegen g = this->dosya->gezegenler[j];
            printf("--- %-5s ---  ", g ? g->isim : "null");
        }
        printf("\n");

        // Gezegen tarihleri
        printf("%-15s", "Tarih");
        for (j = i; j < endIndex; j++) {
            gezegen g = this->dosya->gezegenler[j];
            if (g && g->gezegenZamani) {
                char* tarih = g->gezegenZamani->Dondur(g->gezegenZamani);
                printf("%-15s", tarih);
            } else {
                printf("%-15s", "null");
            }
        }
        printf("\n");

        // Gezegen nüfusları
        printf("%-15s", "Nufus");
        for (j = i; j < endIndex; j++) {
            gezegen g = this->dosya->gezegenler[j];
            printf("%-15d", g ? g->gezegenNufusu : 0);
        }
        printf("\n\n");
    }

    // Uzay araçlarını yazdır
    printf("Uzay Araclari:\n");
    printf("%-10s %-10s %-10s %-10s %-20s %-20s\n", "Arac Adi", "Durum", "Cikis", "Varis", "Hedefe Kalan Saat", "Hedefe Varacagi Tarih");

    for (i = 0; i < this->dosya->satirSayisiUzayAraci; i++) {
        uzayAraci arac = this->dosya->araclar[i];
        if (arac == NULL) {
            printf("%-10s %-10s %-10s %-10s %-20s %-20s\n", "null", "null", "null", "null", "null", "null");
            continue;
        }

        char* durum = "";
        if (strcmp(arac->Durum, this->durum1Imha) == 0) {
            durum = this->durum1Imha;
            char* kalkis = arac->kalkisgezgeni ? arac->kalkisgezgeni->isim : "null";
            char* varis = arac->varisgezgeni ? arac->varisgezgeni->isim : "null";

            printf("%-10s %-10s %-10s %-10s %-20s %-20s\n",
                arac->uzayAraciAdi ? arac->uzayAraciAdi : "null",
                durum,
                kalkis,
                varis,
                "--",
                "--");
        } else {
            if (strcmp(arac->Konum, this->konum1) == 0) {
                durum = "Bekliyor";
            } else if (strcmp(arac->Konum, this->konum2) == 0) {
                durum = this->konum2;
            } else if (strcmp(arac->Konum, this->konum3) == 0) {
                durum = "Vardi";
            } else {
                durum = "null";
            }

            char* kalkis = arac->kalkisgezgeni ? arac->kalkisgezgeni->isim   : "null";
            char* varis = arac->varisgezgeni ? arac->varisgezgeni->isim : "null";

            char mesafe[16];
            if (arac->mesafeSaatOlarak >= 0)
                sprintf(mesafe, "%d", arac->mesafeSaatOlarak);
            else
                strcpy(mesafe, "null");

            char* varisTarihi = arac->varisTarihi ? arac->varisTarihi : "null";

            printf("%-10s %-10s %-10s %-10s %-20s %-20s\n",
                arac->uzayAraciAdi ? arac->uzayAraciAdi : "null",
                durum,
                kalkis,
                varis,
                mesafe,
                varisTarihi);
        }
    }

   // printf("Geçen toplam zaman: %d\n", Zaman_gecenToplamSaat);

}

int programBittimi(simulasyon this) {
    // programBittimi bir ise program biter 
    int programBittimi = 1;

    // kontrol kotları 
    for (int i = 0; i < this->dosya->satirSayisiUzayAraci; i++) {
        if (this->dosya->araclar[i] == NULL)
            continue;

        // kontrol şartı
        if ((strcmp(this->dosya->araclar[i]->Konum, this->konum2) == 0 || strcmp(this->dosya->araclar[i]->Konum, this->konum1) == 0) && this->dosya->araclar[i]->Durum == this->durum2ImhaDegil) 
            {
            programBittimi = 0;
            }
    }
    return programBittimi;
}

void delete_Simulation(simulasyon this)
{
    if (this == NULL) return;

    if (this->buz != NULL) this->buz->delete_BuzAndGezegen(this->buz);
    if (this->cuce != NULL) this->cuce->delete_CuceAndGezegen(this->cuce);
    if (this->gaz != NULL) this->gaz->delete_GazAndGezegen(this->gaz);
    if (this->kayac != NULL) this->kayac->delete_KayacAndGezegen(this->kayac);

    
    free(this);
}