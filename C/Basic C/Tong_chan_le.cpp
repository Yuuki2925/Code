// Tong chan le
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	long long res = 0;
	for (int i = 1; i <= n; i++){
		if(i % 2 == 0){
			res += i;
		}
		else{
			res -= i;
		}
	}
	printf("%lld", res);
	return 0;
}
