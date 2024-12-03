// Cap so cong
#include <stdio.h>
#include <math.h>
int main(){
	long long n, u1, d;
	scanf("%lld%lld%lld", &n, &u1, &d);
	long long un = u1 + 1ll * (n - 1) * d;
	long long tong = n * (u1 + un) / 2;
	printf("%lld", tong);
	return 0;
}
