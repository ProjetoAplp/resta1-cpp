/*
** Cabecalhos das funções implementadas no módulo calculadora.c ,
** que servem para realizar diversos cálculos matemáticos
*/

//structs
struct Jogada{
    int  x;
    int  y;
    int direcao;

    Jogada()
    {   }

    Jogada(int a, int b, int c) : x(a), y(b), direcao(c)
    {   }
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

/*
* Verifica se existe alguma jogada valida a ser feito no jogo, caso nao haja o jogo eh encerrado
*/
bool existeJogada(char tabuleiro[][7]);


/*
* Funcao auxiliar que conta o numero de jogadas pra cima possiveis
*/
int existeJogadaHelper(char tabuleiro[][7]);


/*
* Funcao auxiliar que rotaciona o tabuleiro a fim de contar apenas um time de movimento
*/
void rotacionaTabuleiro(char tabuleiro[][7]);


/*
* Verifica se o jogador venceu o jogo
*/
bool venceu(char tabuleiro[][7]);


/*
 Oferece a possibilidade da proxima jogada ser automatica
 */
bool jogadaSeraAutomatica();

/*
* Joga automaticamente
*/
void jogadaAutomatica(char tabuleiro[][7]);



