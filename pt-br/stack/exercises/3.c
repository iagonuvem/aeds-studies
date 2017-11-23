#include <stdio.h>	

struct no{
	int info;
	struct no* prox;
};
typedef struct no No;

struct pilha{
	struct no* topo;
};
typedef struct pilha Pilha;

void popn(Pilha* p, int n){	
	for (int i = 0; i < n; ++i)
	{
		if(!vazia(p)){ // Se a pilha não estiver vazia
			pop(p); // Remove o topo
		}
		else{
			break;
		}
	}
}


Pilha* pop(Pilha* p){
	Pilha* aux = criar();
	aux->topo = p->topo->prox;
	free(p->topo);
	p = aux;

	return p;
}

Pilha* push(Pilha* p, int info){
	No* novo = (No*) malloc(sizeof(No));
	novo->info = info;
	novo->prox = p->topo;
	p->topo = novo;

	return p;
}

Pilha* criar(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

void imprime(Pilha* p){
	Pilha* aux = criar();
	while(!vazia(p)){ // 'Percorre' a pilha enquanto ela tiver elementos
		int a = pop(p); // Remove o topo da pilha e armazena o topo em 'v'
		printf("%d\n", a); // imprime 
		push(aux,a); // coloca o topo da pilha 'p' na pilha auxiliar
	}

	while(!vazia(aux)){
		push(p, pop(aux)); 
	}

	free(aux);
}

int vazia(Pilha* p){
	return (p->topo == NULL);
}

int main(int argc, char const *argv[])
{
	Pilha* teste = criar();

	push(teste,1);
	push(teste,2);
	push(teste,3);
	push(teste,4);

	imprime(teste);

	popn(teste,2);

	imprime(teste);

	return 0;
}