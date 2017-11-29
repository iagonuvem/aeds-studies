# Filas
Nessa pasta estão todos os exercícios e práticas de Filas. 
Para entender esse conceito, é preciso ter conhecimento prévio dos seguintes assuntos:

- Linguagem C
- Ponteiros
- Alocação Dinâmica
- [Listas](https://github.com/iagonuvem/aeds-studies/tree/master/pt-br/linked-list)

## 1. Como funciona
As filas são estruturas de dados análogas à uma fila de banco - o próprio nome é bem intuitivo - Isto é, em uma fila de banco, quem chega primeiro é atendido primeiro, e quem chega por último é atendido por último, e a fila sempre cresce pelo final, ou seja, sempre que alguem chega vai para o final da fila. Esse conceito é conhecido como "FIFO".

> FIFO : "First in, First Out"

em português: "Primeiro a entrar, Primeiro a sair", e é esse o conceito que temos que saber para entender as **filas**.É importante saber que nós só podemos retirar elementos do início de uma fila, e só podemos também ter acesso ao inicio e ao fim, logo se for nescessário acessar os demais elementos de uma fila, devemos remover os elementos 'mais velhos na lista'. A implementação de uma fila pode ser feita de 2 maneiras: *Com vetores* e *Com lista*, por hora vamos trabalhar só com lista.

## Estrutura de uma fila 

Para a estrutura de fila, precisamos saber qual o nó de início e nó do fim da lista, logo a estrutura de uma fila é feita assim:

```c
struct fila{
	No* ini;
	No* fim;
};
typedef struct fila Fila;
```

## Funções Básicas *(Utilizando Listas)*
Para as funcionalidades básicas das filas devemos ficar atentos as seguintes situações:
- Se Inicio ou Fim tiverem algum valor, isso implica que AMBOS tem que ter algum valor, visto que não é possível ter uma lista com início e sem final ou com final sem início.
- A inserção é feita sempre no final, e a remoção sempre no inicio.

1. Inserir um nó em uma fila

```c
void inserir(Fila* f, int v) {
	// Alocamos um novo nó 
    No* novo = (No*) malloc(sizeof(No));

    novo->info = v; // Seta a informação do nó
    novo->prox = NULL; // O próximo é Nulo pois o nó é adicionado no fim.

    /**
	* Vericamos se o fim da fila não é nulo, isto é, se a fila possui ao menos
	* 1 nó
	*/
    if (f->fim != NULL){
    	/**
    	* Referencia o próximo ao fim como o novo nó criado, visto que este
    	* será adicionado 'após' o 'antigo' final.
    	*/
        f->fim->prox = novo; 
    }

    // Seta o fim da fila como o novo nó criado.
    f->fim = novo;

    /**
    * Verificamos aqui se o início da lista é vazio, se o início for vazio
    * significa que o nó que foi adicionado é o primeiro nó da fila
    */
    if (f->ini == NULL){
    	/**
    	* Como só possui um elemento na fila, o elemento de inicio é o mesmo
    	* do final, aqui é a única vez que mechemos no inicio da fila na 
    	* funcionalidade de adicionar, pois sempre colocamos novos elementos
    	* no final da fila.
    	*/
        f->ini = f->fim;
    }
}
```
2. Remover um nó de uma fila

```c
int remover(Fila* f) {
    int v; // Variável auxiliar para armazenar o valor retirado
    No* p; // Nó auxiliar para não perdermos a referência do resto da fila

    if(f->ini == NULL) { // Se a fila for vazia, não temos nada o que remover
        printf("Fila vazia.\n"); // Exibe uma mensagem de erro
        exit(1); // E aborta a função
    }

    // armazena a informação do inicio na variável
    v = f->ini->info;

    /**
    * Colocamos o auxiliar como sendo o 'segundo da fila', para não perdermos
    * a referência, então podemos liberar o inicio da fila sem preocupação.
    */
    p = f->ini->prox;

    // Libera o início da fila
    free(f->ini);

    /**
    * Referencia o inicio como sendo o valor da auxiliar, antigo 'segundo da
    * fila'
    */
    f->ini = p;

    /**
    * Se APÓS retirarmos o nó, o inicio da lista for vazio, significa que
    * retiramos o único nó da fila, então...
    */
    if (f->ini == NULL)
        f->fim = NULL; // O fim também precisa ser vazio
    
    return v; // Retornamos o valor retirado
}
```
3. Imprimir uma fila

```c
void imprimir(Fila* f) {
	/**
	* Aloca espaço para uma fila auxiliar, pois sabendo que só podemos acessar
	* o inicio e fim de uma lista, temos que imprimir e retirar, e armazenar
	* os valores retirados em uma nova fila para não "perdermos" a fila.
	*/
	Fila* aux = (Fila*) malloc(sizeof(Fila));

	while(f->ini != NULL){
		/**
		* Cria um nó e iguala ele ao 'segundo da fila', para não perder
		* a referencia, fazendo isso podemos agora podemos remover o primeiro
		* sem maiores preocupações.
		*/
		No* t = f->ini->prox;

		// Imprime a informação
		printf("%d" , f->ini->info);

		/**
		* Coloca o inicio da fila principal no final da fila auxiliar
		*/
		aux->fim = f->ini;

		/**
		* Se o inicio da lista auxiliar for vazio (ainda não entrou
		* nenhum elemento), iguala ao fim. ps: só entra nesse condicional
		* uma vez.
		*/
		if(aux->ini == NULL){
			aux->ini = aux->fim;
		}

		// remove o inicio
		free(f->ini);

		// Seta o novo primeiro da fila como o auxiliar(antigo segundo)
		f->ini = aux->ini;

		// Se chegarmos ao ultimo elemento
		if(aux->ini == NULL){
			f->ini = NULL; // Seta o inicio como NULL
			f->fim = NULL; // Seta o final como NULL
		}
		
	}

	/**
	* Ja percorremos toda a fila imprimindo as informações e
	* armazenando em uma fila auxiliar, agora precisamos voltar tudo para
	* a fila principal utilizando o processo de inserção explicado acima e 
	* depois liberar a fila auxiliar.
	*/
	while( aux->ini != NULL){
		No* t = aux->ini->prox;

		if(f->fim != NULL){
			f->fim->prox = aux->ini;
		}

		f->fim = aux->ini;

		if(f->ini == NULL){ // Primeiro nó
			f->ini = f->fim;
		}
		
		free(aux->ini);
		aux->ini = t;
	}

	// Libera a fila auxiliar
	free(aux);
}
```