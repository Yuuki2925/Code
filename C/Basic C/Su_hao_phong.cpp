// Su hao phong
#include <stdio.h>
#include <math.h>
int main(){
	int c1, c2, c3, c4, c5;
	scanf("%d%d%d%d%d", &c1, &c2, &c3, &c4, &c5);
	int b;
	int sum = c1 + c2 + c3 + c4 + c5;
	if( sum % 5 ==0){
		b = sum / 5;
		if(b != 0){
			printf("%d", b);
		}
		else{
			printf("-1");
		}
	}
	else{
		printf("-1");
	}
	return 0;
}
