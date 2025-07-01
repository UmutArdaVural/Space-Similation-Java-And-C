/**
* @file zaman.h
* @description zaman.h için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#ifndef Zaman_H
#define Zaman_H

#include <stdio.h>
#include <stdlib.h>


struct Zaman {
    int gun;
    int ay;
    int yil;
    int saat;
    void (*BirGunIlerle)(struct Zaman*,int ); // int gezegendeGunKacSaat  tutucak 
    void (*Yazdir)(struct Zaman*);
    void (*Yoket)(struct Zaman*);
    char* (*Dondur)(struct Zaman*);
};

typedef struct Zaman* zaman;

zaman newZaman(int , int , int );

void BirGunIlerle(const zaman, int ); // int gezegendeGunKacSaat  tutucak 
void Yazdir(const zaman);
void Yoket(zaman);
char* Dondur(zaman);
#endif