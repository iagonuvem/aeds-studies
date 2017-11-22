#include <stdio.h>
#include <stdlib.h>

/*
Considere estruturas de lista encadeadas que armazenam valores inteiros. Implemente uma
função que receba um vetor de valores inteiros com n elementos e construa uma lista encadeada
armazenando os elementos do vetor nos nós da lista. Assim, se for recebido o vetor v[5]={3, 8, 1,
7, 2}, a função deve retornar uma nova lista cujo primeiro nó tem a informação 3, o segundo a
informação 8, e assim por diante. Se o vetor tiver zero elementos, a função deve ter como valor de
retorno uma lista vazia. O protótipo da função é dado por:
No* constroi(int n, int* v);
*/

struct no{
	int info;
	struct no* prox;
};
typedef struct no No;

No* cria_lista (void){
	return NULL;
}

No* constroi(int n, int* v){
	No* l = NULL;
	
	if(n == 0){
		return l;
	}
	else{
		for(int i=0; i<n; i++){
			No* p = (No*)malloc(sizeof(No));
			p->info = v[i];
			p->prox = l;
			l = p;
		}
	}

	return l;
	
}

void imprime(No* l){
	No* p;
	
	for(p = l; p != NULL; p = p->prox){
		printf("%d -> ", p->info);
	}
	printf("\n");
}


int main(){
	
	
	int n = 5;
	int *v = (int*) malloc(n * sizeof(int));

	// preencher o vetor
	for (int i = 0; i < n; ++i)
	{
		v[i] = i+1;
	}
	
	No* lista = constroi(n,v);
	imprime(lista);

	return 0;
}