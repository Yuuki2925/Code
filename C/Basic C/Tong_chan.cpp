// Tong chan
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		if(a % 2 == 0){
			sum += a;
		}
	}
	printf("%lld", sum);
	return 0;
}
