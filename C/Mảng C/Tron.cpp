//Tron: Merge
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int m;
	printf("Nhap m = ");
	scanf("%d", &m);
	int a[n], b[m];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		printf("b[%d] = ", i);
		scanf("%d", &b[i]);
	}
	int i = 0, j = 0;
	while(i < n && j < m){
		if(a[i] <= b[j]){
			printf("%d ", a[i]);
			++i;
		}
		else{
			printf("%d ", b[j]);
			++j;
		}
	}
	while(i < n){
		printf("%d ", a[i]);
		++i;
	}
	while(j < m){
		printf("%d ", b[j]);
		++j;
	}
	return 0;
}

