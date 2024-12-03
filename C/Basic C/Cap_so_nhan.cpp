// Cap so nhan
#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int q;
	if(b % a == 0){
		q = b / a;
		if(b * q == c && c * q == d){
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
