//Sap xep chon : Seletion sort
#include <stdio.h>
#include <math.h>
void selectionSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int min_pos = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[min_pos]){
				min_pos = j;
			}
		}
		int tg = a[i];
		a[i] = a[min_pos];
		a[min_pos] = tg;
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
	selectionSort(a,n);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
