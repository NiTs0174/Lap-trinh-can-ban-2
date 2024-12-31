#include<stdio.h>
//1a
void NhapN(int &n){
	do{
		printf("n = ");
		scanf("%d",&n);
		if(n<=0 || n>=100)
			printf("Nhap sai, nhap lai");
	} while(n<=0 || n>=100);
}
//1b
int KTNT(int n){
	if(n < 2)
		return 0;
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
//1c
void LietKeNT(int n){
	printf("\nCac so nguyen to trong pham vi tu 1 den %d: ",n);
	for(int i=1; i<n; i++)
		if(KTNT(i) == 1)
			printf("%d\t",i);
}
//1d
int DemNT(int n){
	int  d = 0;
	for(int i=1; i<n; i++)
		if(KTNT(i) == 1)
			d = d + 1;
	return d;
}
//1e
long TongNT(int n){	
	long s = 0;	
	for(int i=1; i<n; i++)
		if(KTNT(i) == 1)
    		s = s + i;
 	return s;
}
//1f
float TbcNT(int n){
	int s = 0;
	int d = 0;
	for(int i=1; i<n; i++)
		if(KTNT(i) == 1){
			s = s + i;
			d = d + 1;
		}
	return (float)s/d;
}

int main(){
	int n;
//1a
	NhapN(n);
//1b
	int kt = KTNT(n);
	if(kt == 1){
		printf("%d la so nguyen to",n);
	}
	else{
		printf("%d khong phai so nguyen to",n);	
	}
////1c
//	LietKeNT(n);
////1d
//	int dem = DemNT(n);
//	printf("\nSo luong cac nguyen to la %d",dem);
////1e
//	long tong = TongNT(n);
//	printf("\nTong cac so nguyen to la %ld" ,tong);
////1f
//	float tbc = TbcNT(n);
//	printf("\nTrung binh cong cac so nguyen to la %f",tbc);
	return 0;
}
