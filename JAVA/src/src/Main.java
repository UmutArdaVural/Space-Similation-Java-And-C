/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Tüm programın bir arada birleştiği tek olarak çalıştırıldığı ana sınıf Main sınıfımız
* </p>
*/
package src;

public class Main {
	
	
	public static void main(String[] args) {
		
		DosyaOkuma basla = new DosyaOkuma();
		Simülasyon simule = new Simülasyon();
		Boolean IsFinish= false;
		// dosyalar dist içinde olmalı ve proje oradan çalışmalı 
		
		while (!IsFinish) {
		    Console.clear();		
		    simule.eventSimilation(Gezegen.getGezegenler(), Kisi.getKisiler(), UzayAraci.getUzayAraci());
		    IsFinish = simule.programBittimi(UzayAraci.getUzayAraci());

		    try {
		        Thread.sleep(10); // 0.01 saniye beklet ekranda verilerin belli olması için kullandım 
		    } catch (InterruptedException e) {
		        e.printStackTrace(); // veya logla
		    }
		}
		System.out.println("Simülasyon tamamlandı ");
		//Kisi.Kisilerimiz();
	}

}
