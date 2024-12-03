// Tong binh phuong
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i =1; i <= n; i++){
		sum += 1ll * pow(i,2);
	}
	printf("%lld", sum);
	return 0;
}
