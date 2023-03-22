package jogodavelha;

/**
 * @param nome nome do jogador
 * @param marca é o simbolo que representa cada jogador
 * @return partidas retorna a quantidade de partidas que foram jogadas
 * @return vitorias retorna o numero de vitórias de um jogador
 * @return empate retorna o numero de empates de um jogador
 * @return marca retorna a símbolo do jogador
 * @return nome retorna o nome do jogador
 */

public class Jogador {
	private String nome;
	private char marca;
	private int partidas, vitorias,empate;
	
	public Jogador(String nome, char marca) {
		partidas = 0;
		vitorias = 0;
		empate = 0;
		this.nome = nome;
		this.marca = marca;
	}
	
	public void marcaPartidas() {
		partidas += 1;
	}
	
	public int getPartidas() {
		return partidas;
	}
	
	public void marcaVitoria() {
		vitorias += 1;
	}
	public void marcaEmpate() {
		empate += 1;
	}
	
	public int getVitorias() {
		return vitorias;
	}
	
	public int getEmpates() {
		return empate;
	}
	
	public char getMarca() {
		return marca;
	}
	
	public String getNome() {
		return nome;
	}
}
