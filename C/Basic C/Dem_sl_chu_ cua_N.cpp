// Dem so luong chu cua N
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	int dem = 0;
	if(n == 0){
		printf("1\n");
		return 0;
	}
	while(n != 0){
		dem++;
		n /= 10;
	}
	printf("%d", dem);
	return 0;
}
