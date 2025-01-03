#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int sphenic(long long n){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            int mu = 0;
            while(n % i == 0){
                mu++;
                n /= i;
            }
            if(mu >=2){
                return 0;
            }
            cnt++;
        }
    }
    if(n > 1){
        cnt++;
    }
    if(cnt == 3){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    long long n;
    scanf("%lld", &n);
    if(sphenic(n)){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}
