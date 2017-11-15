#include <iostream>
#include<stdio.h>
#include "realizaJogadas.h"

#define MAX 7
#define INGLES 0
#define EUROPEU 1
#define EOL "\n"
#define TRIM "\t"
using namespace std;

// Funcao para atribuir os valores da matriz B a matriz A
void atribuir_tabuleiro(char A[MAX][MAX], char B[MAX][MAX]){

    int i, j;

    for(i=0; i < MAX; i++){
        for(j=0; j < MAX; j++){
            A[i][j] = B[i][j];
        }
    }           

};

//Funcao para atribuir o tabuleiro selecionado
void selecionar_tabuleiro(char A[MAX][MAX])
{
    int opt;

    do {
        cout << EOL << "Selecione o tipo de tabuleiro digitando o numero correspondente: 0:INGLES ou 1:EUROPEU. ";
        cin >> opt;
        cout << EOL;
    }while(opt != 0 && opt != 1);

    if(opt == EUROPEU) {
        cout << "O Tabuleiro Europeu foi selecionado." << EOL;
        char B[MAX][MAX] = 
                           {{' ',' ','1','1','1',' ',' '},
                           {' ','1','1','1','1','1',' '},
                           {'1','1','1','1','1','1','1'},
                           {'1','1','1','0','1','1','1'},
                           {'1','1','1','1','1','1','1'},
                           {' ','1','1','1','1','1',' '},
                           {' ',' ','1','1','1',' ',' '}};
        
        atribuir_tabuleiro(A, B);
    }

    if(opt == INGLES) {
        cout << "O Tabuleiro Ingles foi selecionado." << EOL;        
        char B[MAX][MAX] = 
                           {{' ',' ','1','1','1',' ',' '},
                           {' ',' ','1','1','1',' ',' '},
                           {'1','1','1','1','1','1','1'},
                           {'1','1','1','0','1','1','1'},
                           {'1','1','1','1','1','1','1'},
                           {' ',' ','1','1','1',' ',' '},
                           {' ',' ','1','1','1',' ',' '}};
        
        atribuir_tabuleiro(A, B);
    }
};

//Funcao para exibir o tabuleiro selecionado
void exibe_tabuleiro(char tabuleiro[MAX][MAX])
{
    int i,j, k;
    cout << EOL;
    cout << "x" << TRIM
;    char coluna[MAX] = {'A','B','C','D','E','F','G'};
    
    for(i=0; i < MAX; i++){
        cout << coluna[i] << TRIM;
    }

    cout << EOL << EOL;


    for (i=0; i< MAX; i++)
    {   
        k = i + 1;
        cout << k << TRIM;
        for (j=0; j< MAX; j++)
        {
            cout << tabuleiro[i][j] << TRIM;
        }
        cout << EOL << EOL;
    }
};

//Funcao que imprime na tela as regras do jogo 
void imprime_regras(){

    cout << EOL;
    cout << "RRRRRRRRRRRRRRRRR                                                 tttt                                   1111111" << EOL;   
    cout << "R::::::::::::::::R                                             ttt:::t                                  1::::::1" << EOL;   
    cout << "R::::::RRRRRR:::::R                                            t:::::t                                 1:::::::1" << EOL;  
    cout << "RR:::::R     R:::::R                                           t:::::t                                 111:::::1" << EOL;  
    cout << "  R::::R     R:::::R    eeeeeeeeeeee        ssssssssss   ttttttt:::::ttttttt      aaaaaaaaaaaaa           1::::1" << EOL;  
    cout << "  R::::R     R:::::R  ee::::::::::::ee    ss::::::::::s  t:::::::::::::::::t      a::::::::::::a          1::::1" << EOL;   
    cout << "  R::::RRRRRR:::::R  e::::::eeeee:::::eess:::::::::::::s t:::::::::::::::::t      aaaaaaaaa:::::a         1::::1" << EOL;   
    cout << "  R:::::::::::::RR  e::::::e     e:::::es::::::ssss:::::stttttt:::::::tttttt               a::::a         1::::l" << EOL;   
    cout << "  R::::RRRRRR:::::R e:::::::eeeee::::::e s:::::s  ssssss       t:::::t              aaaaaaa:::::a         1::::l" << EOL;   
    cout << "  R::::R     R:::::Re:::::::::::::::::e    s::::::s            t:::::t            aa::::::::::::a         1::::l" << EOL;   
    cout << "  R::::R     R:::::Re::::::eeeeeeeeeee        s::::::s         t:::::t           a::::aaaa::::::a         1::::l" << EOL;   
    cout << "  R::::R     R:::::Re:::::::e           ssssss   s:::::s       t:::::t    tttttta::::a    a:::::a         1::::l" << EOL;   
    cout << "RR:::::R     R:::::Re::::::::e          s:::::ssss::::::s      t::::::tttt:::::ta::::a    a:::::a      111::::::111" << EOL;
    cout << "R::::::R     R:::::R e::::::::eeeeeeee  s::::::::::::::s       tt::::::::::::::ta:::::aaaa::::::a      1::::::::::1" << EOL;
    cout << "R::::::R     R:::::R  ee:::::::::::::e   s:::::::::::ss          tt:::::::::::tt a::::::::::aa:::a     1::::::::::1" << EOL;
    cout << "RRRRRRRR     RRRRRRR    eeeeeeeeeeeeee    sssssssssss              ttttttttttt    aaaaaaaaaa  aaaa     111111111111" << EOL;
    cout << EOL;

    cout << "REGRAS:" << EOL; 
    cout << EOL << "O objetivo é deixar apenas uma peça no tabuleiro após uma sequência de movimentos válidos." << EOL;    
    cout << EOL << "O tabuleiro possui um espaço vazio no centro, representado pelo caractere '0', com um número de peças, representadas pelo caractere '1', que designam uma estrutura pré-definida." << EOL;
    cout << EOL << "O jogo apresenta duas formas de tabuleiro, a primeira com padrão inglês com 32 peças e a outra o padrão europeu com 36 peças." << EOL;
    cout << EOL << "Um movimento consiste em pegar uma peça e fazê-la 'saltar' sobre outra peça, sempre na horizontal ou na vertical, terminando em um espaço vazio, representado pelo caractere '0', adjacente a peça 'saltada'. A peça que foi 'saltada' é retirada do tabuleiro." << EOL;
    cout << EOL;
};

int main(){
    
    char tabuleiro[MAX][MAX];
    
    //setup
    imprime_regras();
    selecionar_tabuleiro(tabuleiro);
    
    //gameLoop
    while(1){
    	exibe_tabuleiro(tabuleiro);
    	joga(tabuleiro);
    }

    return 0;
};
