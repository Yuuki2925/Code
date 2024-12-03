#include <stdio.h>
#include <math.h>
void checkfibo(int n){
	if(n == 1){
		printf("1");
	}
	else if(n == 2){
		printf("1 1 ");
	}
	else{
		printf("1 1 ");
		int f1 = 1, f2 = 1;
		for(int i = 3; i <= n; i++){
			long long fn = f1 + f2;
			printf("%lld ", fn);
			f1 = f2;
			f2 = fn;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	checkfibo(n);
	return 0;
}
