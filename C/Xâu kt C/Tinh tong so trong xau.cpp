//Tinh tong chu so xuat hien trong xau ki tu
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	char c[10001];
	scanf("%s", c);
	int sum = 0;
	for(int i = 0; i < strlen(c); i++){
		if(isdigit(c[i])){
			sum += c[i] - '0';  // chuyen thanh so roi cong vao sum
		}
	}
	printf("%d", sum);
	return 0;
}
