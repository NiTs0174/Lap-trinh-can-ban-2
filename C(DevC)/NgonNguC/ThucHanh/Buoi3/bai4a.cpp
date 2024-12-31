//4a
#include <stdio.h>
#include <math.h>
int main(){
    int n,i,d;
    do{
    	printf("Nhap n = ");
    	scanf("%d", &n);
	} while(n<=0 || n>=100);
	for(d=0, i=1; i<=n; i++){
		if(n % i == 0){
			d = d + 1;
		}
	}
	if(d == 2){
		printf("%d la so nguyen to",n);
	}
	else{
		printf("%d khong phai so nguyen to",n);
	}
	return 0;
}
