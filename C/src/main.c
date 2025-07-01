/**
* @file main.c
* @description main.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // getch için

#include "DosyaOkuma.h"
#include "Gezegen.h"
#include "BuzDeviGezegen.h"
#include "Simulasyon.h"

int main() {
    
    
    // DosyaOkuma nesnesi oluştur
    dosyaOkuma dosya = newDosyaOkuma();
    if (dosya == NULL) {
        printf("Dosya okuma nesnesi oluşturulamadı!\n");
        return 1;
    }  
    // dosyalar okunsun 
    dosya->dosyaOkumaBaslat(dosya);
    // simülasyon yapısı olusturulsun 
    simulasyon ss = newSimulasyon(dosya);
    
    int tursayisi =0;
    int bittimi1isebiter; // kontrol iciin int değişken 
    while(1) // içine true değer veren bir ifade 
    {  
        system("cls"); // ekran temizleme komutu 
 
        ss->eventSimilation(ss);
        bittimi1isebiter = ss->programBittimi(ss);
       
        tursayisi++;
        printf("Gecen saat %d",tursayisi);
         if(bittimi1isebiter==1)
        break;
    }
    // bellek temizleme işlemleri 
      
    // gezegenler ,araçlar,kişiler temizlendi   dizilerde temizlendi
    dosya->delete_DosyaOkuma(dosya);
    // simulasyon içinde kullanılan şeyler temizlendi 
    ss->delete_Simulation(ss);

        printf(" \n Simulasyon tamamlandi. ( Ekranin hemen kapanmamasi icin koydum. Son veriler gozukmesi icin ) Cikmak icin bir tusa basiniz...");
        getch();
    return 0;
}