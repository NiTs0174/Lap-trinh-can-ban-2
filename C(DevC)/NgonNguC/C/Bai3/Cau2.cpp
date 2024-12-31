#include<stdio.h>
//2a liet ke tu 1 den n
void Cau2a(int n){
	for(int i=1; i<=n; i++)
		printf("%d\t",i);
}
//2b so chan
void Cau2b(int n){
	for(int i=2; i<=n; i+=2)
		printf("%d\t",i);
}
//2c Cac so le khong chia het cho 3
void Cau2c(int n){
	for(int i=1; i<=n; i++)	
		if(i%2!=0 && i%3!=0)
			printf("%d\t",i);
}
//2d1 s1 = 1 + 2 + 3 +...+ n
long Cau2d1(int n){	
	long s = 0;
	for(int i=1; i<=n; i++){
			s = s + i;
	}
	return s;
}
//2d2 S2 = - 1 +2 - 3 + 4 - ... + (-1)^n n.
long Cau2d2(int n){	
	long s = 0;
	int t = -1;
	for(int i=1; i<=n; i++){
		s = s + t*i;
		t = t*(-1);
	}
	return s;
}
//2d3 S3 = 1/2 + 2/3 + 3/4 ... + n/(n+1)
float Cau2d3(int n){
	float s = 0;
	for(int i=1; i<=n; i++)	
		s = s + (float)i/(i+1);
	return s;
}
//2d4 S4 = x^n
float Cau2d4(int n){
	float x;
	printf("\nNhap x: ");
	scanf("%f",&x);
	float s = 1;
	for(int i=1; i<=n; i++)	
		s = s * x;
	return s;
}
//2e Tong cac chu so
int Cau2e(int n){
	int s = 0;
	int cs = 0;
	while(n != 0){
		cs = n%10;
		s = s + cs;
		n = n/10;
	}
	return s;
}

int main()
{
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
		if(n <= 0){ 
			printf("Nhap sai, nhap lai");
		}
	} while(n <= 0);
//2a
	printf("cac so trong pham vi tu 1 den %d: ",n);
	Cau2a(n);
//2b
	printf("\nCac so chan trong pham vi tu 1 den %d: ",n);
	Cau2b(n);
//2c
	printf("\nCac so le khong chia het cho 3 trong pham vi tu 1 den %d: ",n);
	Cau2c(n);
//2d1
	long s1 = Cau2d1(n);
	printf("\nS1 = %ld",s1);
//2d2
	long s2 = Cau2d2(n);
	printf("\nS2 = %ld",s2);
//2d3
	float s3 = Cau2d3(n);
	printf("\nS3 = %f",s3);
//2d4
	float s4 = Cau2d4(n);
	printf("S4 (x^n) = %f",s4);
//2e
	int s = Cau2e(n);
	printf("\nTong cac chu so cua n la %d",s);
	return 0;
}
