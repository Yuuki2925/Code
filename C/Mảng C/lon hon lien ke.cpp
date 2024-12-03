//Lon hon lien ke
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
	for(int i = 1; i < n - 1; i++){
			if(a[i] > a[i - 1] && a[i] > a[i + 1]){
				printf("%d ", a[i]);
			}
	}
	return 0;
}
