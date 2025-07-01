/**
* @file CuceGezegen.c
* @description CuceGezegen.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "CuceGezegen.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

cuceGezegen newCuceGezegen(int gunKacSaat,char* isim,int gun,int ay ,int yil,int tur )
{ 
    gezegen super;
    cuceGezegen this;
    this = (cuceGezegen)malloc(sizeof(struct CuceGezegen));
   
    this->super = newGezegen(gunKacSaat,isim,gun,ay,yil,tur);
   this->gezegendeAzalanOmur=0.01;
    // fonksiyon göstericiler 
    this->super->getgezegendeAzalanOmur = &cgetgezegendeAzalanOmur;
   // this->super->altNesne = this;
   this->delete_CuceAndGezegen = &delete_CuceAndGezegen;

    return this;
}

//public fonksiyonlar 

double cgetgezegendeAzalanOmur(const cuceGezegen this)
{
  return this->gezegendeAzalanOmur;
}
void delete_CuceAndGezegen(cuceGezegen this)
{
  if( this->super !=NULL)
  this->super->deleteGezegen( this->super);
  
  if(this !=NULL)
  free(this);
}
