/**
* @file BuzDeviGezegen.c
* @description BuzDeviGezegen.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "BuzDeviGezegen.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

buzDeviGezegen newBuzDeviGezegen(int gunKacSaat,char* isim,int gun,int ay ,int yil,int tur )
{ 
  gezegen super;
    buzDeviGezegen this;
    this = (buzDeviGezegen)malloc(sizeof(struct BuzDeviGezegen));
    
    this->super = newGezegen(gunKacSaat,isim,gun,ay,yil,tur);
   this->gezegendeAzalanOmur=0.5;
    // fonksiyon göstericiler 
    this->super->getgezegendeAzalanOmur = &bgetgezegendeAzalanOmur;
    //this->super->altNesne = this;
    this->delete_BuzAndGezegen =&delete_BuzAndGezegen;
    return this;
}
//public fonksiyonlar 

double bgetgezegendeAzalanOmur(const buzDeviGezegen this)
{
  return this->gezegendeAzalanOmur;
}

void delete_BuzAndGezegen(buzDeviGezegen this)
{
  if( this->super !=NULL)
  this->super->deleteGezegen( this->super);
  
  if(this !=NULL)
  free(this);
}
