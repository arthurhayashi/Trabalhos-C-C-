package entradados;
import java.io.*;

/**
 * @return br.readLine() retorna a string que foi lida
 * @return Integer.parseInt(str) retorna o inteiro que foi lido
 * @return c=(char)br.read() retorna o char que foi lido
 */

public class Console {
	public static String nome() {
		try {	
			BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
			return br.readLine();
		}catch(IOException e) {
			throw new RuntimeException("Erro ao ler o teclado");
		}
		
	}
	
	public static int play() {
		String str = nome();
		try {
			return Integer.parseInt(str);
		}catch(NumberFormatException e) {
			throw new RuntimeException(str + " não é um inteiro válido");
		}
	}
	
	public static char readChar(){
		char c;
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		try {
			return c=(char)br.read();
		} catch (IOException e) {
			throw new RuntimeException("Erro ao ler char");
		}
	}
	
}
