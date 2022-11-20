#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>//incluir a biblioteca padr�o de aloca��o de mem�ria da linguagem
#include<conio.h>

typedef struct nodo
	{
		int info,info2;
		struct nodo * prox;
	}Nodo;

void inserir(int n, int n2);
void mostrar();
int retirar();
int referenciaOca();//criada para a apresenta��o
int criaLixo();// criada para apresenta��o
int esvaziar();

Nodo * topo = NULL;/*armazenamento do apontador "topo" est� no registro de ativa��o para todo o programa
					a cada vez que o controle atinge a chamada de um Nodo atrav�s do malloc() resulta na
					numa c�lula sendo alocada em algum local do heap*/
int main(){
	int num, num2;
	int opc;
	
	do{
		system("cls");
		printf("Bem Vindo a Pilha Dinamica!\n");
		printf("1 inserir: \n");
		printf("2 Mostrar: \n");
		printf("3 Excluir: \n");
		printf("5 Esvaziar toda a pilha: \n");
		printf("5 Lixo: \n");
		printf("4 Alocacao Oca: \n");
		printf("7 sair: \n");
		printf("\n");
		scanf("%d",&opc);
	
		switch(opc){
			case 1:
				system("cls");
				printf("Digite um Numero:\n");
				scanf("%d", &num);
				printf("Digite outro Numero:\n");
				scanf("%d", &num2);
				inserir(num, num2);
				mostrar();
				break;
			case 2:
				system("cls");
				mostrar();
				break;
			case 3:
				system("cls");
				retirar();
				mostrar();
				break;
			case 4:
				system("cls");
				esvaziar();
				mostrar();
				break;
			case 5:
				system("cls");
				criaLixo();
				mostrar();
				break;
			case 6:
				system("cls");
				referenciaOca();
				break;		
			case 7:
				system("cls");
				exit(1);
				break;				
			default:
			printf("Numero Invalido!\n\n");
		}getch();		
	}while(opc!=5);
	printf("Saindo da Pilha");		
	getch();		
}

void inserir(int n, int n2){
	Nodo * novo;
	novo = (Nodo*)malloc(sizeof(Nodo));/*solicitando um espa�o na mem�ria do tipo 
										"Nodo".*/
		if(novo == NULL) exit (1);//se a aloca��o n�o ocorrer, sair do programa com "exit (1)";
		novo -> info = n;
		novo -> info2 = n2;
	
		if (topo == NULL){
			novo -> prox = NULL;
			topo = novo;
		}
		else{
		novo -> prox = topo;
			topo = novo;
		}
}

void mostrar(){
		Nodo * aux;
		aux = topo;
		if(topo == NULL){
		printf("Nada para Mostrar!\n");
		getch();
		}
		while(aux != NULL){
			if(aux == topo && aux->prox == NULL){
				printf("Topo-->[ %d | %d ]-->NULL", aux->info, aux->info2);
			}else if(aux == topo){
				printf("Topo-->[ %d | %d ]-->", aux->info, aux->info2);
			}else if(aux->prox == NULL){
				printf("[ %d | %d ]-->NULL", aux->info, aux->info2);
			}else{
				printf("[ %d | %d ]-->", aux->info, aux->info2);
			}
		aux = aux->prox;
	}
}

int retirar(){
	Nodo * aux;
	int n;
	int n2;
    if (topo == NULL){
	printf("Pilha Vazia!\n");
    return 0;
    }
	aux = topo;
	n = aux -> info;
	n2 = aux -> info2;
	topo = topo->prox;
	free(aux);
	return n,n2;
}

int criaLixo(){
	Nodo * aux;
	int n;
    if (topo == NULL){
	printf("Pilha Vazia!\n");
    return 0;
    }
	aux = topo;
	n = aux -> info;
	topo->prox = NULL;/* aponta o topo para NULL, 
						 n�o aponta mais para a pr�xima c�lula;
						 as c�lulas mais a direita se tornam lixo.
						 
						 refer�ncia ocorre antes da libera��o
					  */
}

int referenciaOca(){
	Nodo * aux;
	int n;
	int n2;
    if (topo == NULL){
	printf("Pilha Vazia!\n");
    return 0;
    }
	aux = topo;
	n = aux -> info;
	n2 = aux -> info2;
	free(topo->prox);/*libera a c�lula seguinte a que est� apontada no topo
						
						Libera��o ocorre antes da �ltima refer�ncia
					*/
	return n,n2;
}

int esvaziar(){
	Nodo * aux;
	int n, n2;
	do{			
		if(topo == NULL)
		{
			printf("Pilha Vazia!\n");
			return 0;
		}
		aux = topo;
		n = aux -> info;
		n2 = aux -> info2;
		topo = topo -> prox;
		free(aux);
	}while(n != NULL);
}

