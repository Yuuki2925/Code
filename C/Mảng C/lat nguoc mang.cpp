//lat nguoc mang
#include <stdio.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int l = 0, r = n - 1;
	while(l <= r){
		int tg = 0;
		tg = a[r];
		a[r] = a[l];
		a[l] = tg;
		++l;
		--r;
	}
	for(int i = 0; i < n ; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
