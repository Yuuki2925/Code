#include <stdio.h>
#include <math.h>
int main(){
	int n;
	float sum = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		if(i % 2 != 0){
			sum += (float)sqrt(i);
		}
	}
	printf("%2.1f", sum);
	return 0;
}
