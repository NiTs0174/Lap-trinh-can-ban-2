#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;
	printf("Nhap a: ");
	scanf("%f",&a);
	printf("Nhap b: ");
	scanf("%f",&b);
	printf("Nhap c: ");
	scanf("%f",&c);
	float d = b*b-4*a*c;
	float x1 = (-b+sqrt(d))/(2*a);
	float x2 = (-b-sqrt(d))/(2*a);
	if(a != 0){
		if(d < 0){
			printf("Phuong trinh vo nghiem");
		}
		else if(d == 0){
			printf("Phuong trinh co nghiem kep x= %.1f",-b/(2*a));
		}
		else{
			printf("Phuong trinh co hai nghiem phan biet x1 = %.1f\t x2 = %.1f",x1,x2);
		}
	}
	else{
		printf("Phuong trinh tro thanh phuong trinh bac 1");
		printf("\nNghiem cua phuong trinh la x = %f",-c/b);
	}
	return 0;
}
