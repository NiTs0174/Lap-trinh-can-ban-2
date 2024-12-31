#include<stdio.h>
#define MAX 100
//1 Nhap ma tran
void NhapMT(int a[][MAX], int d, int c){
	for(int i=0; i<d; i++)
		for(int j=0; j<c; j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
}
//2 Xuat ma tran
void XuatMT(int a[][MAX], int d, int c){
	for(int i=0; i<d; i++){
		for(int j=0; j<c; j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
//3 Tong cac pt chan cua mt
long Tong(int a[][MAX], int d, int c){
	long s = 0;
	for(int i=0; i<d; i++)
		for(int j=0; j<c; j++)
			if(a[i][j] % 2 == 0)
				s += a[i][j];
	return s;
}
//4 Xuat cac pt tren dong k
void XuatDongk(int a[][MAX], int d, int c, int k){
	for(int j=0; j<c; j++)
		printf("%d\t",a[k][j]);
}
//Doi Ky Tu
void Proper(char s[]){
	if(s[0]>='a' && s[0]<='z')
		s[0] -= 32;
	int i = 1;
	while(s[i] != '\0'){
		if(s[i-1]==' ' && s[i]>='a' && s[i]<='z')
			s[i] -= 32;
		if(s[i-1]!=' ' && s[i]>='A' && s[i]<='Z')
			s[i] += 32;
		i++;
	}
}

int main()
{
	int d,c;
	int a[MAX][MAX];
	printf("Nhap so dong: ");
	scanf("%d",&d);
	printf("Nhap so cot: ");
	scanf("%d",&c);
	NhapMT(a,d,c);
	
	XuatMT(a,d,c);

	long s = Tong(a,d,c);
	printf("\nTong cac phan tu chan cua ma tran: %ld",s);

	int k;
	printf("\nNhap dong muon tim: ");
	scanf("%d",&k);
	printf("Dong thu %d la: ",k);
	XuatDongk(a,d,c,k);

	char b[30];
	fflush(stdin);
	printf("\nNhap chuoi ky tu: ");
	gets(b);
	Proper(b);
	printf("\nChuoi sau khi doi: ");
	puts(b);
	return 0;
}
