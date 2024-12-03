// Chuyen so tu he thap phan sang he nhi phan
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	int a[100], dem = 0;
	while(n != 0){
		a[dem] = n % 2;
		n /= 2;
		dem++;
	}
	for(int i = dem - 1; i >= 0; i--){
		printf("%d", a[i]);
	}
}
