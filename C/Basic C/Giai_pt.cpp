// Giai phuong trinh
#include <stdio.h>
#include <math.h>
int main(){
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	for(int  i = 1; i <= n / a; i++){
		int r = n - a * i;
		if(r % b == 0){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
