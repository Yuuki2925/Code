#include <stdio.h>
int ucln(int a, int b){
	while(b != 0){
		int x = a % b;
		a = b;
		b = x;
	}
	return a;
}

int bcnn(int a, int b){
	return a / ucln(a,b) * b;
}
int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	printf("BCNN = %d\n", bcnn(m,n));
	return 0;
}
