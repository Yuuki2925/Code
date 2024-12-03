//Liet ke va dem so fibonacci
#include <stdio.h>
#include <math.h>
#define ll long long
ll F[100];  // luu cac so fibonacci tu 0 -> 92
// F[i] : la so fibonacci thu i


void ktao(){
	F[0] = 0;
	F[1] = 1;
	for(int i = 2; i <= 92; i++){
		F[i] = F[i - 1] + F[i - 2];
	}
}


int checkfb(int n){
	for(int i = 0; i <= 92; i++){
		if(F[i] == n){
			return 1;
		}
	}
	return 0;
}


int main(){
	ktao();
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int ktra = 0;
	for(int i = 0; i < n; i++){
		if(checkfb(a[i])){
			printf("%d ", a[i]);
			ktra = 1;
		}
	}
	if(ktra == 0){
		printf("NONE");
	}
	return 0;
}
