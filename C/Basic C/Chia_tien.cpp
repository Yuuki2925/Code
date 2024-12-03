// Chia tien
#include <stdio.h>
#include <math.h>
int main(){
	long long a, b, c, n;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
	long long sum = a + b + c + n;
	long long res;
	if(sum % 3 == 0){
		res = sum / 3;
		if(res >= a && res >= b && res >= c){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}
