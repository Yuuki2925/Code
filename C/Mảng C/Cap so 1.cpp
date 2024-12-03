//Cap so 1
#include <stdio.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n ; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int k;
	printf("Nhap k = ");
	scanf("%d", &k);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] + a[j] == k){
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
