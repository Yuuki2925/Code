#include <stdio.h>
#include <string.h>
int main(){
	char c[10000];
	scanf("%s", c);
	int sum = 0;
	for(int i = 0; i < strlen(c); i++){
		sum += c[i] - '0';
	}
	printf("%d", sum);
	return 0;
}
