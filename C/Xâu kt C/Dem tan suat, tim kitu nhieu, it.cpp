#include <stdio.h>
#include <string.h>

//1. Dem tan suat cac ki tu xuat hien trong xau
//2. Tim ki tu xuat hien nhieu nhat, it nhat
int main(){
	char c[1000];
	gets(c);
	int cnt[256] = {0};
	for(int i = 0; i < strlen(c); i++){
		cnt[c[i]]++;
	}
	for(int i = 0; i < 256; i++){
		if(cnt[i]){
			printf("%c : %d\n", i, cnt[i]);
		}
	}
	return 0;
}
