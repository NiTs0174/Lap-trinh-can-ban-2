//4b
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    do{
    	printf("Nhap n = ");
    	scanf("%d", &n);	
	}while(n<=0 || n>=100);
    int i = sqrt(n);
    if(i*i == n){
        printf("%d la so chinh phuong!\n", n);
    }
    else{
        printf("%d khong phai so chinh phuong!\n", n);
	}
	return 0;
}
