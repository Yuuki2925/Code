// Ve hinh 3
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int dem = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", dem);
			++dem;
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 1; i <= n; i++){
		int dem2 = i;
		for(int j = 1; j <= n; j++){
			printf("%d ", dem2);
			++dem2;
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j <= n - i){
				printf("~");
			}
			else{
				printf("%d", i);
			}
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 1; i <= n; i++){
		int dem3 = i;
		int kc = n - 1;
		for (int j = 1; j <= i; j++){
			printf("%d ", dem3);
			dem3 += kc;
		
		}
		printf("\n");
	}
}
