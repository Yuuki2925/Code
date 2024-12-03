//tim UCLN cua moi phan tu trong mang

#include <stdio.h>
#define ll long long
ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	ll uc = 0;
	for(int i = 0; i < n; i++){
		uc = gcd(uc, a[i]);
	}
	printf("%lld", uc);
	return 0;
}
