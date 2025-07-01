/**
* @file UzayAraci.c
* @description UzayAraci.c için gerekli tanımlamaların bulunduğu dosya 
* @course 1. Öğretim 1A grubu 
* @assignment 2.ödev
* @date 05.05.2025
* @author Umut Arda Vural B231210081, : umut.vural@ogr.sakarya.edu.tr
*/


#include "UzayAraci.h"
#include <string.h>
#include <time.h>
#include <math.h>

 char* varisTarihiHesapla(gezegen kalkis,
    gezegen varis,
    int mesafeSaat,
    const char* cikisTarihi);

    uzayAraci newUzayAraci(gezegen kalkisgezegeni, gezegen varisgezegeni, char* uzayAraciAdi, char* tarih, int mesafeSaatOlarak) {
        uzayAraci this = (uzayAraci)malloc(sizeof(struct UzayAraci));
        if (this == NULL) return NULL;
        
        if(kalkisgezegeni){
             this->kalkisgezgeni = kalkisgezegeni;
        this->kalkisGezegenTur = kalkisgezegeni->gezegentur;
        }
        else return NULL;
       
        if(varisgezegeni)
       {
         this->varisgezgeni = varisgezegeni;
        
        this->varisgezgeniTur = varisgezegeni->gezegentur;
       }
       else return NULL;
        // Bellekten yer alarak kopyala
        this->uzayAraciAdi = (char*)malloc(strlen(uzayAraciAdi) + 1);
        strcpy(this->uzayAraciAdi, uzayAraciAdi);
        
        this->Durum ="canli";
        this->Konum ="kalkisbekleniyor";
       
        int d, m, y;
        if (sscanf(tarih, "%d.%d.%d", &d, &m, &y) == 3) {
            // Yeni formatta tarih oluştur
            char formattedDate[11];  // "DD.MM.YYYY"
            snprintf(formattedDate, sizeof(formattedDate), "%02d.%02d.%04d", d, m, y);
        
            // Bellek ayır ve ata
            this->cikisTarihi = (char*)malloc(strlen(formattedDate) + 1);
            strcpy(this->cikisTarihi, formattedDate);
        }
    
        this->mesafeSaatOlarak = mesafeSaatOlarak;
    
        // Bu fonksiyon dışarıdan sağlanmalı
        //this->varisTarihi = varisTarihiHesapla(this->kalkisgezgeni, this->varisgezgeni, mesafeSaatOlarak, this->cikisTarihi);
        char* hesaplananTarih = varisTarihiHesapla(this->kalkisgezgeni, this->varisgezgeni, mesafeSaatOlarak, this->cikisTarihi);
        this->varisTarihi = strdup(hesaplananTarih); // malloc ile yeni bir kopya oluşturur
        printf("Hesaplanan Varış Tarihi: %s\n", this->varisTarihi);

        // Fonksiyon işaretçileri
        this->getKalkisGezgeni = &getKalkisGezgeni;
        this->getKalkisGezegenTur = &getKalkisGezegenTur;
        this->getVarisGezgeni = &getVarisGezgeni;
        this->getVarisGezegenTur = &getVarisGezegenTur;
        this->getUzayAraciAdi = &getUzayAraciAdi;
        this->getCikisTarihi = &getCikisTarihi;
        this->getMesafeSaatOlarak = &getMesafeSaatOlarak;
        this->getDurum = &getDurum;
        this->getKonum = &getKonum;
        this->getVarisTarihi = &getVarisTarihi;
    
        this->setMesafeSaatOlarak = &setMesafeSaatOlarak;
        this->setDurum = &setDurum;
        this->setKonum = &setKonum;
    
        this->deleteUzayAraci = &deleteUzayAraci;
    
        return this;
    }

// Getter fonksiyonları
gezegen getKalkisGezgeni(const uzayAraci this) {
    return this->kalkisgezgeni;
}

int getKalkisGezegenTur(const uzayAraci this) {
    return this->kalkisGezegenTur;
}

gezegen getVarisGezgeni(const uzayAraci this) {
    return this->varisgezgeni;
}

int getVarisGezegenTur(const uzayAraci this) {
    return this->varisgezgeniTur;
}

char* getUzayAraciAdi(const uzayAraci this) {
    return this->uzayAraciAdi;
}

char* getCikisTarihi(const uzayAraci this) {
    return this->cikisTarihi;
}

int getMesafeSaatOlarak(const uzayAraci this) {
    return this->mesafeSaatOlarak;
}

char* getDurum(const uzayAraci this) {
    return this->Durum;
}

char* getKonum(const uzayAraci this) {
    return this->Konum;
}

char* getVarisTarihi(const uzayAraci this) {
    return this->varisTarihi;
}

// Setter fonksiyonları
void setMesafeSaatOlarak(uzayAraci this, int mesafe) {
    this->mesafeSaatOlarak = mesafe;
}

void setDurum(uzayAraci this, const char* durum) {
    if (this->Durum) free(this->Durum);
    this->Durum = strdup(durum);
}

void setKonum(uzayAraci this, const char* konum) {
    if (this->Konum) free(this->Konum);
    this->Konum = strdup(konum);
}

void deleteUzayAraci(uzayAraci this) {
    if (this == NULL) return;

    if (this->uzayAraciAdi) {
        free(this->uzayAraciAdi);
    }

    if (this->cikisTarihi) {
        free(this->cikisTarihi);
    }

    // Durum ve Konum sabit string ise FREE EDİLMEZ!
    // Eğer strdup ile kopyalanmış olsaydı, free edebilirdik.

    if (this->varisTarihi) {
        free(this->varisTarihi);
    }

    free(this);
}


// private fonksiyon 
// Yardımcı: Artan günleri tarihe ekleyerek yeni tarihi hesapla Jean Meeus – Astronomical Algorithms kitabı
int tarihtenJulian(int gun, int ay, int yil) {
    if (ay <= 2) {
        yil -= 1;
        ay += 12;
    }
    // https://support.microsoft.com/en-us/office/insert-julian-dates-functions-0c7fa6aa-daff-402e-9990-93a5b76ba018 
    // fonksiyonun hazır formüllerinin olduğu kaynak kendi zaman işlemimiz için kolay dönüşüm sağlar 
    //https://orbital-mechanics.space/reference/julian-date.html örnek kodlar bu kaynakçaları raporumdada belirttim  örnek kodları c ye uyarladım 
    int A = yil / 100;
    int B = 2 - A + (A / 4);
    return (int)(365.25 * (yil + 4716)) + (int)(30.6001 * (ay + 1)) + gun + B - 1524;
}

int tarihFarkiGun(int g1, int a1, int y1, int g2, int a2, int y2) {
    int jdn1 = tarihtenJulian(g1, a1, y1);
    int jdn2 = tarihtenJulian(g2, a2, y2);
    return jdn2 - jdn1;
}

void gunEkle(int *gun, int *ay, int *yil, int eklenecekGun) {
    static const int ayGunleri[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    while (eklenecekGun > 0) {
        int gunSayisi = ayGunleri[*ay - 1];

        // Artık yıl kontrolü
        if (*ay == 2 && ((*yil % 4 == 0 && *yil % 100 != 0) || (*yil % 400 == 0)))
            gunSayisi = 29;

        if (*gun + eklenecekGun <= gunSayisi) {
            *gun += eklenecekGun;
            eklenecekGun = 0;
        } else {
            eklenecekGun -= (gunSayisi - *gun + 1);
            *gun = 1;
            (*ay)++;
            if (*ay > 12) {
                *ay = 1;
                (*yil)++;
            }
        }
    }
}

char* varisTarihiHesapla(gezegen kalkis, gezegen varis, int mesafeSaat, const char* cikisTarihi) {
    
    /*
     javadaki bu kadar kısa kodum aynı şekilde çalışması için çok uğraştım julian takvımine göre çevirince  ama arada yuvarlamalardan dolayı kayıp olabilir 
    private void  varisTarihihesapla()
		    {	
		    	if(this != null && this.kalkisGezegeni != null && this.varisGezegeni != null )
		    	{
		    		 int gunFarki = (int) ChronoUnit.DAYS.between(kalkisGezegeni.getGezegendekiTarih(), cikisTarihi);
			    	    int kalkisaKadarkiSaatFarki = gunFarki * kalkisGezegeni.getGununKacSaatOldugu();
			    	    int varisGezegenindeGecenVakit = kalkisaKadarkiSaatFarki + mesafeSaatOlarak;
			    	    
			    	    // Gün sayısını tam olarak hesaplamak için bölme işlemi
			    	    double gecengunsayisi = varisGezegenindeGecenVakit / (double) varisGezegeni.getGununKacSaatOldugu();
			    	    
			    	    // Eğer kesirli günler varsa, yuvarlama işlemi yapılabilir
			    	    gecengunsayisi = Math.floor(gecengunsayisi); // Tam gün sayısına yuvarlama

			    	    this.varisTarihi = varisGezegeni.getGezegendekiTarih().plusDays((long) gecengunsayisi);
		    	}
		    	
		    	
	
	
		    }
	   
    */
    
    
    static char sonuc[11]; // "DD.MM.YYYY\0"

    // 1. Kalkış gezegeninin zamanını al
    int kGun = kalkis->gezegenZamani->gun;
    int kAy = kalkis->gezegenZamani->ay;
    int kYil = kalkis->gezegenZamani->yil;

    // 2. Çıkış tarihini parse et
    int cGun, cAy, cYil;
    if (sscanf(cikisTarihi, "%d.%d.%d", &cGun, &cAy, &cYil) != 3) {
        // Hatalı giriş varsa kalkış tarihini döndür
        snprintf(sonuc, sizeof(sonuc), "%02d.%02d.%04d", kGun, kAy, kYil);
        return sonuc;
    }

    // 3. Gerçek gün farkını hesapla
    int farkGun = tarihFarkiGun(kGun, kAy, kYil, cGun, cAy, cYil);
    int kalkisaKadarSaatFarki = farkGun * kalkis->getGunKacSaat(kalkis);

    // 4. Toplam saat üzerinden varış gezegeninde kaç gün geçtiğini hesapla
    int toplamSaat = kalkisaKadarSaatFarki + mesafeSaat;
    int varisGun = toplamSaat / varis->getGunKacSaat(varis);

    // 5. Varış tarihini hesapla
    int vGun = varis->gezegenZamani->gun;
    int vAy = varis->gezegenZamani->ay;
    int vYil = varis->gezegenZamani->yil;

    gunEkle(&vGun, &vAy, &vYil, varisGun);

    // 6. Sonucu "GG.AA.YYYY" formatında döndür
    snprintf(sonuc, sizeof(sonuc), "%02d.%02d.%04d", vGun, vAy, vYil);
    return sonuc;
}


int gunFarkiHesapla(int gezegenGun, int gezegenAy, int gezegenYil, const char* cikisTarihi) {
    int gunFarki = 0;
    
    // Aracın çıkış tarihini parçalara ayır
    int aracGun, aracAy, aracYil;
    if (sscanf(cikisTarihi, "%2d.%2d.%4d", &aracGun, &aracAy, &aracYil) != 3) {
        return -1;  // Hatalı tarih formatı
    }

    // 1. Yıl farkını hesapla
    while (aracYil < gezegenYil) {
        // Bu yılın toplam gün sayısını ekleyelim
        int yil = aracYil;
        int gunlerBuYil = (yil % 4 == 0 && (yil % 100 != 0 || yil % 400 == 0)) ? 366 : 365; // Artık yıl kontrolü
        gunFarki += gunlerBuYil;
        aracYil++;
    }

    // 2. Ay farkını hesapla
    int gunlerInAylar[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // Ayların gün sayıları
    if ((aracYil % 4 == 0 && (aracYil % 100 != 0 || aracYil % 400 == 0))) {
        gunlerInAylar[1] = 29;  // Artık yıl Şubat 29 gün
    }

    while (aracAy < gezegenAy) {
        gunFarki += gunlerInAylar[aracAy - 1];
        aracAy++;
    }

    // 3. Gün farkını hesapla
    gunFarki += gezegenGun - aracGun;

    return gunFarki;
}