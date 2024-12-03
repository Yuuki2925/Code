//Mang danh dau 1

// Dieu kien: 0 <= a[i] <= 10^7

#include <stdio.h>
int dem[1000001];
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
		dem[a[i]] = 1;
	}
	int cnt = 0;
	for(int i = 0; i <= 1000000; i++){
		if(dem[i] != 0){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
