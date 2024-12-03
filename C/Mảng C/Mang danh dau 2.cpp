//Mang danh dau 2
#include <stdio.h>
int dem[1000001];
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	int max = -1e9;
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
		dem[a[i]]++;
		if(a[i] > max){
			max = a[i];
		}
	}
	int cnt = 0;
	for(int i = 0; i <= max; i++){
		if(dem[i] != 0){
			printf("%d %d\n", i , dem[i]);
		}
	}
	return 0;
}
