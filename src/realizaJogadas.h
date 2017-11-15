/*
** Cabecalhos das funções implementadas no módulo calculadora.c ,
** que servem para realizar diversos cálculos matemáticos
*/


//structs
struct Jogada{
    int  x;
    int  y;
    int direcao;
};

struct Tabuleiro{
    int numero_linhas;
    int numero_colunas;
	char M[][7];
};


/*
* Recebe as coordenadas e direcao da peca que o jogador quer mover. 
*/
struct Jogada getInputJogador(void);

/*
* Verifica se uma jogada eh valida no jogo.
*/
bool validarJogada(struct Jogada, char tabuleiro[][7]);

/*
* Executa a jogada no tabuleiro. Sem validacao
*/
void realizaJogada(struct Jogada, char tabuleiro[][7]);


/*
* Recebe uma jogada, se ela for valida, eh realizada 
*/
bool joga(char tabuleiro[][7]);

