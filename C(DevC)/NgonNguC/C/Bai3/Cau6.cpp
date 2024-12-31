#include<stdio.h>
//6a
void NhapN(int &n){
	do{
		printf("n = ");
		scanf("%d",&n);
		if(n <= 0)
			printf("Nhap sai, nhap lai");
	} while(n <= 0);
}
//6b
int KTNT(int n){
	if(n < 2)
		return 0;
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
void LietKeNT(int n){
	printf("Cac so nguyen to trong pham vi tu 1 den %d: ",n);
	for(int i=1; i<=n; i++)
		if(KTNT(i) == 1) 
			printf("%d\t",i);
}
//6c
int DemSNT(int n){
	int  d = 0;
	for(int i=1; i<=n; i++)
		if(KTNT(i) == 1)
			d = d + 1;
	return d;
}
//2d
long TongSNT(int n){
	long s = 0;
	for(int i=1; i<=n; i++)
		if(KTNT(i) == 1)
    		s = s + i;
 	return s;
}

int main(){
	int n;
//6a
	NhapN(n);
//6b
	LietKeNT(n);
//6c
	int dem = DemSNT(n);
	printf("\nSo luong cac nguyen to la %d",dem);
//6d
	long tong = TongSNT(n);
	printf("\nTong cac so nguyen to la %ld" ,tong);	
	return 0;
}
