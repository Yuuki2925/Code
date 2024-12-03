//Mang cong don
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
	int f[n];
	for(int i = 0; i < n; i++){
		if(i == 0){
			f[0] = a[0];
		}
		else{
			f[i] = f[i - 1] + a[i];
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", f[i]);
	}
	return 0;
}
