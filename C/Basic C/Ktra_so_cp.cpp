// Ktra so chinh phuong
#include <stdio.h>
#include <math.h>
long long check(long long n){
	long long can = sqrt(n);
	if(can * can == n){
		return 1;
	}
	else return 0;
}
int main(){
	long long n;
	scanf("%lld", &n);
	if(check(n)){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
