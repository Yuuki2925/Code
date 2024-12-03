//Dem so tu in hoa
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int check(char c[]){
	for(int i = 0; i < strlen(c); i++){
		if(islower(c[i])){
			return 0;
		}
	}
	return 1;
}
int main(){
	char c[1000];
	gets(c);
	int cnt = 0;
	char *token = strtok(c, " ");
	while(token != NULL){
		if(check(token)){
			++cnt;
		}
		token = strtok(NULL, " ");
	}
	printf("%d", cnt);
	return 0;
}
