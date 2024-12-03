//Cap so 2
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n ; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int min = 1e9;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(min > abs(a[i] - a[j])){
				min = abs(a[i] - a[j]);
			}
		}
	}
	printf("%d", min);
	return 0;
}
