// Digital root
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	while(n >= 10){
		// di tinh tong chu so cua n sau do gan lai cho n
		int sum = 0;
		while(n){
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}
	printf("%lld", n);
	return 0;
}
