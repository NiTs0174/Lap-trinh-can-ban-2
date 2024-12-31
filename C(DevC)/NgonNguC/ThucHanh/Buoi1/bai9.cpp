#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,dt,x1,x2;
	printf("Nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	printf("Nhap c: ");
	scanf("%f", &c);
	dt = b*b-4*a*c;
	x1 = (-b+sqrt(dt))/(2*a);
	x2 = (-b-sqrt(dt))/(2*a);
	
	if (a!=0){
		if (dt<0){
			printf("Phuong trinh vo nghiem");}
		if (dt==0){
			printf("Phuong trinh co nghien kep: %f", -b/(2*a));}
		else
			printf("Phuong trinh co 2 nghiem phan biet: x=%f,x=%f",x1,x2);
	}else
		printf("Phuong trinh bac 1");
	return 0;
}
