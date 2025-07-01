#include "GazDeviGezegen.h"
#include "Gezegen.h"
#include <stdio.h>
#include <stdlib.h>

gazDeviGezegen newGazDeviGezegen(int gunKacSaat,char* isim,int gun,int ay ,int yil,int tur )
{   
    gezegen super;
    gazDeviGezegen this;
    this = (gazDeviGezegen)malloc(sizeof(struct GazDeviGezegen));
  
    this->super = newGezegen(gunKacSaat,isim,gun,ay,yil,tur);
   this->gezegendeAzalanOmur=0.1;
    // fonksiyon göstericiler 
    this->super->getgezegendeAzalanOmur = &ggetgezegendeAzalanOmur;
    this->delete_GazAndGezegen = &delete_GazAndGezegen;

    return this;
}
//public fonksiyonlar 

double ggetgezegendeAzalanOmur(const gazDeviGezegen this)
{
   return this->gezegendeAzalanOmur;
}
void delete_GazAndGezegen(gazDeviGezegen this)
{
  if( this->super !=NULL)
  this->super->deleteGezegen( this->super);
  
  if(this !=NULL)
  free(this);
}


