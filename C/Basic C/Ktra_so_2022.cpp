// Ktra so 2022
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int check = 0;
	for (int i =1; i <= n; i++){
		int tmp;
		scanf("%d", &tmp);
		if(tmp == 2022){
			check = 1;           // Da co so 2022
		}
	}
	if(check == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
