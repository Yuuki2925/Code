//Ngay sinh
#include <stdio.h>
#include <string.h>
int main(){
	char c[1000];
	scanf("%s", c);
	char *token = strtok(c, "/");
	while(token != NULL){
		if(strlen(token) == 1){
			printf("0%s", token);
		}
		else{
			printf("%s", token);
		}
		if(strlen(token) != 4){
			printf("/");
		}
		token = strtok(NULL, "/");
	}
	return 0;
}
