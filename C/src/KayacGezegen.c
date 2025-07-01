/**
* @file KayacGezegen.c
* @description KayacGezegen.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/

#include "KayacGezegen.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

kayacGezegen newKayacGezegen(int gunKacSaat,char* isim,int gun,int ay ,int yil,int tur  )
{   
    gezegen super;
    kayacGezegen this;
    this = (kayacGezegen)malloc(sizeof(struct KayacGezegen));
    this->super = newGezegen(gunKacSaat,isim,gun,ay,yil,tur);
   this->gezegendeAzalanOmur=1;
    // fonksiyon göstericiler 
    this->super->getgezegendeAzalanOmur = &kgetgezegendeAzalanOmur;
   // this->super->altNesne = this;
  this->delete_KayacAndGezegen= &delete_KayacAndGezegen;

    return this;
}
//public fonksiyonlar 

double kgetgezegendeAzalanOmur(const kayacGezegen this)
{
  return this->gezegendeAzalanOmur;
}

void delete_KayacAndGezegen(kayacGezegen this)
{
  if( this->super !=NULL)
  this->super->deleteGezegen( this->super);
  
  if(this !=NULL)
  free(this);
}
