/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Gezegen kisi ve araclar ile ilgili nesnelerin veri kaynaklarını okuyan ve nesleri bir birine bağlayan sınıf 
* </p>
*/


package src;
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;


public class DosyaOkuma
{
	private String Dosya1 = "Gezegenler.txt";
	private String Dosya2 = "Araclar.txt"; 
	private String Dosya3 = "Kisiler.txt";
	
	public DosyaOkuma()
	{
		gezegenOku();
		aracOku();
		kisiOku();
	}
	DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");

	 private void gezegenOku()  
	 // private yapıldı public ile dışarı açılacak aşadaki metod ile modülerlik için tercih edildi 
	 {
	    try (BufferedReader br = new BufferedReader(new FileReader(Dosya1))) 
	    {
	        String satir;
	        while ((satir = br.readLine()) != null) 
	        {
	            String[] parcalar = satir.split("#"); // "#" ile ayırıyoruz
	            if (parcalar.length == 3) { // 3 parça olmalı
	                String ad = parcalar[0];
	                int gunSaat = Integer.parseInt(parcalar[1]);
	                LocalDate tarih = LocalDate.parse(parcalar[2], formatter); //  Tarihi dönüştür
	
	                // Gezegen nesnesi oluştur ve listeye ekle
	                Gezegen.gezegenEkle(new Gezegen(ad, gunSaat, tarih));
	            }
	        }
	    } 
		catch (IOException e)
		{
	         e.printStackTrace();
	    }
	    finally {
	    	Gezegen.Gezegenlerimiz();
	    }
	}
	
	 
	 // araçları okuyucaz 
	 private void aracOku()
	 {
		 {
			    try (BufferedReader br = new BufferedReader(new FileReader(Dosya2))) 
			    {
			        String satir;
			        while ((satir = br.readLine()) != null) 
			        {
			            String[] parcalar = satir.split("#"); // "#" ile ayırıyoruz
			            if (parcalar.length == 5)
			            { // 5 parça olmalı
			                String ad = parcalar[0].trim();
			                String  kalkısGezegeni = parcalar[1];
			                String varısGezegeni = parcalar[2];
			                LocalDate cikisTarihi = LocalDate.parse(parcalar[3], formatter); //  Tarihi dönüştür
			                int mesafe_saat_olarak = Integer.parseInt(parcalar[4]);
			                Gezegen kalkisnesnesi=Gezegen.gezegenBul(kalkısGezegeni);
			                Gezegen varisnesnesi=Gezegen.gezegenBul(varısGezegeni);
			                
			                if(kalkisnesnesi != null && varisnesnesi!= null)	{
				                UzayAraci.addUzayAraci(new UzayAraci(ad, kalkisnesnesi, varisnesnesi,cikisTarihi ,mesafe_saat_olarak));

			                }
			                
			                // arac  nesnesi oluştur ve listeye ekle
			            }
			        }
			    } 
				catch (IOException e)
				{ 
			         e.printStackTrace();
			    }
			    finally {
					 System.out.println("--------------------------------");

			    	UzayAraci.araclarımız();
			    }
	  }
	 
    }
	
	 private void kisiOku()
	 {
		 try (BufferedReader br = new BufferedReader(new FileReader(Dosya3))) 
		    {
		        String satir;
		        while ((satir = br.readLine()) != null) 
		        {
		            String[] parcalar = satir.split("#"); // "#" ile ayırıyoruz
		            if (parcalar.length == 4) { // 3 parça olmalı
		                String ad = parcalar[0];
		                int yas = Integer.parseInt(parcalar[1]);
		                int kalanOmurSaat = Integer.parseInt(parcalar[2]);
		                String bulunduguArac = parcalar[3].trim();
		                
		                UzayAraci bulunduguAracObje = UzayAraci.uzayAraciBul(bulunduguArac);
		                // kişi nesnesi oluştur ve listeye ekle
		                if(bulunduguAracObje != null) 
		                {
			                Kisi.kisiEkle(new Kisi(ad, yas, kalanOmurSaat,bulunduguAracObje));

		                }
		                
						 System.out.println("--------------------------------");

		            }
		        }
		    } 
			catch (IOException e)
			{
		         e.printStackTrace();				 System.out.println("--------------------------------");

		    }
		    finally {
				 System.out.println("--------------------------------");

		    	Kisi.Kisilerimiz();
		    }
	 }
	 
	 
}
