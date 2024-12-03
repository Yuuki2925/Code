//Tinh tong va tich cac phan tu
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	long long sum = 0, tich = 1;
	int mod = 1000000007;
	for(int i = 0; i < n; i++){
		sum  += a[i];
		sum %= mod;
		tich *= a[i];
		tich %= mod;
	}
	printf("Tong = %lld\nTich = %lld", sum % mod, tich % mod);
	return 0;
}
