#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char* removeP();
void rot13(char* str);
char* decifraMsg();

int main(int argc, char *argv[]) {
	char* decifra = decifraMsg();
	if (decifra != NULL) {
		printf("Mensagem decodificada: %s\n", decifra);
		free(decifra);
	}
	return 0;
}

// Função para remover os P's definida, para utilizá-la em outro local, basta chamar por 'removeP()' e assim teremos a string armazenada em 'novo'
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
}

// Função que executa a decodificação em ROT-13
void rot13(char* str) {
	int i;													// Variável de controle
	for (i = 0; str[i] != '\0'; i++) {						// O loop só executa enquanto o caractere não for terminador nulo
		char c = str[i];									// Variável para armazenar o caractere respectivo ao índice 'i' de str
		if (c >= 'A' && c <= 'Z') {							// Condicional que determina se 'c' está entre 'A' e 'Z' (maiúsculas)
			str[i] = (c - 'A' + 13) % 26 + 'A';
		} else if (c >= 'a' && c <= 'z') {					// Condicional que determina se 'c' está entre 'A' e 'Z' (minúsculas)
			str[i] = (c - 'a' + 13) % 26 + 'a';
		}
	}
}

char* decifraMsg() {
	char* msg = removeP();
	if (msg != NULL) {
		rot13(msg);
	}
	
	return msg;
}
