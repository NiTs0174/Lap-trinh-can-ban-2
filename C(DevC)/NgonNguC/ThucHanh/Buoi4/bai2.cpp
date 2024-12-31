#include<stdio.h>
//2a
void Nhap(int &n){
	do{
		printf("n = ");
		scanf("%d",&n);
	} while(n<=0 || n>=100);
}
//2b
int KTNT(int n){
	int d = 0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			d = d + 1;
	if(d==2)
		return 1;
	return 0;
}
//2c
void LietKeNT(int n){
	printf("\nCac so nguyen to tu 1 den %d: ",n);
	for(int i=1; i<=n; i++)
		if(KTNT(i)==1)
			printf("%d\t",i);
}
//2d
int DemNT(int n){
	int i, d = 0;
	for(i=2; i<=n; i++)
		if(KTNT(i)==1)
			d = d + 1;
				return d;
}
//2e
int TongNT(int n){
	int i, s=0;
		for(i=1; i<=n; i++)
			if(KTNT(i)==1)
    			s=s+i; 
 	return s;
}
//2f
float tbcNT(int n){
 	return (float)TongNT(n)/DemNT(n);
}

int main(){
	int n;
//2a
	Nhap(n);
//2b
	int kt = KTNT(n);
	if(kt==1){
		printf("%d La so nguyen to",n);
	}
	else{
		printf("%d Khong phai so nguyen to",n);
	}
//2c
	LietKeNT(n);
//2d
	DemNT(n);
	printf("\nSo luong cac cac nguyen to la %d",DemNT(n));
//2e
	TongNT(n); 
	printf("\nTong la %d" , TongNT(n));
//2f
	printf("\nTrung binh cong la %f", (float)TongNT(n)/DemNT(n));
	return 0;
}
