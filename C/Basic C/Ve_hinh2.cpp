// Ve hinh 2
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = n; i >= 1; i--){
		for(int j = 1; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j <= n - i){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
	for (int i = n; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			if(j <= n - i){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(i == 1 || i == n || j == 1 || j == i){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
