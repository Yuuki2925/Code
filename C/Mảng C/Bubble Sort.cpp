//Sap xep noi bot: Bubble Sort
#include <stdio.h>
#include <math.h>
void bubbleSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				int tg = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tg; 
			}
		}
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
	bubbleSort(a,n);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
