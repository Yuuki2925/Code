//Ham strtok tach xau ki tu
#include <stdio.h>
#include <string.h>
int main(){
	char c[10000];
	gets(c);
	int cnt = 0;
	char* word = strtok(c, " ");
	while(word != NULL){
		cnt++;
		word = strtok(NULL, " ");
	}
	printf("%d", cnt);
	return 0;
}
