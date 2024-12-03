//Mang danh dau 5
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
	}
	int tansuat = 0, res;
	for(int i = 0; i <= n; i++){
		if(dem[a[i]] > tansuat){
			tansuat = dem[a[i]];
			res = a[i];
		}
	}
	printf("%d %d\n", res, tansuat);
	return 0;
}
