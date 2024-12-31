#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Nhap a: ");
	scanf("%d",&a);
	printf("Nhap b: ");
	scanf("%d",&b);
	fflush(stdin);
	printf("Chon phep toan: ");
	scanf("%c",&c);
	
	switch(c){
		case '+': printf("Tong = %d",a+b); break;
		case '-': printf("Hieu = %d",a-b); break;
		case '*': printf("Tich = %d",a*b); break;
		case '/': printf("Thuong = %f",(float)a/b); break;
		default: printf("\nKhong co phep toan nay");
	}
	return 0;
}
