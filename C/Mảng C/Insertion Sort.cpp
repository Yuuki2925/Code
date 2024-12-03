// Sap xep chen: Insertion Sort
#include <stdio.h>
void insertionSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int pos = i - 1, value = a[i];
		while(pos >= 0 && value < a[pos]){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = value;
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
	insertionSort(a, n);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
