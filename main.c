#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Fun��o para remover os P's definida, para utiliz�-la em outro local, basta chamar por 'removeP()' e assim teremos a string armazenada em 'novo'
char* removeP() {
	setlocale(LC_ALL, "Portuguese");
	
	
	char message[100] = "";									// Vari�vel para armazenar a mensagem criptografada (comporta at� 99 caracteres + "\0"
	int i;													// Vari�vel de controle
	printf("Digite sua mensagem criptografada:\n");
	
	
	if (fgets(message, sizeof(message), stdin) != NULL) {	// Capta dados do teclado do usu�rio, armazenando na vari�vel 'message'
		int len = strlen(message);							// Vari�vel que armazena o tamanho da mensagem
		
		char* novo = (char*)malloc(len / 2 + 1);			// N�o entendi esse c�digo, sei que aloca mem�ria para que possa editar a string depois
		
		if (novo == NULL) {
			printf("Erro ao alocar mem�ria\n");				// Caso n�o haja sucesso ao atribuir 'novo', essa mensagem ser� exibida
			exit(1);
		}
		
		int j = 0;											// Vari�vel utilizada para indicar a posi��o de 'novo' ao receber os caracteres espec�ficos de 'message'
		for(i = 1; i < len; i = i + 2) {
			novo[j++] = message[i];							// Copia o caractere da posi��o desejada de 'message' para novo e depois incrementa 'j'
			
			if (message[i + 1] == ' ') {
				novo[j++] = ' ';							// Adiciona um espa�o se o pr�ximo caractere for um espa�o
				i++;										// Incrementa i para que a itera��o se mantenha sempre no �ndice de caracteres desejados
			}
			
		}
		novo[j] = '\0';										// Acrescenta um caractere no �ltimo �ndice de 'novo' para indicar o final da string
		//printf("%s", novo);
		return novo;
	} else {
		printf("Mensagem indefinida!");
		return NULL;
	}
}

// Fun��o que executa a decodifica��o em ROT-13
void rot13(char* str) {
	int i;													// Vari�vel de controle
	for (i = 0; str[i] != '\0'; i++) {						// O loop s� executa enquanto o caractere n�o for terminador nulo
		char c = str[i];									// Vari�vel para armazenar o caractere respectivo ao �ndice 'i' de str
		if (c >= 'A' && c <= 'Z') {							// Condicional que determina se 'c' est� entre 'A' e 'Z' (mai�sculas)
			str[i] = (c - 'A' + 13) % 26 + 'A';
		} else if (c >= 'a' && c <= 'z') {					// Condicional que determina se 'c' est� entre 'A' e 'Z' (min�sculas)
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

int main(int argc, char *argv[]) {
	char* decifra = decifraMsg();
	if (decifra != NULL) {
		printf("Mensagem decodificada: %s\n", decifra);
		free(decifra);
	}
	return 0;
}
