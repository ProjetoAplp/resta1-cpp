#include <iostream>
#define MAX 8
#define INGLES 0
#define EUROPEU 1
#define EOL "\n"
#define TRIM "\t"
using namespace std;


void atribuir_tabuleiro(char A[MAX][MAX], char B[MAX][MAX]){

    int i, j;

    for(i=0; i < MAX; i++){
        for(j=0; j < MAX; j++){
            A[i][j] = B[i][j];
        }
    }           

};

//Função para atribuir o tabuleiro selecionado
void selecionar_tabuleiro(char A[MAX][MAX],int opt)
{

    if(opt == EUROPEU) {
        cout << "O Tabuleiro Europeu foi selecionado." << EOL;
        char B[MAX][MAX] = 
                           {{'x','A','B','C','D','E','F','G'},
                           {'1',' ',' ','1','1','1',' ',' '},
                           {'2',' ','1','1','1','1','1',' '},
                           {'3','1','1','1','1','1','1','1'},
                           {'4','1','1','1','0','1','1','1'},
                           {'5','1','1','1','1','1','1','1'},
                           {'6',' ','1','1','1','1','1',' '},
                           {'7',' ',' ','1','1','1',' ',' '}};
        
        atribuir_tabuleiro(A, B);
    }

    if(opt == INGLES) {
        cout << "O Tabuleiro Ingles foi selecionado." << EOL;        
        char B[MAX][MAX] = 
                           {{'x','A','B','C','D','E','F','G'},
                           {'1',' ',' ','1','1','1',' ',' '},
                           {'2',' ',' ','1','1','1',' ',' '},
                           {'3','1','1','1','1','1','1','1'},
                           {'4','1','1','1','0','1','1','1'},
                           {'5','1','1','1','1','1','1','1'},
                           {'6',' ',' ','1','1','1',' ',' '},
                           {'7',' ',' ','1','1','1',' ',' '}};
        
        atribuir_tabuleiro(A, B);
    }
};

//Função para exibir o tabuleiro selecionado
void exibe_tabuleiro(char tabuleiro[MAX][MAX])
{
    int i,j;
    cout << EOL;
    for (i=0; i< MAX; i++)
    {   
        for (j=0; j< MAX; j++)
        {
            cout << tabuleiro[i][j] << TRIM;
        }
        cout << EOL << EOL;
    }
};

int main(){
    
    int opt;
    char tabuleiro[MAX][MAX];
    cout << "Resta 1" << EOL;
    cout << "REGRAS:" << EOL; 
    cout << EOL << "O objetivo é deixar apenas uma peça no tabuleiro após uma sequência de movimentos válidos." << EOL;    
    cout << EOL << "O tabuleiro possui um espaço vazio no centro, com um número de peças que designam uma estrutura pré-definida."
    cout << "O jogo apresenta duas formas de tabuleiro, a primeira com padrão inglês com 32 peças e a outra o padrão europeu com 36 peças." << EOL;
    cout << EOL << "Um movimento consiste em pegar uma peça e fazê-la 'saltar' sobre outra peça, sempre na horizontal ou na vertical, terminando em um espaço vazio adjacente a peça 'saltada'. A peça que foi 'saltada' é retirada do tabuleiro." << EOL;
    cout << EOL << "\nSelecione o tipo de tabuleiro digitando o numero correspondente: 0:INGLES ou 1:EUROPEU." << EOL;
    cin >> opt;
    cout << EOL;
    selecionar_tabuleiro(tabuleiro, opt);
    exibe_tabuleiro(tabuleiro);

    return 0;
};