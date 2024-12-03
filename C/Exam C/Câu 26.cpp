#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	long long sum = 0;
	for(int i = 1; i < n; i++){
		if(i % 2 == 0){
			sum += i;
		}
	}
	printf("Tong chan = %lld", sum);
	return 0;
}
