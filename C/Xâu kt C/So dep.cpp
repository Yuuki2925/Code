//So dep
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int check(char c[]){
	for(int i = 0; i < strlen(c) - 2; i++){
		if(abs(c[i] - c[i + 1]) != 1){
			return 0;
		}
	}
	return 1;
}
int main(){
	char c[10000];
	scanf("%s", c);
	if(check(c)){
		printf("Day la so dep");
	}
	else{
		printf("So khong dep");
	}
}
