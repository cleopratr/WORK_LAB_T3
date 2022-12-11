#include <stdio.h>
#include <stdlib.h>

int main() { 
    int value = 0; // variável que armazena o valor digitado pelo usuário, sendo depois acrescentado ao vetor
    unsigned int vector[200]; // vetor com 200 posicoes, guardando valores de 1 a 5000
    int aux = 0; // variável utilizada para incrementar os valores dos números a serem somados de acordo com sua posição no vetor
    
    // zerando as posicoes do vetor
    for(int i = 0; i < 200; i++){
    	vector[i] = 0;
    
    }    
    while (value != -1) {  // se o valor digitado é menos um um código se encerra
        printf("Digite um valor entre 1 e 5000:\n");
        scanf("%d", &value); // lê o valor digitado pelo o usuário
        
        if (value > -1 && value <= 5000) { // verifica se o valor digitado está entre 0 e 5000
        vector[value/32] = vector[value/32] | 2147483648 >> (value%32); // encontra a posicao e ativa o bit do número que foi digitado

        }
    }   
    
    for (int i = 0; i < 200; i++){  // Percorre as posições externas do vetor de 200      
             for(int j = 0; j < 32; j++){ // Percorre as posições internas do vetor de 200, que guardam 32 bits.
             	if(vector[i] & 2147483648 >> j){ // percorre os 32 bits verificando se algum deles está ativado 
             		printf("%d\n", (j + aux)); // se estiver ele printa o valor armazenado
             	}
             	
             	
             }
              aux = aux + 32; // Ao ir de uma posição para outra deve ser incrementado o valor 32
	}
    return 0; 
} 
