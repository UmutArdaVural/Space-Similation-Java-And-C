/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Kisi için gerekli olan özellikler ve fonksiyonları içeren kişi sınıfı tanımlarını içermektedir 
* </p>
*/


package src;
import java.util.ArrayList;

public class Kisi {
	
	private String isim;
    private int yas;
    private int kalan_omur; // saat cinsinden 
    private UzayAraci bulunduguarac;
    
    private static ArrayList<Kisi> kisiler = new ArrayList<>();
    
    // contracter metod 
    public Kisi(String isim,int yas,int kalan_omur,UzayAraci bulunduguarac)
    {
    	this.isim = isim;
    	this.yas = yas;
    	this.kalan_omur=kalan_omur;
    	this.bulunduguarac = bulunduguarac;
    }
    
    
    // Getter ve Setter metodları
    public UzayAraci getBulunduguarac()
    {
    	return bulunduguarac ; 
    }
    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public int getYas() {
        return yas;
    }

    public void setYas(int yas) {
        this.yas = yas;
    }

    public int getKalanOmur() {
        return kalan_omur;
    }

    public void setKalanOmur(int kalan_omur) {
        this.kalan_omur = kalan_omur;
    }
    public UzayAraci getUzayAraci()
    {
    	return this.bulunduguarac;
    }
    
    @Override
    public String toString() {
        String aracAdi = (bulunduguarac != null) ? bulunduguarac.getUzayAraciAdi() : "null";
        return isim + "  " + yas + "  " + kalan_omur + "  " + aracAdi;
    }

    
    // liste ile ilgili olan metodlar 
    public static void kisiEkle(Kisi kisi) {
        kisiler.add(kisi);
    }
    // Listeyi döndüren metot
    public static ArrayList<Kisi> getKisiler() {
        return kisiler;
    }
    
    public static void Kisilerimiz() 
    {
        for (Kisi kisi : kisiler) {
            System.out.println(kisi.toString()); // her kişilerin  toString çıktısını yazdırıyoruz
        }
    }
	
}
