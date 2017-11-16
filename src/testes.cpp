#include "realiza_jogadas.h"
#include <iostream>

using namespace std;

#define MAX 7

void assertTrue(bool teste, string casoDeTeste){
    if(teste){
        cout << "CASO DE TESTE: " << casoDeTeste << " ====> \033[1;32m PASSOU! \033[0m";
    }else{
        cout << "CASO DE TESTE: " << casoDeTeste << " ====> \033[1;31m FALHOU! \033[0m";
    }
    cout << "\n";
}

void assertFalse(bool teste, string casoDeTeste){
    if(!teste){
        cout << "CASO DE TESTE: " << casoDeTeste << " ====> \033[1;32m PASSOU! \033[0m";
    }else{
        cout << "CASO DE TESTE: " << casoDeTeste << " ====> \033[1;31m FALHOU! \033[0m";
    }
    cout << "\n";
}

bool comparaMatriz(char m1[][MAX], char m2[][MAX]){
    bool iguais = true;

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(m1[i][j] != m2[i][j]){
                iguais = false;
            }
        }
    }

    return iguais;
}

void testeVencerJogo(){
    string casoDeTeste1 = "Vencer Tabuleiro Ingles";
    char tabuleiroI[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','1','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    assertTrue(venceu(tabuleiroI), casoDeTeste1);

    string casoDeTeste2 = "Vencer Tabuleiro Europeu";
    char tabuleiroE[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ','0','0','0','0','0',' '},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','1','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {' ','0','0','0','0','0',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    assertTrue(venceu(tabuleiroE), casoDeTeste2);

}

void testeRotacaoTabuleiro(){
    bool iguais;

    //Tabuleiro ingles
    string casoDeTeste1 = "Rotação de Tabuleiro Ingles";
    char tabuleiroI[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '},
                    {'1','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    char tabuleiroIRot[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {' ',' ','0','0','0',' ',' '},
                    {' ',' ','1','1','1',' ',' '}   };

    rotacionaTabuleiro(tabuleiroI);
    iguais = comparaMatriz(tabuleiroI, tabuleiroIRot);
    assertTrue(iguais, casoDeTeste1);

    //Tabuleiro europeu
    string casoDeTeste2 = "Rotação de Tabuleiro Europeu";
    char tabuleiroE[MAX][MAX] =
            {       {' ',' ','1','1','1',' ',' '},
                    {' ','0','0','0','0','1',' '},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {' ','0','0','0','0','0',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    char tabuleiroERot[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ','1','0','0','0','0',' '},
                    {'1','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {' ','0','0','0','0','0',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    rotacionaTabuleiro(tabuleiroE);
    iguais = comparaMatriz(tabuleiroE, tabuleiroERot);
    assertTrue(iguais, casoDeTeste2);
}

void testeExisteJogada(){
    string casoDeTeste1 = "Existe jogada válida";

    char tabuleiro[MAX][MAX] =
            {       {' ',' ','1','1','1',' ',' '},
                    {' ',' ','1','1','1',' ',' '},
                    {'1','1','1','1','1','1','1'},
                    {'1','1','1','1','1','1','1'},
                    {'1','1','1','1','1','1','1'},
                    {' ',' ','1','1','1',' ',' '},
                    {' ',' ','1','0','1',' ',' '}   };

    assertTrue(existeJogada(tabuleiro), casoDeTeste1);

    string casoDeTeste2 = "Não Existe jogada válida";

    char tabuleiro1[MAX][MAX] =
            {       {' ',' ','1','1','1',' ',' '},
                    {' ',' ','1','1','1',' ',' '},
                    {'1','1','1','1','1','1','1'},
                    {'1','1','1','1','1','1','1'},
                    {'1','1','1','1','1','1','1'},
                    {' ',' ','1','1','1',' ',' '},
                    {' ',' ','1','1','1',' ',' '}   };

    bool existeJogadaTabuleiro1 = existeJogada(tabuleiro1);

    char tabuleiro2[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '},
                    {'1','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    bool existeJogadaTabuleiro2 = existeJogada(tabuleiro2);

    char tabuleiro3[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '},
                    {'1','0','0','1','0','1','0'},
                    {'0','0','0','0','0','0','0'},
                    {'1','0','0','0','0','0','0'},
                    {' ',' ','1','0','1',' ',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    bool existeJogadaTabuleiro3 = existeJogada(tabuleiro3);

    char tabuleiro4[MAX][MAX] =
            {       {' ',' ','0','0','0',' ',' '},
                    {' ',' ','0','0','0',' ',' '},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','0'},
                    {' ',' ','0','0','1',' ',' '},
                    {' ',' ','0','0','0',' ',' '}   };

    bool existeJogadaTabuleiro4 = existeJogada(tabuleiro4);

    assertFalse(existeJogadaTabuleiro1 || existeJogadaTabuleiro2 || existeJogadaTabuleiro3 || existeJogadaTabuleiro4, casoDeTeste2);

}

void executarTestes(){
    testeVencerJogo();
    testeRotacaoTabuleiro();
    testeExisteJogada();
}

int main(){
    executarTestes();
    return 0;
};