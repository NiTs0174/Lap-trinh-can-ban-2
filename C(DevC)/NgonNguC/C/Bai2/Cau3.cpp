#include<stdio.h>
int main(){
	unsigned int a,b,c;
	printf("Nhap canh a: ");
	scanf("%u",&a);
	printf("Nhap canh b: ");
	scanf("%u",&b);
	printf("Nhap canh c: ");
	scanf("%u",&c);
	if(a+b>c && a+c>b && b+c>a){	
		if(a*a==b*b+c*c || b*b==a*a+c*c || c*c== a*a+b*b){
      		printf("Ba canh tao thanh tam giac vuong");
		}
		else if(a==b && b==c){
			printf("Ba canh tao thanh tam giac deu");
		}
		else if(a==b || a==c || b==c){
			printf("Ba canh tao thanh tam giac can");
		}
		else{
			printf("Ba canh tao thanh tam giac giac thuong");
		}
	}
	else{
		printf("Ba canh khong tao thanh tam giac");
	}
	return 0;
}
