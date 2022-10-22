#include "lista.h"

int main(int argc, char *argv[]) {
	// Definindo a saida como PT-BR, assim eh possivel colocar a saida com acentos.
	setlocale(LC_ALL, "Portuguese");
	int tamanho, i, op;
	
	// Definindo o tamanho do vetor
	printf("Qual tamanho tera o vetor: ");
	scanf("%d" , &tamanho);
	
	// Cada posicao do vetor sera do tipo TLista, ou seja, tera um inicio e fim.
	TLista vetor[tamanho];
	
	for(i = 0; i < tamanho; i++){
		//Inicializando todos os campos dos vetores
		inicializaLista(&vetor[i]);
	}
	
	do {

		op = menu();
		switch (op){

			case 1: insere_vetor(vetor, tamanho); break;

			case 2: exibir_vetor(vetor, tamanho); break;

			case 3: excluir_vetor(vetor, tamanho); break;

			case 4: buscar_vetor(vetor, tamanho); break;

		}

		system("Pause");

	} while(op != 0);
		
	return 0;
}


