/**
*
* @author UMUT ARDA VURAL umut.vural@ogr.sakarya.edu.tr
* @since 01.04.2025
* <p>
* Console ekranının temizlenmesi için yazılan kodları barındıran sınıf 
* </p>
*/


package src;
import java.io.IOException;

public class Console {
	
		
	 public static void clear() {
	        try {
	            if (System.getProperty("os.name").contains("Windows")) {
	                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
	            } else {
	                Runtime.getRuntime().exec("clear");
	            }
	        } catch (IOException | InterruptedException ex) {
	            ex.printStackTrace();
	        }
	    }
}
