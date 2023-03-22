package armazenamento;
import java.io.*;

/**
 * @param vencedor retorna a string que corresponde ao nome do vencedor
 */

public class GerenciaJogadoresArquivo implements GerenciaJogadores{

	public static void gravarVencedores(String vencedor) {
		BufferedWriter writer =null;
		try {
			writer = new BufferedWriter(new FileWriter("arquivo.txt",true));
			writer.write(vencedor);
			writer.newLine();
		}catch(IOException exc) {
			System.out.println("Erro ao arquivar"+ exc);
		}finally {
			try {
				if (writer!=null) 
					writer.close();
				}catch(IOException exc) {
					System.out.println("Fechando o arquivo"+exc);
				}
			}
		}
		
	}


