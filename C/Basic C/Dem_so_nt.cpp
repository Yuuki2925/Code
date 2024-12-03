// Dem chu so nguyen to cua so nguyen
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	int cnt = 0;
	while(n != 0){
		int a = n % 10; // chu so hang don vi
		if(a == 2 || a == 3 || a == 5 || a == 7){
			cnt++;
			n /= 10;
		}
	}
	printf("%d", cnt);
	return 0;
}
