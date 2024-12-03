//Xoa
#include <stdio.h>
int main(){
	int n, x;
	printf("Nhap n, x = ");
	scanf("%d%d", &n, &x);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int k = -1; 
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			k = i;
			break;
		}
	}
	if(k == -1){
		printf("NOT FOUND");
	}
	else{
		for(int i = k; i < n - 1; i++){
			a[i] = a[i + 1];
		}
		for(int i = 0; i < n - 1; i++){
			printf("%d ", a[i]);
		}
	}
	return 0;
}
