/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Uzay araclari için gerekli tanımla ve fonksiyonları içeren sınıf  
* </p>
*/


package src;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.time.temporal.ChronoUnit;


public class UzayAraci {
	   
		private String uzayAraciAdi;	 
	    private LocalDate cikisTarihi;
	    private int mesafeSaatOlarak;
	    private Gezegen kalkisGezegeni; 
	    private Gezegen varisGezegeni;
	    private String Durum;
	    private String Konum;
	    private LocalDate varisTarihi;
	    // static alanlar 
	    private static ArrayList<UzayAraci> uzayaraci = new ArrayList<>();
	    
	    // YAPICI METOD  
	    public  UzayAraci(String uzayAraciAdi,Gezegen kalkisGezegeni,Gezegen varisGezegeni , LocalDate cikisTarihi ,int mesafeSaatOlarak )
	    {
	    	this.cikisTarihi = cikisTarihi;
	    	this.kalkisGezegeni = kalkisGezegeni;
	    	this.uzayAraciAdi = uzayAraciAdi;
	    	this.varisGezegeni = varisGezegeni;
	    	this.mesafeSaatOlarak = mesafeSaatOlarak;
	    	this.varisTarihihesapla();
	    	this.Durum = "canli";
	    	this.Konum = "kalkisbekleniyor";
	    }
	    public LocalDate getVarisTarihi()
	    {
	    	return varisTarihi;
	    }
	    // Getter ve Setter metodları
	    public LocalDate getCikisTarihi()
	    {
	    	return cikisTarihi;
	    }
	    
	    public Gezegen getKalkisGezegeni()
	    {
	    	return kalkisGezegeni;
	    }
	    public Gezegen getVarisGezegeni()
	    {
	    	return varisGezegeni;
	    }
	    
	    public String getDurum() {
	        return Durum;
	    }
	    public void setDurum(String Durum)
	    {
	    	this.Durum = Durum;
	    }
	    public String getKonum() {
	        return Konum;
	    }
	    public void setKonum(String Konum)
	    {
	    	this.Konum = Konum;
	    }
	    
	    public String getUzayAraciAdi() {
	        return uzayAraciAdi;
	    }

	    public void setUzayAraciAdi(String uzayAraciAdi) {
	        this.uzayAraciAdi = uzayAraciAdi;
	    }

	    public int getMesafeSaatOlarak() {
	        return mesafeSaatOlarak;
	    }

	    public void setMesafeSaatOlarak(int mesafeSaatOlarak) {
	        this.mesafeSaatOlarak = mesafeSaatOlarak;
	    }
	    
	    // liste ile ilgili metodlar
	    public static ArrayList<UzayAraci> getUzayAraci()
	    {
	    	return uzayaraci; 
	    }
	    public static void addUzayAraci(UzayAraci UA)
	    {
	    	uzayaraci.add(UA);
	    }
	    
	    @Override
	    public String toString() {
	    	 DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");
	         
	         // Formatlı tarihi al
	         String formatliVarisTarihi = varisTarihi.format(formatter);
	        return uzayAraciAdi + "  " + cikisTarihi + "  " + mesafeSaatOlarak +"  "+kalkisGezegeni.getGezegenAdi() +"   "+varisGezegeni.getGezegenAdi()+ "  "+ formatliVarisTarihi;
	    }

	    // Gezegenlerimizi eklediğimiz listeyi yöneten metod
	    public static void araclarımız() 
	    {
	        for (UzayAraci uzayAracı : uzayaraci) {
	            System.out.println(uzayAracı.toString()); // her gezegenin toString çıktısını yazdırıyoruz
	        }
	    }
	    
	    
	    public static  UzayAraci uzayAraciBul(String UzayAracıAdiArama) {
	        for (UzayAraci uzayAraci : uzayaraci) {
	        	
	        	 if (uzayAraci == null) {
	        	        continue; // Bu turu atla, sıradaki gezegene geç
	        	    }
	        	
	            if (uzayAraci.uzayAraciAdi.equalsIgnoreCase(UzayAracıAdiArama)) {
	                return uzayAraci; // Eşleşen gezegen bulundu, geri döndürülüyor
	            }
	        }
	        return null; // Eğer gezegen bulunamazsa null döndürülür
	    }
	    
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
	   
}
