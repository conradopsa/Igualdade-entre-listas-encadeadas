#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
	int valor;
	struct No * prox;
} No;

/*
	Fa�a um programa em C que leia duas listas simplesmente encadeadas e
	implemente uma fun��o que verifica e retorna se as duas lista s�o iguais ou
	diferentes.
*/

No * novoNo(int valor){
	No * novo = malloc(sizeof(No));
	novo->valor = valor;
	novo->prox = NULL;
	
	return novo;
}

void adicionarF(No ** iniL, int valor){
	//(*iniL) ou *iniL � o ponteiro fora da fun��o
	
	//Uma exce��o para caso o ponteiro seja nulo
	if ((*iniL) == NULL){
		(*iniL) = novoNo(valor);
		return;
	}		
	
	No * aux = (*iniL);
	
	//Encontra o ultimo n�
	while (aux->prox != NULL)
		aux = aux->prox;	
	
	//Declara��o do novo n�
	No * novo = novoNo(valor);
	
	//add o novo n� no pr�ximo do ultimo n�
	aux->prox = novo;
}

void adicionarI(No ** iniL, int valor){
	//(*iniL) ou *iniL � o ponteiro fora da fun��o
	
	No* aux = novoNo(valor);
	aux->prox = (*iniL);
	
	(*iniL) = aux;
}

void remover(No ** iniL, int valor){	
	//(*iniL) ou *iniL � o ponteiro fora da fun��o
		
	No * ant = NULL;	
	No * aux = (*iniL);
	
	if (aux == NULL){
		printf("Lista Vazia\n");
		return;
	}		
	
	//Encontra o valor, sempre armazenando o n� anterior
	while (aux->valor != valor && aux != NULL){
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		printf("Valor n�o existente\n");
	else{		
		if (ant!=NULL){
			ant->prox = aux->prox;	
		}					
		else		
			*iniL = aux->prox;	
			
		free(aux);
	}	
}

void imprimir(No * aux) {
	if (aux == NULL)
		printf("Lista vazia!\n");
	
	while (aux!=NULL){	
 		printf("| %d | ", aux->valor);
 		aux=aux->prox;
 	}
 	printf("\n__________________________________\n");
}

int compararlista(No * aux1, No * aux2){

	//Percorre aux1 e aux2, comparando cada valor
	while(aux1 != NULL || aux2 != NULL){
		
		/* Corrigindo um bug:
		   Se alguma vari�vel (aux) for nula, 
		   n�o ser� poss�vel alca�ar o aux->valor */
		if (aux1==NULL || aux2==NULL)
			return 0;
		
		if (aux1->valor == aux2->valor){
			aux1=aux1->prox;
			aux2=aux2->prox;
		}		
		else //Se n�o, falso (0)
			return 0;
	}
	
	//Percorreu tudo e todos os itens s�o iguais, verdadeiro (1)
	return 1; 
}
	
void leituraListas(No ** ini, int n){
	int valor, op, i=0;
	
	do{
		printf("\n***************************************\n");
		printf("\n		LISTA %d\n", n);
		printf("\n***************************************\n\n");
		printf("\n\n1 - Inserir no inicio\n");
		printf("2 - Inserir no final\n");
		printf("3 - Imprimir lista\n");
		printf("4 - Remover elemento\n");
		printf("0 - Sair\n");
		
		printf("Opcao: ");
		scanf("%d", &op);
		
		printf("\n__________________________________\n");
		
		if(op == 1){
			printf("Valor a ser inserido no inicio: ");
			scanf("%d", &valor);
			adicionarI(&(*ini), valor);
		} 
		else if(op == 2){
			printf("Valor a ser inserido no final: ");
			scanf("%d", &valor);
			adicionarF(&(*ini), valor);
		} 
		else if(op == 3){
			imprimir(*ini);
			printf("\n");
			system("pause");
		} 
		else if(op == 4){
		 	printf("Valor a ser removido: ");
			scanf("%d", &valor);
			remover(&(*ini), valor);
		}
		
		system("cls");
		
		i++;
	}while(op != 0);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	No *lista1 = NULL, *lista2 = NULL;
	
	leituraListas(&lista1, 1);
	leituraListas(&lista2, 2);
	
	//Compara
	if (compararlista(lista1, lista2) == 1)
		printf("As listas s�o iguais!");
	else
		printf("As listas N�O s�o iguais!");
}
