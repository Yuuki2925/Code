//Duoi hoc sinh vien co gpa <= 1.0
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct sv{
	char ten[100];
	char ns[100];
	char dc[100];
	float gpa;
};
typedef struct sv sv;

//In thong tin
void in(sv a){
	printf("%s %s %s %.2f\n", a.ten, a.ns, a.dc, a.gpa);
}

int xoaSinhVien(sv *a, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].gpa >= 1.0) {
            a[j++] = a[i];       //Neu co sinh vien co gpa >= 1.0 se gan vao a[j] sau do tang j len
        }
    }
    return j; //Tra ve j ( day la nhung sinh vien GPA >= 1.0)
}

int main(){
	int n;
	printf("So luong sinh vien: ");
	scanf("%d", &n);
	sv a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Sinh vien thu %d\n", i + 1);
		printf("Nhap ten sinh vien: ");
		gets(a[i].ten);
		printf("Nhap ngay sinh sinh vien: ");
		gets(a[i].ns);
		printf("Nhap dia chi sinh vien: ");
		gets(a[i].dc);
		printf("Nhap diem GPA: ");
		scanf("%f", &a[i].gpa);
	}
	n = xoaSinhVien(a, n);
	for(int i = 0; i < n; i++){
		in(a[i]);
	}
//Co the thay the ham xoa sinh vien bang cach khac: 
//	if(a[i].gpa >= 1.0){
//			in(a[i]);
//		}
}
