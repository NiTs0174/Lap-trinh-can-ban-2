//1a
#include<stdio.h>
void Nhap(int &n){
	do{
		printf("Nhap n= ");
		scanf("%d",&n);
	} while(n<=0);
}
//1b
void LietKe(int n){
	printf("Liet ke cac so chan: ");
	for(int i=1; i<=n; i++)
		if(i%2==0)
			printf("%d\t",i);
}
//1c
void LietKeUS(int n){
	printf("\nLiet ke cac uoc cua %d: ",n);
	for(int i=1; i<=n; i++)
		if(n % i == 0)
			printf("%d\t",i);
}
//1d
int Tong(int n){
	int s=0;
	for(int i=1; i<=n; i++)
		s = s + i;
		return s;
}
//1e
float TrungBinhCong(int n){
	int s=0;
	for(int i=1; i<=n; i++)
		s = s + i;
		return s;
}
int main(){
	int n;
	Nhap(n);
	LietKe(n);
	LietKeUS(n);
	printf("\nTong = %d",Tong(n));
	int x = TrungBinhCong(n);
	printf("\nTBC = %.1f",(float)x/n);
	return 0;
}
