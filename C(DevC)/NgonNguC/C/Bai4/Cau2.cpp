#include<stdio.h>
void XuatMenu(){
	printf("\n1. Giai phuong trinh bac 1");
	printf("\n2. Kiem tra so hoan thien");
	printf("\n3. Liet ke so hoan thien trong pham vi tu 1 den n");
	printf("\n4. Tim uoc chung lon nhat cua hai so nguyen");
	printf("\n0. Thoat");
}
//2a Giai phuong trinh bac 1
void ptb1(float a, float b){
	if(a == 0){
		if(b == 0){
			printf("Phuong trinh vo so nghiem");
		}
		else{
			printf("Phuong trinh vo nghiem");
		}
	}
	else{
		printf("Phuong trinh co nghiem x = %.2f",-b/a);
	}
}
//2b Kiem tra so hoan thien
int KTHT(int n){
	long s = 0;
	for(int i=1; i<n; i++)
		if(n % i == 0)
			s = s + i;
	if(s == n)
		return true;
	return false;
}
//2c Liet ke so hoan thien
void LietKeHT(int n){
	for(int i=1; i<n; i++)
		if(KTHT(i) == true)
			printf("%d\t",i);
}
//2d Tim uoc chung lon nhat
int UCLN(int a,int b){
	while(a*b != 0)
		if(a > b)
			a = a % b;
		else
			b = b % a;
	return a + b;
}

int main(){
	int chon;
	do{
		XuatMenu();
		printf("\nHay chon cong viec: ");
		scanf("%d",&chon);
		switch(chon){
			case 1:
				float a,b;
				printf("Nhap a, b: ");	scanf("%f%f",&a,&b);
				ptb1(a,b);
			break;
			case 2:
				int n;
				printf("Nhap n: ");	scanf("%d",&n);
				if(KTHT(n) == true){
					printf("%d la so hoan thien",n);
				}	
				else{ 
					printf("%d khong phai so hoan thien",n);
				}
			break;
			case 3:	
				int n2;
				printf("Nhap n: ");	scanf("%d",&n2);
				LietKeHT(n2);
			break;
			case 4:
				int a2,b2;
				printf("Nhap a, b: ");	scanf("%d%d",&a2,&b2);
				printf("Uoc chung lon nhat cua 2 so la %d",UCLN(a2,b2));
			break;
			default: chon = 0;	printf("Ban da chon thoat");
		}
	} while(chon != 0);
	return 0;
}
