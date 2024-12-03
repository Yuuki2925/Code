//sap xep dem phan phoi: Counting Sort
#include <stdio.h>
#include <math.h>
int cnt[10000001];
void countingSort(int a[], int n){
	int k = -1e9;
	for(int i = 0; i < n; i++){
		k = fmax(k,a[i]);
	}
	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < cnt[i]; j++){
			printf("%d ", i);
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
	countingSort(a,n);
	return 0;
}
