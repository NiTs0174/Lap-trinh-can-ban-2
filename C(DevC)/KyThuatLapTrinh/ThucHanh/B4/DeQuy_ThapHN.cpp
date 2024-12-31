#include<stdio.h>
//Thap Ha Noi
void ThapHN(int n, char a, char b, char c){
	if(n == 1){
		printf("\n%c --> %c",a,b);
		return;
	}
	ThapHN(n-1,a,c,b);
	ThapHN(1,a,b,c);
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
