#include <stdio.h>
#include <math.h>
int ucln(int a, int b){
	if(b == 0){
		return a;
	}
	while(b != 0){
		int x = a % b;
		a = b;
		b = x;
	}
	return a;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("UCLN = %d", ucln(a,b));
	return 0;
}
