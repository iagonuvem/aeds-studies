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

em português: "Primeiro a entrar, Primeiro a sair", e é esse o conceito que temos que saber para entender as **filas**. A implementação de uma fila pode ser feita de 2 maneiras: *Com vetores* e *Com lista*, por hora vamos trabalhar só com lista.

## Estrutura de uma fila *(Utilizando Listas)*

Para a estrutura de fila, precisamos saber qual o nó de início e nó do fim da lista, logo a estrutura de uma fila é feita assim:

```c
struct fila{
	No* ini;
	No* fim;
};
typedef struct fila Fila;
```

## Funções 