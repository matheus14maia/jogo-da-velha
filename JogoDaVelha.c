#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void tabuleiro(char casas2[3][3]){
	system("clear");
	
	printf("\n\n\t Jogo da Velha\n\n");
	printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
	printf("\t ----------\n");
	printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
	printf("\t ----------\n");
	printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);
}

typedef struct{
	
	char casas[3][3];
	char res;

}func;

int main(){

	int cont_jogadas, l, c, vez = 0, i, j;
	
	func *p;
	
	p = (func *) calloc(2, sizeof(func));
	
	do{ 
		cont_jogadas = 1;
		for(i = 0; i <= 2; i++){
			for(j = 0; j <= 2; j++){
				p->casas[i][j] = ' ';
				
			}
		}
		do{
			tabuleiro(p->casas);
			if(vez%2 == 0){
				printf("\nJogador1\n");
			}else{
				printf("\nJogador2\n");
			}
			printf("Digite a linha: ");
			scanf("%d", &l);	
			printf("Digite a coluna: ");
			scanf("%d", &c);
			if(l < 1 || c < 1 || l > 3 || c > 3){
				l = 0;
				c = 0;
			}else if(p->casas[l - 1][c - 1] != ' '){
				l = 0;
				c = 0;
			}else{
				if(vez%2 == 0){
					p->casas[l-1][c-1] = 'X';
				
				}else{
					p->casas[l-1][c-1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			if(p->casas[0][0] == 'X' && p->casas[0][1] == 'X' && p->casas[0][2] == 'X'){ cont_jogadas = 11;	}
			if(p->casas[1][0] == 'X' && p->casas[1][1] == 'X' && p->casas[1][2] == 'X'){ cont_jogadas = 11; }
			if(p->casas[2][0] == 'X' && p->casas[2][1] == 'X' && p->casas[2][2] == 'X'){ cont_jogadas = 11; }
			if(p->casas[0][0] == 'X' && p->casas[1][0] == 'X' && p->casas[2][0] == 'X'){ cont_jogadas = 11; }
			if(p->casas[0][1] == 'X' && p->casas[1][1] == 'X' && p->casas[2][1] == 'X'){ cont_jogadas = 11; }
			if(p->casas[0][2] == 'X' && p->casas[1][2] == 'X' && p->casas[2][2] == 'X'){ cont_jogadas = 11; }
			if(p->casas[0][0] == 'X' && p->casas[1][1] == 'X' && p->casas[2][2] == 'X'){ cont_jogadas = 11; }
			if(p->casas[0][2] == 'X' && p->casas[1][1] == 'X' && p->casas[2][0] == 'X'){ cont_jogadas = 11; }
			
			
			if(p->casas[0][0] == 'O' && p->casas[0][1] == 'O' && p->casas[0][2] == 'O'){ cont_jogadas = 12;	}
			if(p->casas[1][0] == 'O' && p->casas[1][1] == 'O' && p->casas[1][2] == 'O'){ cont_jogadas = 12; }
			if(p->casas[2][0] == 'O' && p->casas[2][1] == 'O' && p->casas[2][2] == 'O'){ cont_jogadas = 12; }
			if(p->casas[0][0] == 'O' && p->casas[1][0] == 'O' && p->casas[2][0] == 'O'){ cont_jogadas = 12; }
			if(p->casas[0][1] == 'O' && p->casas[1][1] == 'O' && p->casas[2][1] == 'O'){ cont_jogadas = 12; }
			if(p->casas[0][2] == 'O' && p->casas[1][2] == 'O' && p->casas[2][2] == 'O'){ cont_jogadas = 12; }
			if(p->casas[0][0] == 'O' && p->casas[1][1] == 'O' && p->casas[2][2] == 'O'){ cont_jogadas = 12; }
			if(p->casas[0][2] == 'O' && p->casas[1][1] == 'O' && p->casas[2][0] == 'O'){ cont_jogadas = 12; }
			
		}while(cont_jogadas <= 9);
		tabuleiro(p->casas);
		if(cont_jogadas == 10){
			printf("Deu velha!!!\n");
		}else if(cont_jogadas == 11){
			printf("Vencedor Jogador1\n");
		}else if(cont_jogadas == 12){
			printf("Vencedor Jogador2\n");
		}
		printf("Deseja jogar novamente?[S-N]\n");
		scanf(" %s", &p->res);
		
	}while(p->res == 's');
	
	return 0;
}
