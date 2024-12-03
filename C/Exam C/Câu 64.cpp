//Cau 64
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct sach{
	char ms[100];
	char tg[100];
	char ts[100];
	int nxb;
}; 
typedef struct sach sach;

//In thong tin
void in(sach a){
	printf("%s %s %s %d\n", a.ms, a.tg, a.ts, a.nxb);
}

int main(){
	int n;
	printf("Nhap so luong sach: ");
	scanf("%d", &n);
	sach a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Nhap ma sach: ");
		gets(a[i].ms);
		printf("Nhap ten sach: ");
		gets(a[i].ts);
		printf("Nhap ten tac gia: ");
		gets(a[i].tg);
		printf("Nhap nam xuat ban: ");
		scanf("%d", &a[i].nxb);
	}
	for(int i = 0; i < n; i++){
		if(strcmp(a[i].ts, "tin hoc dai cuong") == 0){
			in(a[i]);
		}
	}
	return 0;
}
