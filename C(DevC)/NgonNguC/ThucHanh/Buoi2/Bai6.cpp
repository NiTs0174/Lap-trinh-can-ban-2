#include<stdio.h>
int main(){
	float a,b,c;
	printf("Nhap canh a: ");
	scanf("%f",&a);
	printf("Nhap canh b: ");
	scanf("%f",&b);
	printf("Nhap canh c: ");
	scanf("%f",&c);
	
	if(a+b>c && a+c>b && b+c>a){
		if( a==b && b==c ){
			printf("Ba canh tao thanh tam giac deu");
		}
		else if(a==b || a==c || b==c){
			printf("Ba canh tao thanh tam giac can");
		}
		else if( a*a==b*b+c*c || b*b==a*a+c*c || c*c== a*a+b*b){
      		printf("Ba canh tao thanh tam giac vuong");
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
