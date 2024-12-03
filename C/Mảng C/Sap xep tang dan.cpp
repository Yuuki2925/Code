//Sap xep mang tang dan
#include <stdio.h>
int sx(int a[], int n){
	int tg;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	printf("Thu tu tang dan la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	sx(a,n);
	return 0;
}
