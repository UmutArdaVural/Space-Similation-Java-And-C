
/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Simülasyon için gerekli fonksiyonların ve kontrollerin gerçekleştirildiği main fonksiyonuna en fazla veri gönderen sınıfdır 
* </p>
*/




package src;
import java.util.ArrayList;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.List;


public class Simülasyon {
	
		private String durum1Imha = "imha" ;
		private String durum2ImhaDeğil = "canli" ;
		
		private String konum1 = "kalkisbekleniyor" ;
		private String konum2 = "yolda" ;
		private String konum3 = "vardi";
	
	public void eventSimilation( ArrayList<Gezegen> gezegenler ,ArrayList<Kisi> kisiler,ArrayList<UzayAraci> araclar) // fonksiyon ismi ingilizce bilinçli olarak diğerlerinden ayrışması için koydum  olay similasyonun ingilizcesi tüm olayları kapsıcak ve sonsuz döngüde devam edicek olayları çalıştırıcak 
	{
		//1 önce gezegenlerin zamanı artacak 
				//2 kişileirn yaşları azalıcak 
				// 3 araçkontrolü 
				// 4 konum işlemleri 
				// 5 gezegen nufusu ayarlama 
		this.saatartışı(gezegenler);
		this.yaslarıAzalt(kisiler);
		this.AraclarıKontrolEt(kisiler,araclar);
		this.konumIslemleri(araclar);
		this.gezegenNufusuAyarla(kisiler,araclar,gezegenler);
		this.ekranaYaz(gezegenler,araclar);
	}
	private void ekranaYaz(ArrayList<Gezegen> gezegenler, ArrayList<UzayAraci> araclar) {
	    int maxGezegenPerSatir = 4; // Bir satıra maksimum 4 gezegen yazılacak

	    // Gezegenleri 4'erli gruplara bölerek yazdır
	    System.out.println("Gezegenler:");
	    for (int i = 0; i < gezegenler.size(); i += maxGezegenPerSatir) {
	        int endIndex = Math.min(i + maxGezegenPerSatir, gezegenler.size());
	        List<Gezegen> subList = gezegenler.subList(i, endIndex);

	        // Gezegen başlıklarını yazdır
	        System.out.printf("%-15s", " ");
	        for (Gezegen g : subList) {
	            String gezegenAdi = (g != null && g.getGezegenAdi() != null) ? g.getGezegenAdi() : "null";
	            System.out.printf("--- %-5s ---  ", gezegenAdi);
	        }
	        System.out.println();

	        // Gezegen tarihlerini yazdır
	        System.out.printf("%-15s", "Tarih");
	        for (Gezegen g : subList) {
	            String tarih = (g != null && g.getGezegendekiTarih() != null) 
	                ? g.getGezegendekiTarih().format(DateTimeFormatter.ofPattern("d.MM.yyyy")) 
	                : "null";
	            System.out.printf("%-15s", tarih);
	        }
	        System.out.println();

	        // Gezegen nüfuslarını yazdır
	        System.out.printf("%-15s", "Nüfus");
	        for (Gezegen g : subList) {
	            String nufus = (g != null) ? String.valueOf(g.getNufus()) : "null";
	            System.out.printf("%-15s", nufus);
	        }
	        System.out.println("\n");
	    }

	    // Uzay Araçlarını Yazdır
	    System.out.println("Uzay Araçları:");
	    System.out.printf("%-10s %-10s %-10s %-10s %-20s %-20s\n",
	                      "Araç Adı", "Durum", "Çıkış", "Varış", "Hedefe Kalan Saat", "Hedefe Varacağı Tarih");

	    for (UzayAraci arac : araclar) {
	        if (arac == null) {
	            System.out.printf("%-10s %-10s %-10s %-10s %-20s %-20s\n",
	                    "null", "null", "null", "null", "null", "null");
	            continue;
	        }

	        String durum = "";
	        if (arac.getDurum() != null && arac.getDurum().equals(durum1Imha)) {
	            durum = durum1Imha;
	            String kalkis = (arac.getKalkisGezegeni() != null) ? arac.getKalkisGezegeni().getGezegenAdi() : "null";
	            String varis = (arac.getVarisGezegeni() != null) ? arac.getVarisGezegeni().getGezegenAdi() : "null";

	            System.out.printf("%-10s %-10s %-10s %-10s %-20s %-20s\n",
	                    (arac.getUzayAraciAdi() != null) ? arac.getUzayAraciAdi() : "null",
	                    durum,
	                    kalkis,
	                    varis,
	                    "--",
	                    "--");
	        } else {
	            durum = (arac.getKonum() != null) ? arac.getKonum() : "null";
	            if (durum.equals(konum1)) {
	                durum = "Bekliyor";
	            } else if (durum.equals(konum2)) {
	                durum = konum2;
	            } else if (durum.equals(konum3)) {
	                durum = "Vardı";
	            }

	            String kalkis = (arac.getKalkisGezegeni() != null) ? arac.getKalkisGezegeni().getGezegenAdi() : "null";
	            String varis = (arac.getVarisGezegeni() != null) ? arac.getVarisGezegeni().getGezegenAdi() : "null";

	            String mesafe = (arac.getMesafeSaatOlarak() >= 0) ? String.valueOf(arac.getMesafeSaatOlarak()) : "null";
	            String varisTarihi = (arac.getVarisTarihi() != null)
	                    ? arac.getVarisTarihi().format(DateTimeFormatter.ofPattern("d.MM.yyyy"))
	                    : "null";

	            System.out.printf("%-10s %-10s %-10s %-10s %-20s %-20s\n",
	                    (arac.getUzayAraciAdi() != null) ? arac.getUzayAraciAdi() : "null",
	                    durum,
	                    kalkis,
	                    varis,
	                    mesafe,
	                    varisTarihi);
	        }
	    }

	    int zaman = Zaman.gecenToplamSaat;
	    System.out.println("geçen toplam zaman " + zaman);
	}

	
	private void saatartışı( ArrayList<Gezegen> gezegenler)
	{
		for(Gezegen gezegen : gezegenler)
		{	
			if (gezegen == null) {
		        continue; // Bu turu atla, sıradaki gezegene geç
		    }
			
			gezegen.getZaman().zamanKontrolu();
			gezegen.setGezegendekiTarih(gezegen.getZaman().getMevcutGun());
			
		}
		Zaman.gecenToplamSaat++;
	}
	
	private void yaslarıAzalt(ArrayList<Kisi> kisiler)
	{	// her kişinin yaşı bir azaltılıcak  
		for (Kisi kisi : kisiler) {
			
			 if (kisi == null) {
			        continue; // Bu turu atla, sıradaki gezegene geç
			    }
			
            // Kişinin yaşını bir azalt
			if(kisi.getKalanOmur() >0 )
            kisi.setKalanOmur(kisi.getKalanOmur() - 1 );
        }
	}
	private void AraclarıKontrolEt(ArrayList<Kisi> kisiler, ArrayList<UzayAraci> araclar) {
	    // Her uzay aracı için kontrol yap
	    for (UzayAraci arac : araclar) {
	        if (arac == null) {
	            continue; // Araç null ise atla
	        }
	        
	        boolean aracdakiHerkesSifirYas = true;

	        // Uzay aracındaki her kişiyi kontrol et
	        for (Kisi kisi : kisiler) { 
	            if (kisi == null || kisi.getBulunduguarac() == null) {
	                continue; // Kişi veya bulunduğu araç null ise atla
	            }
	            
	            if (kisi.getBulunduguarac().getUzayAraciAdi() != null 
	                && kisi.getBulunduguarac().getUzayAraciAdi().equals(arac.getUzayAraciAdi())) {
	                // Kişi bu araçta ve yaşını kontrol et
	                if (kisi.getKalanOmur() != 0) {
	                    aracdakiHerkesSifirYas = false;
	                    break; // Bir kişi yaşıyorsa kontrolü durdur
	                }
	            }
	        }

	        // Eğer uzay aracındaki tüm kişilerin ömürleri sıfırsa
	        if (aracdakiHerkesSifirYas) {
	            arac.setDurum(durum1Imha);
	            arac.setMesafeSaatOlarak(0);
	        } else {
	            arac.setDurum(durum2ImhaDeğil);
	        }
	    }
	}

	
	private void konumIslemleri(ArrayList<UzayAraci> araclar) {
	    for (UzayAraci arac : araclar) {
	    	
	    	 if (arac == null) {
	    	        continue; // Bu turu atla, sıradaki araca geç
	    	    }
	    	
	        // Durumu "imha" olmayan ve kalkış bekleyen araçlar için
	        if (arac.getKonum().equals(konum1) && !arac.getDurum().equals(durum1Imha)) {
	            if (arac.getKalkisGezegeni().getGezegendekiTarih().equals(arac.getCikisTarihi()) && arac.getKonum().equals(konum1)) {
	                arac.setKonum(konum2); // Konum 2'ye geçiş yapılıyor
	            }
	        }

	        // Yolda olan araçlar için
	        if (arac.getKonum().equals(konum2) && arac.getDurum().equals(durum2ImhaDeğil)) {
	            arac.setMesafeSaatOlarak(arac.getMesafeSaatOlarak() - 1); // Yol saati bir azaltılıyor
	            if (arac.getMesafeSaatOlarak() == 0) {
	                arac.setKonum(konum3); // Konum 3'e geçiş yapılıyor
	            }
	        }
	    }
	}
	private void gezegenNufusuAyarla(ArrayList<Kisi> kisiler, ArrayList<UzayAraci> araclar, ArrayList<Gezegen> gezegenler) {
	    // Gezegenlerdeki nüfusu sıfırla
	    Gezegen.gezegenNufusSifirlama();
	    
	    for (Kisi kisi : kisiler) {
	        if (kisi == null) {
	            continue; // Kişi null ise atla
	        }
	        
	        UzayAraci arac = kisi.getBulunduguarac();
	        if (arac == null) {
	            continue; // Bulunduğu araç null ise atla
	        }
	        
	        if (kisi.getKalanOmur() > 0 
	            && arac.getDurum() != null && !arac.getDurum().equals(durum1Imha) 
	            && arac.getKonum() != null && !arac.getKonum().equals(konum2)) {
	            
	            if (arac.getKonum().equals(konum1)) {
	                Gezegen kalkis = arac.getKalkisGezegeni();
	                if (kalkis != null) {
	                    kalkis.setNufus(kalkis.getNufus() + 1);
	                }
	            } else if (arac.getKonum().equals(konum3)) {
	                Gezegen varis = arac.getVarisGezegeni();
	                if (varis != null) {
	                    varis.setNufus(varis.getNufus() + 1);
	                }
	            }
	        }
	    }
	}

	public  boolean  programBittimi(ArrayList<UzayAraci> araclar)
	{	
		//boolean 
		for(UzayAraci uzayAraclarim : araclar )
		{ 
			 if (uzayAraclarim == null) {
			        continue; // Bu turu atla, sıradaki gezegene geç
			    }
			
			//uzayAraclarim içinde yolda olan veya kalkışdabekliyen olup durumu imha değilse program devam edicek 
			if( (uzayAraclarim.getKonum() == konum2 || uzayAraclarim.getKonum() == konum1 )  &&  uzayAraclarim.getDurum() == durum2ImhaDeğil)
				return false;
		}
		return true ; 
	}
	
	
	
}
