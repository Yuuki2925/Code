#include <stdio.h>
#include <math.h>
int chan(int n){
	int tichchan = 1;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0){
			tichchan *= i;
		}
	}
	printf("Tich chan = %d", tichchan);
}
int le(int n){
	int tichle = 1;
	for(int i = 1; i <= n; i++){
		if(i % 2 != 0){
			tichle *= i;
		}
	}
	printf("Tich le = %d", tichle);
}
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	if(n % 2 == 0){
		chan(n);
	}
	else{
		le(n);
	}
	return 0;
}
