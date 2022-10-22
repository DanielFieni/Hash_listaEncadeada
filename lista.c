#include "lista.h"

// Funcao para definir a posicao que o entrada ocupara no vetor
int hash_function(int input, int tamanho){
	// Retornara o resto da divisao
	return input % tamanho;
}

// Inicializando a lista
void inicializaLista(TLista *vetor){

	vetor->inicio = NULL;
	vetor->fim = NULL;
	vetor->total = 0;

}

int menu(){
	
	int opcao;
	system("CLS"); 
    printf("\n\n\n\t=====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir.\n");
    printf("2 - Exibir Lista Completa.\n");
    printf("3 - Excluir.\n");
    printf("4 - Buscar valor.\n");
    printf("\tInforme OPCAO desejada: ");
    
    scanf("%d",&opcao);
	
	if ((opcao > 4) || (opcao < 0)){
		printf("\n\n\n");
		printf("+-------------------------------+\n");
		printf("|ERRO  	------------------------|\n");
		printf("|Opcao invalida	----------------|\n");
		printf("|Tente outra vez    ------------|\n");
		printf("+-------------------------------+\n\n\n");
		system("PAUSE");
	}
	return opcao;
}

void insere(TLista *lista, int input){
	// Alocar um espaco para o novo elemento que sera inserido
	TElemento *novo = (TElemento*)malloc(sizeof(TElemento));

	novo->valor = input;
	novo->prox = NULL;
	
	if (lista->inicio == NULL)
	{
		// Se a lista estiver vazia, ira inserir no inicio dela
		lista->inicio = novo;

	} else {

		// Caso ja existe algum elemento na lista ele sera inserido no final dela
		TElemento *anterior = lista->inicio;

		while (anterior->prox != NULL)
		{
			anterior = anterior->prox;
		}
		anterior->prox = novo;

	}
	
	// Aumenta a quantidade total de elemento da lista
	lista->total++;
	
}

void insere_vetor(TLista *vetor, int tamanho){

	int posicao_hash, input;

	printf("\n\nInsira um valor: ");
	scanf("%d" , &input);

	//Retorna a posicao do vetor onde o elemento sera inserido
	posicao_hash = hash_function(input, tamanho);

	// Insere o elemento na lista de sua posicao do vetor
	insere(&vetor[posicao_hash], input);

}

void exibir_lista(TLista *lista){

	TElemento *atual = lista->inicio;

	int cont=0;

	// Enquanto nao for o final da lista
	while(atual != NULL){
		printf("(%d) - Valor: %d\n" ,++cont, atual->valor);
		atual = atual->prox;
	}
	printf("\n\n");

}

void exibir_vetor(TLista *vetor, int tamanho){
	int i;

	for(i = 0; i < tamanho; i++){

		printf("Lista %d; Tamanho: %d\n" ,i, vetor[i].total);
		//Eh passado como parametro cada posicao do vetor para ser listado no exibir_lista()
		exibir_lista(&vetor[i]);

	}

}

void excluirElemento(TLista *lista, int input){

	TElemento *atual=NULL, *anterior=NULL;

	// Determinar se o valor foi excluido
	int excluido = 0;
	
	if(lista->inicio == NULL)
	{
		//Se a lista estiver vazia
		printf("\n\nNenhum elemento na lista\n\n\n");	

	}else {

		atual = lista->inicio;
		while(atual != NULL){

			//Vai percorrer ate achar o elemento que pretende ser excluido
			if(atual->valor == input){
				excluido = 1;
				if(anterior == NULL){

					//Se o elemento for o primeiro da lista ele vai excluir, e o proximo valor sera o primeiro
					lista->inicio = atual->prox;

				} else {

					anterior->prox = atual->prox;
					if(atual == lista->fim){
						//Se o elemento for o ultimo da lista, ele ira exclui-lo e o fim sera null
						lista->fim = NULL;
					}
				}

				//Liberando espaco na memoria
				free(atual);
				// Diminuindo a quantidade de valores da lista
				lista->total--;
				break;
			}

			//O anterior recebe o atual porque quando um elemento do meio da lista for excluido, ele fara a ligacao com o proximo elemento
			anterior = atual;
			atual = atual->prox;
		}

		if(!excluido){

			// Quando o elemento nao for encontrado
			printf("\t\n\nElemento %d n�o encontrado!!", input);
			printf("\t\n\nTente novamente\n\n\n");

		}
	}

}

void excluir_vetor(TLista *vetor, int tamanho){

	int posicao_hash, input;

	printf("\n\nInsira o valor que sera removido: ");
	scanf("%d" ,&input);

	posicao_hash = hash_function(input, tamanho);

	//Encontra a posicao do vetor que o elemento esta para ser excluido
	excluirElemento(&vetor[posicao_hash], input);

}

void buscar_valor(TLista *lista, int argumento, int posicao){
	TElemento *atual = lista->inicio;
	int encontrado=0;
	
	if(lista->inicio == NULL){
		
		printf("\t\n\nFILA VAZIA!!\n\n\n");
	} else {

		while(atual != NULL){

			if(atual->valor == argumento){
				encontrado = 1;
				printf("\t\n\nElemento %d encontrado!\n");
				printf("Lista: %d; tamanho: %d\n\n\n" ,posicao, lista->total);
			}

			atual = atual->prox;
		}
		
		if(!encontrado){
			printf("\t\n\nElemento %d n�o encontrado!!", argumento);
			printf("\t\n\nTente novamente\n\n\n");
		}
	}
	
}

void buscar_vetor(TLista *vetor, int tamanho){

	int posicao_hash, input;

	printf("\n\nInsira o valor que ser� pesquisado: ");
	scanf("%d" ,&input);

	posicao_hash = hash_function(input, tamanho);

	buscar_valor(&vetor[posicao_hash], input, posicao_hash);
}
