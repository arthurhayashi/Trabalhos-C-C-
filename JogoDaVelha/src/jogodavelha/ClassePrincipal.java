/**
 * @author ${Arthur Y. Hayashi}
 * @author ${Rafael R. Barbosa}
 * @version 1.0
 */
package jogodavelha;
import entradados.Console;

public class ClassePrincipal {
	
	public static void main(String[] args) {
		Tabuleiro tab = new Tabuleiro();
		System.out.printf("Jogador1, digite o seu nome: ");
		Jogador j1 = new Jogador(Console.nome(), 'X');
		System.out.printf("Jogador2, digite o seu nome: ");
		Jogador j2 = new Jogador(Console.nome(), 'O');
		Jogo jogo = new Jogo(tab, j1, j2);
		
		boolean jogar = true;
		
		try{while(jogar) {
			tab.zeraTabuleiro();
			while((!jogo.getVitoria())&&(!jogo.getEmpate())) {
				for(int i = 1; i < 3; i++) {
					if(!jogo.getVitoria()) {
						
						System.out.println("Estas são suas opções de jogada:");
						tab.mostraOpcoes();
						System.out.println("Este é como o tabuleiro está agora:");
						tab.mostraTabuleiro();
						
						System.out.printf("Jogador " + i + ", digite o sua jogada: ");
						Jogada jogada = new Jogada(Console.play());
						
						if(jogo.checaCasaValida(i, jogada.getPosicao())) {
							if(i == 1) {
								tab.registraJogada(j1.getMarca(), jogada.getPosicao());
							}else if(i == 2){
								tab.registraJogada(j2.getMarca(), jogada.getPosicao());
							}
							
							if(jogo.checaVitoria(i, jogada.getPosicao())) {
								jogo.setVitoria(true);
								break;
							}
							else if (jogo.checaEmpate()) {
									jogo.setEmpate(true);
									break;
								}
						}else {
							i--;
						}
					}
				}
			}
			
			j1.marcaPartidas();
			j2.marcaPartidas();
			
			System.out.println("O jogo acabou, desejam continuar? (s/n)");
			if(Console.readChar() == 'n') {
				jogar = false;
	
			}
			jogo.setVitoria(false);
			jogo.setEmpate(false);
		}
	}catch(ArrayIndexOutOfBoundsException exc) {
		System.out.println("Erro");
	}
		
		System.out.println("O jogador 1 (" + j1.getNome() + " (" + j1.getMarca()
						   + ")) acabou com: " + j1.getVitorias() + " vitória(s) e "
						   +j1.getEmpates()+" empate(s) de um total de "
						   + j1.getPartidas() + " partida(s).");
		
		System.out.println("O jogador 2 (" + j2.getNome() + " (" + j2.getMarca()
		                   + ")) acabou com: " + j2.getVitorias() + " vitória(s) e "
		                   +j2.getEmpates()+" empate(s) de um total de "
		                   + j2.getPartidas() + " partida(s).");
	}
}
