//Mang chan le
#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int chan = 0, le = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			++chan;
		}
		else{
			++le;
		}
	}
	if(chan > le){
		printf("Mang chan");
	}
	else if(chan < le){
		printf("Mang le");
	}
	else{
		printf("Mang chan le");
	}
	return 0;
}
