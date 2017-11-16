#include<stdio.h>
#include <iostream>
#include <ctype.h>
#include "realiza_jogadas.h"

#define SIZE 7
#define EOL "\n"

enum direcoes {cima = 0, baixo = 1, esquerda = 2, direita = 3};

//declarando as funcoes
int getLinha(void);
int getColuna(void);
int getDirecao(void);


struct Jogada getInputDoJogador(void){
	
	struct Jogada j;
	j.x = getLinha();
	j.y = getColuna();
	j.direcao = getDirecao();
	return j;
}

int getLinha(void){

	int linha;

	do {
		printf( "Escolha uma Linha valida(1-%i): ", SIZE);
		scanf("%i", &linha);
		setbuf(stdin, NULL);

    }while(linha < 1 || linha > SIZE);

    return linha - 1;
}

int getColuna(void){
	
	char letraColuna;
	int coluna;

	do {
		//('A' + SIZE-1) = letra do alfabeto equivalente a ultima coluna
        printf( "Escolha uma Coluna valida (A-%c). ", ('A' + SIZE-1) );
		scanf("%c", &letraColuna);
        letraColuna = toupper(letraColuna);
        setbuf(stdin, NULL); 
    }while( letraColuna - 'A' < 0 ||  letraColuna - ('A' + SIZE-1) +1 > SIZE);
	
	coluna = letraColuna - 'A';
    return coluna;
}

int getDirecao(void){

	int direcao;

	do {
        printf( "Selecione a direcao digitando o numero correspondente: 0:CIMA, 1:BAIXO, 2:ESQUERDA OU 3:DIREITA. ");
        scanf("%i", &direcao);
        setbuf(stdin, NULL); 
        
    }while(direcao < 0 || direcao > 3);

    return direcao;
}

bool validarJogada(struct Jogada jogada, char tabuleiro[][SIZE]){
	
	int x = jogada.x;
	int y = jogada.y;
	int direcao = jogada.direcao;
	
	//printf("%d  %d  %d  x,y,dir \n", x, y, direcao);//debug

	//nao possui peca no lugar indicado
	if(tabuleiro[x][y] == '0'){
		printf("Escolha um espaco com uma peca\n");
		return false;
	}
	
	switch( direcao ){
	    case cima:
	         //checka se espaco na matriz pro "salto"
			if (x<2){
				printf("Movimento invalido c1\n");
				return false;
			}
			//checka se existe uma peca adjacente pra saltar por cima
			if (tabuleiro[x-1][y] != '1'){
				printf("Movimento invalido c2\n");
				return false;
			}
			//checka se o espaco do salto esta vazio
			if (tabuleiro[x-2][y] != '0'){
				printf("Movimento invalido c1\n");
				return false;
			}
	        break;
	    
	    case baixo:
            //checka se espaco na matriz pro "salto"
			if (x>4){
				printf("Movimento invalido b1\n");
				return false;
			}
			//checka se existe uma peca adjacente pra saltar por cima
			if (tabuleiro[x+1][y] != '1'){
			    printf("Movimento invalido b2\n");
				return false;
			}
			//checka se o espaco do salto esta vazio
			if (tabuleiro[x+2][y] != '0'){
				printf("Movimento invalido b3\n");
				return false;
			}
            break;
    
	    case esquerda:
            //checka se espaco na matriz pro "salto"
			if (y<2){
				printf("Movimento invalido e1\n");
				return false;
			}
			//checka se existe uma peca adjacente pra saltar por cima
			if (tabuleiro[x][y-1] != '1'){
				printf("Movimento invalido e2\n");
				return false;
			}
			//checka se o espaco do salto esta vazio
			if (tabuleiro[x][y-2] != '0'){
				printf("%c \n",tabuleiro[x][y-2]);
				printf("Movimento invalido e3\n");
				return false;
			}
            break;
	    
	    case direita:
            //checka se espaco na matriz pro "salto"
			if (y>4){
				printf("Movimento invalido d1\n");
				return false;
			}
			//checka se existe uma peca adjacente pra saltar por cima
			if (tabuleiro[x][y+1] != '1'){
				printf("Movimento invalido d2\n");
				return false;
			}
			//checka se o espaco do salto esta vazio
			if (tabuleiro[x][y+2] != '0'){
				printf("Movimento invalido d3\n");
				return false;
			}
            break;
	    
	    default:
			break;
	}
	
	printf("sucesso");
    return true;
}

int getNumeroJogadas(char tabuleiro[][SIZE]) {
	int jogadas = 0;
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			if (tabuleiro[x][y] == '1') {
				if (x-1 <= 6 && tabuleiro[x-1][y] == '1') {
					if (x-2 <= 6 && tabuleiro[x-2][y] == '0') {
						jogadas++;
					}
				}
			}
		}
	}
	return jogadas;
}

void realizaJogada(struct Jogada jogada, char tabuleiro[][SIZE]){
	//remove a peca do espaco escolhido
	int x = jogada.x;
	int y = jogada.y; 
	int direcao = jogada.direcao;
	
	tabuleiro[jogada.x][jogada.y] = '0';
	
	switch( direcao ){
    case cima:
    	//come a peca adjacante
		tabuleiro[x-1][y] = '0';
		//add peca ao local do salto
		tabuleiro[x-2][y] = '1';
		break;
    
    case baixo:
        //come a peca adjacante
		tabuleiro[x+1][y] = '0';
		//add peca ao local do salto
		tabuleiro[x+2][y] = '1';
        break;
    
    case esquerda:
    	//come a peca adjacante
		tabuleiro[x][y-1] = '0';
		//add peca ao local do salto
		tabuleiro[x][y-2] = '1';
        break;
            
    case direita:
        //come a peca adjacante
		tabuleiro[x][y+1] = '0';
		//add peca ao local do salto
		tabuleiro[x][y+2] = '1';
        break;
    
    default: 
    	break;
	}
}

bool joga(char tabuleiro[][SIZE]){
	bool jogou = false;
	struct Jogada j;

	j = getInputDoJogador();
	
	if(validarJogada(j, tabuleiro)){
		realizaJogada(j, tabuleiro);
		jogou = true;
	}

	return jogou;
}

bool existeJogada(char tabuleiro[][SIZE]) {

	int jogadas = 0;
	for (int i = 0; i < 4; i++) { //pra frente, pra tras, pro lado e pro outro
		jogadas += getNumeroJogadas(tabuleiro);
		rotacionaTabuleiro(tabuleiro);
 	}

	return jogadas != 0;
}

void rotacionaTabuleiro(char tabuleiro[][SIZE]) {
	int tmp;
	for (int i = 0; i < SIZE/2; i++){
		for (int j = i; j < SIZE-i-1; j++){
			tmp = tabuleiro[i][j];
			tabuleiro[i][j] = tabuleiro[j][SIZE-i-1];
			tabuleiro[j][SIZE-i-1] = tabuleiro[SIZE-i-1][SIZE-j-1];
			tabuleiro[SIZE-i-1][SIZE-j-1] = tabuleiro[SIZE-j-1][i];
			tabuleiro[SIZE-j-1][i] = tmp;
		}
	}
}

bool venceu(char tabuleiro[][SIZE]) {
	bool flag = true;
	for(int x = 0; x < SIZE; x++) {
		for(int y = 0; y < SIZE; y++) {
			if(tabuleiro[x][y] == '1' && (x != 3 && y != 3)) {
				flag = false;
			}
		}
	}

	return flag;
}



