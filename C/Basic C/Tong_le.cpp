// Tong le
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	long long res = 0;
	for(int i = 1; i <= n; i++){
		res += 1ll * 2 * i - 1;
	}
	printf("%lld", res);
	return 0;
}
