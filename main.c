#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	
	char message[100] = "";		// Variável para armazenar a mensagem criptografada (comporta até 99 caracteres + "\0"
	char novo[100] = "";		// Variável que vai receber a mensagem sem os P's
	int i;
	printf("Digite sua mensagem criptografada:\n");
	
	
	if (fgets(message, sizeof(message), stdin) != NULL) {	// Capta dados do teclado do usuário, armazenando na variável 'message'
		int len = strlen(message);							// Variável que armazena o tamanho da mensagem
		
		for(i = 1; i < len;) {
			char temp[2] = {message[i], '\0'};
			strcat(novo, temp);
			
			if (message[i + 1] == ' ') {
				strcat(novo, " ");
				i = i + 1;
			}
			
			i = i + 2;
		}
		printf("%s", novo);
	} else {
		printf("Mensagem indefinida!");
	}
	
	return 0;
}
