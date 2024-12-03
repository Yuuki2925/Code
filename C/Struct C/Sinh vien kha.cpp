//Sinh vien kha
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
	for(int i = 0; i < n; i++){
		if(strcmp(a[i].dc, "Nam Dinh") == 0 && a[i].gpa >= 2.5){
			in(a[i]);
		}
	}
}
