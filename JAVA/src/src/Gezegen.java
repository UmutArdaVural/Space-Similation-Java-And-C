/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Gezegenlerin özelliğini barındıran sınıf 
* </p>
*/

package src;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class Gezegen {
	private String gezegenAdi;
    private int gununKacSaatOldugu;
    private LocalDate gezegendekiTarih; // Tarih burada LocalDate olarak tutuluyor
    private static ArrayList<Gezegen> gezegenler = new ArrayList<>();
    public Zaman zaman ;
    private int nufus;
    private int mevcutSaat;
    
    public Gezegen (String gezegenAdi,int gununKacSaatOldugu,LocalDate gezegendekiTarih )
    {
    	this.gezegenAdi = gezegenAdi; 
    	this.gununKacSaatOldugu = gununKacSaatOldugu ; 
    	this.gezegendekiTarih = gezegendekiTarih;
    	 zaman = new Zaman(gezegendekiTarih,gununKacSaatOldugu);
    	 nufus=0;
    	 mevcutSaat=0;
    }
    public Zaman getZaman()
    {
    	return  zaman ;
    }
    // Getter ve Setter metodları
    public String getGezegenAdi() {
        return gezegenAdi;
    }
    public void setNufus(int nufus) {
        this.nufus = nufus;
    }

    public int getNufus() {
        return nufus;
    }

    
    public void setGezegenAdi(String gezegenAdi) {
        this.gezegenAdi = gezegenAdi;
    }

    public int getGununKacSaatOldugu() {
        return gununKacSaatOldugu;
    }

    public void setGununKacSaatOldugu(int gununKacSaatOldugu) {
        this.gununKacSaatOldugu = gununKacSaatOldugu;
    }

    public LocalDate getGezegendekiTarih() {
        return gezegendekiTarih;
    }

    public void setGezegendekiTarih(LocalDate gezegendekiTarih) {
        this.gezegendekiTarih = gezegendekiTarih;
    }


    public String getFormattedGezegendekiTarih() {
        // "5.10.2020" formatında dışarıya dönüştürme
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");
        return this.gezegendekiTarih.format(formatter);
    }

    
    
    // liste ile ilgili olan metodlar 
    public static void gezegenEkle(Gezegen gezegenimiz) {
    	gezegenler.add(gezegenimiz);
    }
    // Listeyi döndüren metot
    public static ArrayList<Gezegen> getGezegenler() {
        return gezegenler;
    }
    @Override
    public String toString() {
        return gezegenAdi + "  " + gununKacSaatOldugu + "  " + gezegendekiTarih;
    }

    // Gezegenlerimizi eklediğimiz listeyi yöneten metod
    public static void Gezegenlerimiz() 
    {
        for (Gezegen gezegen : gezegenler) {
            System.out.println(gezegen.toString()); // her gezegenin toString çıktısını yazdırıyoruz
        }
    }
    
    public static  Gezegen gezegenBul(String gezegenAdiArama) {
        for (Gezegen gezegen : gezegenler) {
            if (gezegen.getGezegenAdi().equalsIgnoreCase(gezegenAdiArama)) {
                return gezegen; // Eşleşen gezegen bulundu, geri döndürülüyor
            }
        }
        return null; // Eğer gezegen bulunamazsa null döndürülür
    }
    public static void gezegenNufusSifirlama()
    {
    	for(Gezegen gezegen : gezegenler)
    	{	
    		if (gezegen == null) 	
                continue; // Null gezegen varsa atla

    		gezegen.nufus = 0 ;
    	}
    
    }
}
