#include <stdio.h>
#include <string.h>
int main(){
	char c[10000];
	gets(c);
	char* word = strtok(c, " /.");
	while(word != NULL){
		printf("%s\n", word);
		word = strtok(NULL, " /.");
	}
	return 0;
}
