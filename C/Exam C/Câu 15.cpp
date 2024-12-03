#include <stdio.h>
#include <math.h>
int main(){
    int n , x;
    double A , B , C , D;
    A = 10;
    B = 0 ;
    C = 100 ;
    D = 99 ;
    printf("Nhap so x : ");
    scanf("%d", & x);
    printf("Nhap so n : ");
    scanf("%d", &n);
    
    
    //Cau a
   	for (int i = 1; i <= n; i++){
            A = A  + exp(i * x);
	}
    printf("A = %lf", A );
    
    
    //Cau b
   	for (int i = 1; i <= n; i++){
    	B = B + i * (i + 1);
    }
    printf("\nB= %lf",B);
    
    
    //Cau c
    for(int i = 2; i <= n; i++){
        C += (float)x / i;
    }
    printf("\nC = %lf", C );
    
    
    //Cau d
    for (int i = 1; i <= n; i++){
        if(i % 2 == 1){
            D -= 1.0 / (10.0 * i);
        } 
        else{
            D += 1.0 / (10.0 * i);
        }
    }
    printf("\nD = %lf\n", D);
    return 0;
}
