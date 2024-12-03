//Tong tu nhien lien tiep
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	int sum = 0;
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i = 1; i <= n;i++){
		sum += i;
	}
		printf("Tong = %d", sum);
}
