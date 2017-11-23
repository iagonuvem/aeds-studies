# Listas Simplesmente Encadeadas
Nessa pasta estão todos os exercícios e práticas de Listas encadeadas. 
Para entender esse conceito, é preciso ter conhecimento prévio dos seguintes assuntos:

- Linguagem C
- Ponteiros
- Alocação Dinâmica

## 1. Como funciona
As listas encadeadas são estruturas de dados simples que são compostas por _nós_, ou como você preferir chamar, que contém uma informação e um endereço de memória do próximo elemento da lista. Veja abaixo uma ilustração de um nó de uma lista

### **Exemplo Teórico**
	
---------------------------

##### Endereço de memória : 200
Informação | Próximo Endereço
------------ | -------------	
Info 1| 300

##### Endereço de memória : 300
Informação | Próximo Endereço
------------ | -------------	
Info 2| NULL

---------------------------

No exemplo acima temos uma lista simplesmente encadeada com 2 nós, o primeiro nó possui o endereço de memória **200** e o segundo elemento possui o endereço de memória **300**.O endereço de memória da lista sempre é o endereço do primeiro elemento da lista, nesse caso, essa lista possui o endereço **200**. No endereço 200, o campo *Próximo Endereço* tem o valor 300, isso significa que o NÓ alocado no endereço 200 **APONTA** para o NÓ alocado no endereço 300. O nó alocado no endereço 300 por sua vez tem como *Próximo Endereço* o valor NULL, ou seja, não aponta para ninguém, indicando assim o **FIM DA LISTA**.

Agora vamos para o lado bom da força, aplicar esse conceito em programação.

### **Criação de lista em C**

1. **Criar a estrutura do nó**

```c
struct no {
    int info; // Informação do nó
    struct no* prox; // Endereço de memória do próximo nó da lista
};
typedef struct no No; // Define um apelido para a estrutura
```

2. **Criar uma função que inicialize a lista Vazia**

```c
/* Cria uma função do tipo "Nó" que retorna um ponteiro para um nó */ 
No* criar() {    
	return NULL; // retorna um nó NULO/VAZIO
}
```
Agora nós ja temos um estrutura do nó, e uma função que inicializa a lista retornando o endereço de memória da lista criada, agora precisamos mecher nessa lista, ou seja, Inserir, Retirar, Acessar elementos dessa lista, veremos isso a seguir.

### **Operações com lista em C**
Sempre que trabalhamos com lista, começamos a fazer as operações pelo inicio, pois o endereço de memória da lista aponta sempre para o primeiró nó, ou seja, quando vamos inserir um novo nó, inserimos no inicio da lista, e o endereço da lista é atualizado apontando para o novo nó inserido.

1. **Inserir um novo nó**

```c
/*Função recebe como parâmetro o endereço de memória do primeiro nó da lista
e a informação que será inserida no novo nó*/
No* inserir(No* lista, int info){
	// Aloca um espaço suficiente para um nó na memória
	No* novo = (No*) malloc(sizeof(No)); 

	novo->info = info; // Seta a informação do novo nó

	/* 
	Seta o endereço do próximo nó 
	como o endereço da lista(primeiro nó da lista),
	ao fazer isso, colocamos o novo nó "na frente" do antigo inicio da lista,
	tornando-o o novo início da lista 
	*/
	novo->prox = lista; 

	/* Retorna o endereço do nó inserido, novo início da lista */
	return novo; 
}
```

2. **Remover um nó**

```c
/*Função recebe como parâmetro o endereço de memória do primeiro nó da lista
e a informação que será removida da lista*/
No* remover(No* lista, int info){
	/*
	Criamos um nó 'anterior' auxiliar
	*/
	No* ant = NULL;
    No* p = lista;

    // Percorre a lista enquanto não encontrar a informação
    while (p != NULL && p->info != info) {
        ant = p;

        /*
        Coloca o endereço de memória de p como o endereço do próximo nó,
        sendo assim, quando o endereço for NULO/VAZIO significa que chegou
        no final da lista, parando a repetição.
        */
        p = p->prox; 
    }

    /*
    Tratamentos de excessões
    */

    /*
    Se p for NULO, significa que percorreu toda a lista e não encontrou
    nenhum elemento igual ao que queremos retirar, então ....
    */
    if (p == NULL){
        return l; // Retorna a própria lista
    }

    /* 
    Se o 'anterior' for NULO, significa que o elemento que queremos
    retirar é o primeiro elemento da lista, então...
    */
    if (ant == NULL) {
        // A Lista agora aponta para o segundo elemento
        l = p->prox; 
    }
    else { // se não for o primeiro...
    	/*
    	Faz o anterior ao elemento encontrado apontar para o próximo ao
    	elemento encontrado, "pulando" o elemento encontrado
    	*/
        ant->prox = p->prox;
    }
    free(p); // Libera o nó
    return l;
}
```

3. **Alterar a informação de um nó**

```c
/*Função recebe como parâmetro o endereço de memória do primeiro nó da lista, a informação do nó que queremos alterar e a nova informação*/
No* remover(No* lista, int info, int new_info){
	/*
	Criamos um nó 'anterior' auxiliar
	*/
	No* ant = NULL;
    No* p = lista;

    // Percorre a lista enquanto não encontrar a informação
    while (p != NULL && p->info != info) {
        ant = p;

        /*
        Coloca o endereço de memória de p como o endereço do próximo nó,
        sendo assim, quando o endereço for NULO/VAZIO significa que chegou
        no final da lista, parando a repetição.
        */
        p = p->prox; 
    }

    /*
    Tratamentos de excessões
    */

    /*
    Se p for NULO, significa que percorreu toda a lista e não encontrou
    nenhum elemento igual ao que queremos retirar, então ....
    */
    if (p == NULL){
        return l; // Retorna a própria lista
    }
    else{ // se encontrou algum nó correspondente
    	p->info = p->new_info; // Atualiza a informação do nó
    }

    return l; // Retorna a lista atualizada
}
```

# Listas duplamente encadeadas

A diferença básica entre a lista simplesmente encadeada e duplamente encadeada, é que Na lista Simplesmente encadeada temos apenas o endereço de memória do próximo nó como referência e na Duplamente encadeada temos o endereço do próximo e o anterior, logo a definição da estrutura apenas se altera um pouco.

### Estrutura de lista duplamente encadeada

```c
struct no {
    int info; // Informação do nó
    struct no* ant; // Endereço de memória do nó anterior
    struct no* prox; // Endereço de memória do próximo nó
};
typedef struct no No; // Define um apelido para a estrutura
```