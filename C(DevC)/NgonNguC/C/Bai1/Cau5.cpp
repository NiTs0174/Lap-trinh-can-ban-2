#include<stdio.h>
int main()
{
//Cau 5a
	int a,b;
	printf("Nhap a: ");
	scanf("%d",&a);
	printf("Nhap b: ");
	scanf("%d",&b);
	int max1 = a;
	if(max1 < b){
		max1 = b;
	}
	printf("Gia tri lon nhat la %d\n",max1);
//Cau 5b
	int x,y,z;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("Nhap y: ");
	scanf("%d",&y);
	printf("Nhap z: ");
	scanf("%d",&z);
	int max2 = x; 
	if(max2 < y){
		max2 = y;
	}
	if(max2 < z){
		max2 = z;
	}
	printf("Gia tri lon nhat la %d",max2);
	return 0;
}
