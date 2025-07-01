/**
* @file Zaman.c
* @description Zaman.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "Zaman.h"
#include <stdio.h>
#include <stdlib.h>


typedef enum {false, true} bool; 

zaman newZaman(int gun, int ay, int yil)
{
    zaman this;
    // bellekden alan tahsisi 
    this =  (zaman)malloc(sizeof(struct Zaman));
    
    // değişkeler 
    this->ay=ay;
    this->gun=gun;
    this->yil= yil;
    this->saat =0;

    // fonksiyon göstericileri 
    //printf("Gün: %d | Ay: %d | Yıl: %d | Saat: %d\n", this->gun, this->ay, this->yil, this->saat);
    this->BirGunIlerle = &BirGunIlerle;
    this->Yazdir = &Yazdir;
    this->Yoket = &Yoket;
    this->Dondur = &Dondur;
    return this;
}

    // burda olup h dosyasında olmayanlar private olan metodlardır 


    bool ArtikYilMi(int yil) {
        return (yil % 4 == 0 && yil % 100 != 0) || (yil % 400 == 0);
    }
    int GunSayisi(int ay, int yil) {
        int gunler[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (ay == 2 && ArtikYilMi(yil))
            return 29;
        return gunler[ay - 1];
    }
   
    // public 
    void  BirGunIlerle(const zaman this , int gezegendeGunKacSaat ){
        this->saat += 1;  // 1 saat ilerletiyoruz

        if (this->saat >= gezegendeGunKacSaat) {  // Eğer gezegendeki günün süresi tamamlandıysa
            this->saat = 0;  // Saat sıfırlanır
            this->gun += 1;  // Gün bir arttırılır
    
            int maxGun = GunSayisi(this->ay, this->yil);
            if (this->gun > maxGun) {  // Ay sonu gelirse
                this->gun = 1;  // Günü sıfırlıyoruz
                this->ay += 1;  // Ay bir arttırılır
    
                if (this->ay > 12) {  // Yıl sonu gelirse
                    this->ay = 1;  // Ay sıfırlanır
                    this->yil += 1;  // Yıl bir arttırılır
                }
            }
        }
    }
     // int gezegendeGunKacSaat  tutucak 
    void Yazdir(const zaman this)
    {
        printf("%02d.%02d.%04d", this->gun, this->ay, this->yil);
    }
    char* Dondur(const zaman this)
    {
        static char buffer[11]; // "dd.mm.yyyy" + null karakter
        snprintf(buffer, sizeof(buffer), "%02d.%02d.%04d", this->gun, this->ay, this->yil);
        return buffer;
    }
    
    void Yoket(zaman this){
        if (this != NULL) free(this);
    }