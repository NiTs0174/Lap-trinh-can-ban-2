#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	printf("Nhap a: ");
	scanf("%d",&a);
	printf("Nhap b: ");
	scanf("%d",&b);
	printf("Chon thuc hien phep toan(+,-,*,/): ");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch){
		case '+': printf("Tong = %d",a+b); break;
		case '-': printf("Hieu = %d",a-b); break;
		case '*': printf("Tich = %d",a*b); break;
		case '/': printf("Thuong = %f",(float)a/b); break;
		default: printf("\nKhong co phep toan nay");
	}
	return 0;
}
