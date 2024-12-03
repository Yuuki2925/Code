// Tinh tong chu so cua N
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	while(n != 0){
		
		n /= 10;
		sum += n % 10;
	}
	printf("%d", sum);
	return 0;
}

