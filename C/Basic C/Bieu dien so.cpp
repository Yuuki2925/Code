//Bieu dien so
#include <stdio.h>
#include <math.h>
int check(int n){
	for(int i = 1; i <= n / 111; i++){
		int tmp = n - 111 * i;
		if(tmp % 11 == 0){
			return 1;
		}
	}
	return 0;
}
int main(){
	int n;
	scanf("%d", &n);
	if(check(n)){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
