/**
* @file dosyaokuma.c
* @description dosyaokuma.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "DosyaOkuma.h"
#include "Gezegen.h"
#include "BuzDeviGezegen.h"
#include "CuceGezegen.h"
#include "GazDeviGezegen.h"
#include "KayacGezegen.h"

#include "KISI.h"

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

dosyaOkuma newDosyaOkuma() {
    dosyaOkuma this = (dosyaOkuma)malloc(sizeof(struct DosyaOkuma));
    if (this == NULL) return NULL;

    // Dosya isimlerini ata
    this->dosyaAraclar = "Araclar.txt";
    this->dosyaGezegenler = "Gezegenler.txt";
    this->dosyaKisiler = "Kisiler.txt";

    // Fonksiyon işaretçileri 
    this->dosyaOkumaBaslat             = &dosyaOkumaBaslat;
    this->gezegenOku                   = &gezegenOku;
    this->aracOku                      = &aracOku;
    this->kisiOku                      = &kisiOku;

    this->satirSayisiniHesapla        = &satirSayisiniHesapla;

    this->gezegenDizisiniOlustur      = &gezegenDizisiniOlustur;
    this->aracDizisiniOlustur         = &aracDizisiniOlustur;
    this->kisiDizisiniOlustur         = &kisiDizisiniOlustur;

    this->gezegenBul                  = &gezegenBul;
    this->uzayAraciBul                = &uzayAraciBul;

    this->gezegenDizisiniSerbestBirak = &gezegenDizisiniSerbestBirak;
    this->aracDizisiniSerbestBirak    = &aracDizisiniSerbestBirak;
    this->kisiDizisiniSerbestBirak    = &kisiDizisiniSerbestBirak;
    this->delete_DosyaOkuma = &delete_DosyaOkuma;
    this-> satirSayisiniHesaplaAltGezegen=&satirSayisiniHesaplaAltGezegen;

     this->satirSayisiGezegen = this->satirSayisiniHesapla(this, this->dosyaGezegenler);
     this->satirSayisiUzayAraci = this->satirSayisiniHesapla(this, this->dosyaAraclar);
    this->satirSayisiKisiler = this->satirSayisiniHesapla(this,this->dosyaKisiler);
    
    this->satirSayisiGezegen0 = this->satirSayisiniHesaplaAltGezegen(this, this->dosyaGezegenler,0);
    this->satirSayisiGezegen1 = this->satirSayisiniHesaplaAltGezegen(this, this->dosyaGezegenler,1);
    this->satirSayisiGezegen2 = this->satirSayisiniHesaplaAltGezegen(this, this->dosyaGezegenler,2);
    this->satirSayisiGezegen3 = this->satirSayisiniHesaplaAltGezegen(this, this->dosyaGezegenler,3);



    return this;
}


int satirSayisiniHesapla(const dosyaOkuma this, const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        perror("Dosya açılamadı");
        return 0;
    }

    int sayac = 0;
    char satir[1024];  // Her satır için geçici bir buffer

    // Satır satır oku
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        int i = 0;
        int veriVarMi = 0;

        // Satırdaki her karakteri kontrol et
        while (satir[i] != '\0') {
            // Eğer satırda boşluk, tab veya yeni satır değilse veri var demektir
            if (satir[i] != ' ' && satir[i] != '\t' && satir[i] != '\n') {
                veriVarMi = 1;  // Satırda veri var
                break;
            }
            i++;
        }

        // Eğer satırda veri varsa, sayacı artır
        if (veriVarMi) {
            sayac++;
        }
    }

    fclose(dosya);
    return sayac;
}

int satirSayisiniHesaplaAltGezegen(dosyaOkuma this, const char* dosyaAdi, int tur) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        perror("Dosya açılamadı");
        return 0;
    }

    int sayac = 0;
    char satir[1024];

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        int okunanTur;
        char* satirKopya = strdup(satir);  // strtok bozmasın diye kopya

        // Satır örneği: A#1#27#07.04.2025
        char* token = strtok(satirKopya, "#"); // A (isim)
        token = strtok(NULL, "#"); // tür olacak: "1"
        
        if (token != NULL) {
            okunanTur = atoi(token);
            if (okunanTur == tur) {
                sayac++;
            }
        }

        free(satirKopya);
    }

    fclose(dosya);
    return sayac;
}
void  gezegenDizisiniOlustur(const dosyaOkuma this, int satirSayisi) // Gezegen dizisini oluştur
{
    this->gezegenler = (gezegen*)malloc(satirSayisi * sizeof(gezegen));

    if(this->satirSayisiGezegen0 >0)
    this->dizikayac = (kayacGezegen*)malloc(this->satirSayisiGezegen0 * sizeof(kayacGezegen));

    if(this->satirSayisiGezegen1 >0)
    this->dizigaz = (gazDeviGezegen*)malloc(this->satirSayisiGezegen1 * sizeof(gazDeviGezegen));
    
    if(this->satirSayisiGezegen2 >0)
    this->dizibuzdevi = (buzDeviGezegen*)malloc(this->satirSayisiGezegen2 * sizeof(buzDeviGezegen));
    
    if(this->satirSayisiGezegen3 >0)
    this->dizicuce = (cuceGezegen*)malloc(this->satirSayisiGezegen3 * sizeof(cuceGezegen));

}
void aracDizisiniOlustur(const dosyaOkuma this, int satirSayisi)
{
    this->araclar = (uzayAraci*)calloc(satirSayisi, sizeof(struct UzayAraci));
} 
void kisiDizisiniOlustur(const dosyaOkuma this , int satirSayisi)
{
    this->kisiler = (Kisi*)calloc(satirSayisi, sizeof(struct KISI));
} 

void gezegenOku(const dosyaOkuma this) {
    FILE* dosya = fopen(this->dosyaGezegenler, "r");
    if (dosya == NULL) {
        printf("Hata: %s\n", strerror(errno));  // Hata mesajını detaylı olarak yazdır
        return;
    }
    int tur0=0; 
    int tur1=0;
    int tur2=0;
    int tur3=0;

    int satirSayisi = this->satirSayisiniHesapla(this,this->dosyaGezegenler );
    printf("%d",satirSayisi);
    this->gezegenDizisiniOlustur(this, satirSayisi);

    char satir[256];
    int i = 0;

    while (fgets(satir, sizeof(satir), dosya) != NULL && i < satirSayisi) {
        // Boş satır kontrolü

        int veriVar = 0;
        for (int k = 0; satir[k] != '\0'; k++) {
            if (satir[k] != ' ' && satir[k] != '\n' && satir[k] != '\t') {
                veriVar = 1;
                break;
            }
        }
        if (!veriVar) continue;

        // Parçalama
        char* ad = strtok(satir, "#");
        char* turStr = strtok(NULL, "#");
        char* gunStr = strtok(NULL, "#");
        char* tarihStr = strtok(NULL, "#");

        if (!ad || !turStr || !gunStr || !tarihStr) {
            printf("Eksik veri! Satır atlandı. ad: %s, turStr: %s, gunStr: %s, tarihStr: %s\n",
                   ad ? ad : "NULL",
                   turStr ? turStr : "NULL",
                   gunStr ? gunStr : "NULL",
                   tarihStr ? tarihStr : "NULL");
            continue;
        }
      
        int tur = atoi(turStr);
        int gunUzunlugu = atoi(gunStr);

        int gun, ay, yil;
        sscanf(tarihStr, "%d.%d.%d", &gun, &ay, &yil);


        // Türüne göre nesne oluştur (örnek)
        gezegen g = NULL;
        switch (tur) {
            case 0:{
            //printf("Buraya geldi ");
                kayacGezegen nesne = newKayacGezegen( gunUzunlugu,ad,gun,ay,yil,tur );
                this->dizikayac[tur0] =  nesne;
                tur0++;
                g = nesne->super; break;
            }
            case 1:
           { //printf("Buraya geldi ");
                gazDeviGezegen nesne2 = newGazDeviGezegen( gunUzunlugu,ad,gun,ay,yil,tur );
                 this->dizigaz[tur1] =  nesne2;
                tur1++;
                g = nesne2->super; break;}
            case 2:{
            //printf("Buraya geldi ");
            
                buzDeviGezegen nesne3 =newBuzDeviGezegen( gunUzunlugu,ad,gun,ay,yil,tur );
                 this->dizibuzdevi[tur2] =  nesne3;
                tur2++;
                g = nesne3->super; break; }
            case 3:{
            //printf("Buraya geldi ");
                cuceGezegen nesne4 = newCuceGezegen( gunUzunlugu,ad,gun,ay,yil,tur );
                 this->dizicuce[tur3] =  nesne4;
                tur3++;
                g = nesne4->super;break; }
            default:
            //printf("Buraya geldi ");

                printf("Bilinmeyen gezegen türü: %d\n", tur); continue;
        }
        
        this->gezegenler[i] = g;
       // printf("gezgen ismi %s \n", this->gezegenler[i]->isim);
        i++;

    }

    fclose(dosya);
}
void dosyaOkumaBaslat(const dosyaOkuma this) {
   this->gezegenOku(this);
    this->aracOku(this);
    this->kisiOku(this);
}

void aracOku(const dosyaOkuma this) {
    FILE* dosya = fopen(this->dosyaAraclar, "r");
    if (dosya == NULL) {
        printf("Hata: %s\n", strerror(errno));
        return;
    }

    int satirSayisi = this->satirSayisiniHesapla(this, this->dosyaAraclar);
    printf("Arac satir sayisi: %d\n", satirSayisi);
    this->aracDizisiniOlustur(this, satirSayisi);  // diziyi oluşturmalı

    char satir[256];
    int i = 0;
    while (fgets(satir, sizeof(satir), dosya) != NULL && i < satirSayisi) {
        int veriVar = 0;
        for (int k = 0; satir[k] != '\0'; k++) {
            if (satir[k] != ' ' && satir[k] != '\n' && satir[k] != '\t') {
                veriVar = 1;
                break;
            }
        }
        if (!veriVar) continue;

        // Parçalama
        char* ad = strtok(satir, "#");
        char* cikisGezegen = strtok(NULL, "#");
        char* varisGezegen = strtok(NULL, "#");
        char* tarihStr = strtok(NULL, "#");
        char* mesafeStr = strtok(NULL, "#");

        if (!ad || !cikisGezegen || !varisGezegen || !tarihStr || !mesafeStr) {
            printf("Eksik veri! Satır atlandı.\n");
            continue;
        }

        int mesafe = atoi(mesafeStr);
        printf("%d mesefa ",mesafe);
        gezegen kalkisg = this->gezegenBul(this,cikisGezegen);
        gezegen varisg = this->gezegenBul(this,varisGezegen);

        

        // Uzay aracı oluşturuluyor
        uzayAraci yeniArac = newUzayAraci( kalkisg, varisg, ad,tarihStr, mesafe);
        this->araclar[i] = yeniArac;
        i++;
    }

    fclose(dosya);
}
void trimEnd(char* str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n' || str[len - 1] == '\r' || str[len - 1] == '\t')) {
        str[len - 1] = '\0';
        len--;
    }
}
void kisiOku(const dosyaOkuma this) {
    FILE* dosya = fopen(this->dosyaKisiler, "r");
    if (dosya == NULL) {
        printf("Hata: %s\n", strerror(errno));
        return;
    }

    int satirSayisi = this->satirSayisiniHesapla(this, this->dosyaKisiler);
    printf("Kisi satir sayisi: %d\n", satirSayisi);
    this->kisiDizisiniOlustur(this, satirSayisi);  // Kisi dizisini oluştur

    char satir[256];
    int i = 0;
    while (fgets(satir, sizeof(satir), dosya) != NULL && i < satirSayisi) {
        // Satır boşsa geç
        int veriVar = 0;
        for (int k = 0; satir[k] != '\0'; k++) {
            if (satir[k] != ' ' && satir[k] != '\n' && satir[k] != '\t') {
                veriVar = 1;
                break;
            }
        }
        if (!veriVar) continue;

        // Parçalama
        char* isim = strtok(satir, "#");
        char* yasStr = strtok(NULL, "#");
        char* omurStr = strtok(NULL, "#");
        char* aracAdi = strtok(NULL, "#");
        if (aracAdi) trimEnd(aracAdi); 
        if (!isim || !yasStr || !omurStr || !aracAdi) {
            printf("Eksik veri! Kisi atlandı.\n");
            continue;
        }

        double yas = atof(yasStr);
        double omur = atof(omurStr);

        // Uzay aracı bul
        uzayAraci arac = this->uzayAraciBul(this, aracAdi);
        if (arac == NULL) {
            printf("Uyarı: %s adlı araç bulunamadı. Kisi atlandı.\n", aracAdi);
            continue;
        }
        
        // Kisi nesnesi oluştur
        Kisi yeniKisi = newKisi(isim, yas, omur, arac);
        this->kisiler[i] = yeniKisi;
        i++;
        printf("%d",i);
    }

    fclose(dosya);
}

gezegen gezegenBul(const dosyaOkuma this, char* isim) {
    
    for (int i = 0; i <this->satirSayisiGezegen; i++)
    {
        if (strcmp(isim, this->gezegenler[i]->isim) == 0)
        return this->gezegenler[i];
    }
     
    return NULL;
}

uzayAraci uzayAraciBul(const dosyaOkuma this, char* isim) {
    
    for (int i = 0; i <this->satirSayisiUzayAraci; i++)
    {   if(this->araclar[i] == NULL)
       {
        continue;
       } 
        if (strcmp(isim, this->araclar[i]->uzayAraciAdi) == 0)
        return this->araclar[i];
    }
     printf("bulunmadı ");
    return NULL;
}

void gezegenDizisiniSerbestBirak(dosyaOkuma this) {
    
    // önce kayaçları serbest bırakıcam onun üst sınıfı olanlarıda serbest bırakıcam 
     for (int i = 0; i < this->satirSayisiGezegen0; i++)
    {
        if(this->dizikayac[i]==NULL)
        continue;
        // null değilse arac serbest bırakılcak 
        this->dizikayac[i]->delete_KayacAndGezegen(this->dizikayac[i]);
    }  

    if(this->dizikayac != NULL)
    free(this->dizikayac); 

     for (int i = 0; i < this->satirSayisiGezegen1; i++)
    {
        if(this->dizigaz[i]==NULL)
        continue;
        // null değilse arac serbest bırakılcak 
        this->dizigaz[i]->delete_GazAndGezegen(this->dizigaz[i]);
    }   

     if(this->dizigaz != NULL)
    free(this->dizigaz); 

      for (int i = 0; i < this->satirSayisiGezegen2; i++)
    {
        if(this->dizibuzdevi[i]==NULL)
        continue;
        // null değilse arac serbest bırakılcak 
        this->dizibuzdevi[i]->delete_BuzAndGezegen(this->dizibuzdevi[i]);
    }
     if(this->dizibuzdevi != NULL)
    free(this->dizibuzdevi); 
      for (int i = 0; i < this->satirSayisiGezegen3; i++)
    {
        if(this->dizicuce[i]==NULL)
        continue;
        // null değilse arac serbest bırakılcak 
        this->dizicuce[i]->delete_CuceAndGezegen(this->dizicuce[i]);
    }
    if(this->dizicuce != NULL)
    free(this->dizicuce); 

    // gezegen dizisini serbest bırakıyorum içindekileri yukarda ki fonksiyonlar ile bıraktık zaten
    if(this->gezegenler != NULL)
    free(this->gezegenler);

}

void aracDizisiniSerbestBirak(dosyaOkuma this) {
   
    for (int i = 0; i < this->satirSayisiUzayAraci; i++)
    {
        if(this->araclar[i]==NULL)
        continue;
        // null değilse arac serbest bırakılcak 
        this->araclar[i]->deleteUzayAraci(this->araclar[i]);
    }   
    free(this->araclar);

}

void kisiDizisiniSerbestBirak(dosyaOkuma this) {
    for (int i = 0; i < this->satirSayisiKisiler; i++)
    {
        if(this->kisiler[i]==NULL)
        continue;
        // null değilse kişi serbest bırakılcak 
        this->kisiler[i]->delete_Kisi(this->kisiler[i]);
    }   
    free(this->kisiler);
}

void delete_DosyaOkuma(dosyaOkuma this)
{
    // önce kisiler sonra araclar  sonra da gezgenleri silicez dosyadan okuduğumuz tam tersi  
    
    // kisiler serbest bırakılıyor 
    this->kisiDizisiniSerbestBirak(this);

    // sıra araçalrda 
    this->aracDizisiniSerbestBirak(this);
    
    // sıra gezegenlerde 
    this->gezegenDizisiniSerbestBirak(this);

    // sıra yapıda 
    free(this);
}