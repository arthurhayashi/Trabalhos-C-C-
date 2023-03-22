package jogodavelha;
import armazenamento.GerenciaJogadoresArquivo;

/**
 * @param tab representa o tabuleiro
 * @param j1 é a variável responsável pelas ações do jogador 1
 * @param j2 é a variável responsável pelas ações do jogador 2
 * @param jogador variavel para passar a informação de qual jogador realizou tal ação
 * @param pos posição de cada jogar
 * @param vitoria recebe o valor booleano se o jogador venceu
 * @param empate recebe o valor booleano se o jogador empatou
 */

public class Jogo {
	private boolean vitoria;
	private boolean empate;
	private Jogador j1;
	private Jogador j2;
	private Tabuleiro tab;
	
	public Jogo(Tabuleiro tab, Jogador j1, Jogador j2) {
		vitoria = false;
		empate = false;
		this.tab = tab;
		this.j1 = j1;
		this.j2 = j2;
	}
	
	public boolean checaCasaValida(int jogador, int pos) {
		if(tab.mostraCasa(pos) == j1.getMarca() || tab.mostraCasa(pos) == j2.getMarca()) {
			System.out.println("Posição inválida.");
			return false;
		}
		
		return true;
	}
	
	public boolean checaVitoria(int jogador, int pos) {
		if(verifLinha(pos) || verifColuna(pos) || verifDiag(pos)) {
			if(jogador == 1) {
				System.out.println("Parabéns jogador(a): "+j1.getNome()+" você venceu!");
				j1.marcaVitoria();
				GerenciaJogadoresArquivo.gravarVencedores(j1.getNome());
			}else {
				System.out.println("Parabéns jogador(a): "+j2.getNome()+" você venceu!");
				j2.marcaVitoria();
				GerenciaJogadoresArquivo.gravarVencedores(j2.getNome());
			}
			return true;
			
		}
		return false;
	}
	
	public boolean checaEmpate() {
		for(int j=1;j<10;j++) {
			if(tab.mostraCasa(j)==' ') {
				return false;
			}
		}
			System.out.println("O jogo acabou por: Empate!!");
			j1.marcaEmpate();
			j2.marcaEmpate();
			
		return true;
	}
	
	public boolean verifColuna(int pos) {
		if(pos >6) {
			if(tab.mostraCasa(pos) == tab.mostraCasa(pos - 3) &&
			   tab.mostraCasa(pos) == tab.mostraCasa(pos - 6)   ) {
				
				return true;
			}
		}else if(pos >3){
			if(tab.mostraCasa(pos) == tab.mostraCasa(pos - 3) &&
			   tab.mostraCasa(pos) == tab.mostraCasa(pos + 3)   ) {
						
				return true;
			}
		}else { 
			if(tab.mostraCasa(pos) == tab.mostraCasa(pos + 3) &&
			   tab.mostraCasa(pos) == tab.mostraCasa(pos + 6)   ) {
						
				return true;
			}
		}
		
		return false;
	}
	
	public boolean verifLinha(int pos) {
		if(pos % 3 == 1) {
			if(tab.mostraCasa(pos) == tab.mostraCasa(pos + 1) &&
			   tab.mostraCasa(pos) == tab.mostraCasa(pos + 2)   ) {
								
				return true;
			}
		}else if(pos % 3 == 2){
			if(tab.mostraCasa(pos) == tab.mostraCasa(pos - 1) &&
			   tab.mostraCasa(pos) == tab.mostraCasa(pos + 1)   ) {
										
				return true;
			}
		}else {
			if(tab.mostraCasa(pos) == tab.mostraCasa(pos - 2) &&
			   tab.mostraCasa(pos) == tab.mostraCasa(pos - 1)   ) {
										
				return true;
			}
		}
		return false;
	}
	
	public boolean verifDiag(int pos) {
		if(pos == 1 || pos == 9) {
			if(tab.mostraCasa(1) == tab.mostraCasa(5) &&
			   tab.mostraCasa(1) == tab.mostraCasa(9)   ) {
															
				return true;
			}
		}
		else if(pos == 3 || pos == 7) {
			if(tab.mostraCasa(3) == tab.mostraCasa(5) &&
			   tab.mostraCasa(3) == tab.mostraCasa(7)   ) {
																	
				return true;
			}
		}
		else if(pos == 5) {
			if(tab.mostraCasa(1) == tab.mostraCasa(5) &&
			   tab.mostraCasa(1) == tab.mostraCasa(9)   ) {
				
				return true;
			}
			else if(tab.mostraCasa(3) == tab.mostraCasa(5) &&
					tab.mostraCasa(3) == tab.mostraCasa(7)   ) {
				return true;
			}
		
		}
		return false;
	}
	
	public boolean getVitoria() {
		return vitoria;
	}
	public void setVitoria(boolean vitoria) {
		this.vitoria = vitoria;
	}
	
	public boolean getEmpate() {
		return empate;
	}
	public void setEmpate(boolean empate) {
		this.empate = empate;
	}
}
