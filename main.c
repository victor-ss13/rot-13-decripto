#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char* removeP() {
	setlocale(LC_ALL, "Portuguese");
	
	
	char message[100] = "";									// Vari�vel para armazenar a mensagem criptografada (comporta at� 99 caracteres + "\0"
	char novo[100] = "";									// Vari�vel que vai receber a mensagem sem os P's
	int i;													// Vari�vel de controle
	printf("Digite sua mensagem criptografada:\n");
	
	
	if (fgets(message, sizeof(message), stdin) != NULL) {	// Capta dados do teclado do usu�rio, armazenando na vari�vel 'message'
		int len = strlen(message);							// Vari�vel que armazena o tamanho da mensagem
		
		for(i = 1; i < len; i = i + 2) {
			char temp[2] = {message[i], '\0'};				// Transforma o caractere de message[i] em string ao juntar com '\0'
			strcat(novo, temp);								// Concatena duas strings: novo e temp. Ou seja, novo = novo + temp
			
			if (message[i + 1] == ' ') {
				strcat(novo, " ");							// Concatena um espa�o � string, caso o pr�ximo caractere for um espa�o
				i++;										// Incrementa i para que a itera��o se mantenha sempre no �ndice de caracteres desejados
			}
			
		}
		//printf("%s", novo);
		return novo;
	} else {
		printf("Mensagem indefinida!");
		return NULL;
	}
	/* Fun��o para remover os P's definida, para utiliz�-la em outro local, 
	basta chamar por 'removeP()' e assim teremos a string armazenada em 'novo'*/
	
}

char* decifraMsg() {
	char* msg = removeP();
	
}

int main(int argc, char *argv[]) {
	
	return 0;
}
