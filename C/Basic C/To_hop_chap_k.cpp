// To hop chap k cua n
#include <stdio.h>
#include <math.h>
long long tohop(int n, int k){
	long long res = 1;
	k = fmin(k, n - k);
	for(int i = 1; i <= k; i++){
		res *= (n - i + 1);
		res /= i;
	}
	return res;
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%lld", tohop(n, m));
	return 0;
}
