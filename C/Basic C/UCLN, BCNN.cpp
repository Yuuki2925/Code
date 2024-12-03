// UCLN
#include <stdio.h>
#include <math.h>
int ucln(int a, int b){
	while(b != 0){
		int x = a % b;
		a = b;
		b = x;
	}
	return a;
}

// BCNN
int bcnn(int a, int b){
	return a / ucln(a,b) * b;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("UCLN = %d\n", ucln(a,b));
	printf("BCNN = %d\n", bcnn(a,b));
	return 0;
}
