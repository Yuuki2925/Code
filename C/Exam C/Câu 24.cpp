#include <stdio.h>
#include <math.h>
int nt(int n){
	if(n < 2){
		return 0;
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	if(nt(n)){
		printf("La so nguyen to");
	}
	else{
		printf("Khong phai la so nguyen to");
	}
	return 0;
}
