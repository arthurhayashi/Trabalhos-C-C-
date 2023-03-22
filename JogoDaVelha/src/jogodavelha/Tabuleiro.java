package jogodavelha;

/**
 * @param posicao posição no tabuleiro
 * @param marca é o simbolo que representa cada jogador
 * @return tabuleiro[posicao - 1] retorna o valor corespondente ao valor do array
 */

public class Tabuleiro {
	private char[] tabuleiro = new char[9];
	private int i;
	
	public Tabuleiro() {
		zeraTabuleiro();
	}
	
	public void zeraTabuleiro() {
		for(i = 0; i < 9; i++) {
			tabuleiro[i] = ' ';
		}
	}
	
	public char mostraCasa(int posicao) {
		return tabuleiro[posicao - 1];
	}
	
	public void registraJogada(char marca, int posicao) {
	
			tabuleiro[posicao - 1] = marca;
	
	}
	
	public void mostraOpcoes() {
		System.out.println("\n");
		for(i = 0; i < 3; i++) {
			System.out.printf(" " + ((i * 3) + 1));
			System.out.printf(" | " + ((i * 3) + 2) + " |");
			System.out.printf(" " + ((i * 3) + 3));
			if(i < 2) {
				System.out.println("\n---+---+---");
			}
		}
		System.out.println("\n");
	}
	
	public void mostraTabuleiro() {
		System.out.println("\n");
		for(i = 0; i < 3; i++) {
			System.out.printf(" " + tabuleiro[(i * 3) + 0]);
			System.out.printf(" | " + tabuleiro[(i * 3) + 1] + " |");
			System.out.printf(" " + tabuleiro[(i * 3) + 2]);
			if(i < 2) {
				System.out.println("\n---+---+---");
			}
		}
		System.out.println("\n");
	}
}
