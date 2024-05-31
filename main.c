#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char* removeP() {
	setlocale(LC_ALL, "Portuguese");
	
	
	char message[100] = "";									// Variável para armazenar a mensagem criptografada (comporta até 99 caracteres + "\0"
	char novo[100] = "";									// Variável que vai receber a mensagem sem os P's
	int i;													// Variável de controle
	printf("Digite sua mensagem criptografada:\n");
	
	
	if (fgets(message, sizeof(message), stdin) != NULL) {	// Capta dados do teclado do usuário, armazenando na variável 'message'
		int len = strlen(message);							// Variável que armazena o tamanho da mensagem
		
		for(i = 1; i < len; i = i + 2) {
			char temp[2] = {message[i], '\0'};				// Transforma o caractere de message[i] em string ao juntar com '\0'
			strcat(novo, temp);								// Concatena duas strings: novo e temp. Ou seja, novo = novo + temp
			
			if (message[i + 1] == ' ') {
				strcat(novo, " ");							// Concatena um espaço à string, caso o próximo caractere for um espaço
				i++;										// Incrementa i para que a iteração se mantenha sempre no índice de caracteres desejados
			}
			
		}
		//printf("%s", novo);
		return novo;
	} else {
		printf("Mensagem indefinida!");
		return NULL;
	}
	/* Função para remover os P's definida, para utilizá-la em outro local, 
	basta chamar por 'removeP()' e assim teremos a string armazenada em 'novo'*/
	
}

char* decifraMsg() {
	char* msg = removeP();
	
}

int main(int argc, char *argv[]) {
	
	return 0;
}
