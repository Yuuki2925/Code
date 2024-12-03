//Cau truc sinh vien
#include <stdio.h>
#include <math.h>
#include <string.h>
struct sv{
	char ten[100];
	char ns[100];
	char dc[100];
	int toan, ly, hoa;
};
typedef struct sv sv;

//In thong tin
void in(sv a){
	printf("%s %s %s %d\n", a.ten, a.ns, a.dc, a.toan + a.ly + a.hoa);
}
int main(){
	int n;
	printf("So luong sinh vien: ");
	scanf("%d", &n);
	sv a[n];
	int max = 0;
	for(int i = 0; i < n; i++){
		getchar();
		printf("Sinh vien thu %d\n", i + 1);
		printf("Nhap ten sinh vien: ");
		gets(a[i].ten);
		printf("Nhap ngay sinh sinh vien: ");
		gets(a[i].ns);
		printf("Nhap dia chi sinh vien: ");
		gets(a[i].dc);
		printf("Nhap diem toan, ly, hoa: ");
		scanf("%d%d%d", &a[i].toan, &a[i].ly, &a[i].hoa);
		max = fmax(max, a[i].toan + a[i].ly + a[i].hoa);
	}
	printf("\nDanh sach thu khoa: \n");
	for(int i = 0; i < n; i++){
		if(a[i].toan + a[i].ly + a[i].hoa == max){
			in(a[i]);
			printf("\n");
		}
	}
	printf("Ket qua xet tuyen: \n");
	for(int i = 0; i < n; i++){
		in(a[i]);
		if(a[i].toan + a[i].ly + a[i].hoa >= 24){
			printf("Do\n");
		}
		else{
			printf("Truot\n");
		}
	}
}

