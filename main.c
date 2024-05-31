#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char* removeP() {
	setlocale(LC_ALL, "Portuguese");
	
	
	char message[100] = "";									// Variável para armazenar a mensagem criptografada (comporta até 99 caracteres + "\0"
	int i;													// Variável de controle
	printf("Digite sua mensagem criptografada:\n");
	
	
	if (fgets(message, sizeof(message), stdin) != NULL) {	// Capta dados do teclado do usuário, armazenando na variável 'message'
		int len = strlen(message);							// Variável que armazena o tamanho da mensagem
		
		char* novo = (char*)malloc(len / 2 + 1);			// Não entendi esse código, sei que aloca memória para que possa editar a string depois
		
		if (novo == NULL) {
			printf("Erro ao alocar memória\n");				// Caso não haja sucesso ao atribuir 'novo', essa mensagem será exibida
			exit(1);
		}
		
		int j = 0;											// Variável utilizada para indicar a posição de 'novo' ao receber os caracteres específicos de 'message'
		for(i = 1; i < len; i = i + 2) {
			novo[j++] = message[i];							// Copia o caractere da posição desejada de 'message' para novo e depois incrementa 'j'
			
			if (message[i + 1] == ' ') {
				novo[j++] = ' ';							// Adiciona um espaço se o próximo caractere for um espaço
				i++;										// Incrementa i para que a iteração se mantenha sempre no índice de caracteres desejados
			}
			
		}
		novo[j] = '\0';										// Acrescenta um caractere no último índice de 'novo' para indicar o final da string
		//printf("%s", novo);
		return novo;
	} else {
		printf("Mensagem indefinida!");
		return NULL;
	}
	/* Função para remover os P's definida, para utilizá-la em outro local, 
	basta chamar por 'removeP()' e assim teremos a string armazenada em 'novo'*/
	
}

void rot13(char* str) {
	
}

char* decifraMsg() {
	char* msg = removeP();
	
}

int main(int argc, char *argv[]) {
	char* love = removeP();
	printf("%s", love);
	return 0;
}
