//In phan tu
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0 && a[i] % 2 == 0){
			printf("%d ", a[i]);
			cnt = 1;
		}
	}
	if(cnt == 0){
			printf("NONE");
	}
	return 0;
}
