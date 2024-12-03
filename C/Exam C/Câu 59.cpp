//Cau 59
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct nv{
	char mnv[100];
	char ten[100];
	int pb;
};

typedef struct nv nv;

//In thong tin nhan vien
void in(nv a){
	printf("%s  %s  %d\n", a.mnv, a.ten, a.pb);
}
int main(){
	int n;
	printf("Nhap danh sach nhan vien: ");
	scanf("%d", &n);
	nv a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Nhan vien thu %d\n", i + 1);
		printf("Nhap ma nhan vien: ");
		gets(a[i].mnv);
		printf("Nhap ho ten: ");
		gets(a[i].ten);
		printf("Nhap so phong ban: ");
		scanf("%d", &a[i].pb);
	}
	printf("\nDanh sach cac nhan vien la:\n");
	for(int i = 0; i < n; i++){
		in(a[i]);
	}
	return 0;
}
