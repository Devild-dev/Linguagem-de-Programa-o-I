#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAM 5

int checkIguais(int *v, int *x);

int main(){
	int v1[TAM], v2[TAM], check = 0, aux = 0;
		
	for(int i=0;i<TAM;i++){
		printf("Digite o %do numero do 1o vetor:\n", i+1);
		scanf("%d", &v1[i]);
	}
	printf("---------------------------------------------\n");
	for(int i=0;i<TAM;i++){
		printf("Digite o %do numero do 2o vetor:\n", i+1);
		scanf("%d", &v2[i]);
	}
	
	int teste = checkIguais(v1, v2);
	int teste2 = checkIguais(v2, v1);	
	
	if(teste2 == 1 || teste == 1){
		printf("Elementos s�o Diferentes!!!");
	}else{
		printf("Elementos s�o Iguais!!!");
	}
	getch();
}

int checkIguais(int *v, int *x){
	int check, cont = 0;	
	for(int i=0;i<TAM;i++){
		for(int j=0;j<TAM;j++){
			if(v[i] != x[j]){//se posi��o i do 1� vetor � diferente da posi��o j do 2� vetor entra e incremente 1 no contador.
				cont++;
				if(cont == TAM){//se contador recebe o tamanho do vetor o check recebe 1 e os elementos s�o diferentes.
					check = 1;
				}	
			}else{//sen�o o contador zera e encerra o segundo la�o
				cont = 0;
				j = TAM-1;
			}
		}	
	}	
	if(check == 1){
		return 1;
		}else{
		return 0;
		}	
}


