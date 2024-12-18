//sap xep nhanh: quick Sort
#include <stdio.h>
#include <math.h>
int partition(int a[], int l, int r){
	int i = l - 1;
	int pivot = a[r];
	for(int j = l; j < r; j++){
		if(a[j] <= pivot){
			++i;
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	++i;
	int tmp = a[i];
	a[i] = a[r];
	a[r] = tmp;
	return i;
}

void quickSort(int a[], int l, int r){
	if(l < r){
		int pos = partition(a, l, r);
		quickSort(a, l, pos - 1);
		quickSort(a, pos + 1, r);
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
	quickSort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
