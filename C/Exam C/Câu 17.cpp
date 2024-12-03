#include <stdio.h>
#include <math.h>
int main(){
    float a , b ,c ;
    printf("Nhap 3 canh a, b, c : ");
    scanf("%f%f%f",&a,&b,&c);
    if(a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0){
        if (a == b && b == c)
        {
            printf("La tam giac deu");
        }
        else if(a == b || a == c || b == c)
        {
            printf("La tam giac can");
        }
        else if( a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            printf("La tam giac vuong ");
        }   
        else
        {
            printf("La tam giac thuong");
        } 
        float P , S , C ;
        C = a + b + c ;
        P = C / 2 ;
        S = sqrt(P*(P-a)*(P-b)*(P-c));
        printf("\nChu vi = %2.1f\n",C);
        printf("Dien tich = %2.1f\n",S);   
    }
    else
    {   
        printf("Khong phai la tam giac");
    }

    
    return 0;
}
