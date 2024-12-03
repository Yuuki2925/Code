// So gan thuan nghich
#include <stdio.h>
#include <math.h>
int tn(int n){
	int lat = 0, tmp = n;
	while(n){
		lat = lat * 10 + n % 10;
		n /= 10;
	}
	return lat == tmp;
}
int check(long long n){
	int r = n % 10;
	long long rev = 0;
	n /= 10; // lam mat 1 chu so hang don vi
	while(n >= 10){
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	if(n == r * 2 || r == n * 2 && tn(rev)){
		return 1;
	}
	else{
		return 0;
	}
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
