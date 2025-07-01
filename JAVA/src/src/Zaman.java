/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Gezegenler için gerekli zaman tanımlamaları ve işlemlerin yapıldığı sınıf 
* * </p>
*/


package src;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;


public class Zaman {
	// burda her gezegen için zaman kontrolü yapılıcak eğer saat o gezegendeki gün sayısına ulaştıysa gezegenin saati güncellenicek 
	int saat ; 
	int Gunun_kac_saat_oldugu;	
	public LocalDate GezegenZamanı;
	public static int gecenToplamSaat=0;
	public Zaman(LocalDate GezegenZamanı,int Gunun_kac_saat_oldugu )
	{
		this.GezegenZamanı = GezegenZamanı ; 
		saat= 0 ; 
		this.Gunun_kac_saat_oldugu = Gunun_kac_saat_oldugu;
	}
	public void zamanKontrolu() {
	    // Önce saati bir artır
	    saat++;
	    
	    // Eğer saat günün toplam saatine ulaştıysa, gün geçişi yap
	    if (saat >= Gunun_kac_saat_oldugu) {
	        saat = 0; 
	        GezegenZamanı = GezegenZamanı.plusDays(1);
	    }
	}
	public LocalDate getMevcutGun()
	{
		return GezegenZamanı;
	}
	public int getMevcutSaat()
	{
		return saat;
	}
	
}
