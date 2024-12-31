#include<stdio.h>
//Thap Ha Noi
void ThapHN(int n, char a, char b, char c){//chuyen n dia tu A sang B, Thap trung gian C
	if(n == 1){
		printf("\n%c --> %c",a,b);
		return;
	}
	//de giai bai toan: chuyen n dia chuyen tu a sang b
	//thuat toan lam 3 buoc
	
	//1. dung B lam trung gian, chuyen n-1 sang C
	ThapHN(n-1,a,c,b);
	//2. Chuyen 1 dia lon nhat tu A sang B, C lam trung gian
	ThapHN(1,a,b,c);
	//3. Chuyen n-1 dia tu c sang b, a trung gian
	ThapHN(n-1,c,b,a);
}

int main()
{
	char a ='A',b ='B',c ='C';
	int n;
	printf("Nhap so dia muon chuyen: ");	scanf("%d",&n);
	ThapHN(n,a,b,c);
	return 0;
}
