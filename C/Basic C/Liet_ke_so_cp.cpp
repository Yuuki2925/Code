// Liet ke so chinh phuong
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	for(int i = 1; i <= sqrt(n); i++){
		printf("%lld ", 1ll * i * i);
	}
	return 0;
}
