//So nho nhat
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int min = 1e9;
	for(int i = 0; i < n; i++){
		if(min > a[i]){
			min = a[i];
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == min){
			++cnt;
		}
	}
	printf("Co %d so nho nhat la %d", cnt, min);
	return 0;
}
