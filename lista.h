#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct tipoElemento{
	int valor;
	struct tipoElemento *prox;
}TElemento;

typedef struct TipoLista{
	TElemento *inicio;
	TElemento *fim;
	int total;
}TLista;

TLista lista;


int hash_function(int input, int tamanho);
void inicializaLista(TLista *vetor);
int menu();

void insere(TLista *lista, int input);
void insere_vetor(TLista *vetor, int tamanho);

void exibir_lista(TLista *lista);
void exibir_vetor(TLista *vetor, int tamanho);

void excluirElemento(TLista *lista, int input);
void excluir_vetor(TLista *vetor, int tamanho);

void buscar_valor(TLista *lista, int argumento, int posicao);
void buscar_vetor(TLista *vetor, int tamanho);
