package jogodavelha;

/**
 * @param scanner inteiro respons�vel pela jogada dos jogadores 
 * @return a posicao da jogada realizada pelo jogador
 */
public class Jogada {
	private int posicao;
	
	public Jogada(int scanner) {
		posicao = scanner;
	}
	
	public int getPosicao(){
		return posicao;
	}

}
