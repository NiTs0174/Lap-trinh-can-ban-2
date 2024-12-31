#include <stdio.h>
//3b so nguyen to
int Cau3b(int n){
	if(n < 2)
		return 0;
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
//3c so hoan thien
int Cau3c(int n){
	long s = 0;
	for(int i=1; i<n; i++)
		if(n % i == 0)
			s = s + i;
	if(s == n)
		return 1;
	return 0;
}

int main(){
    int n;
//3a
    do{
    	printf("Nhap n = ");
    	scanf("%d",&n);	
    	if(n<=0 || n>100)
    		printf("Nhap sai, nhap lai\n");
	} while(n<=0 || n>100);
//3b	
	int kt = Cau3b(n);
	if(kt == 1)
		printf("%d la so nguyen to",n);
	else
		printf("%d khong phai so nguyen to",n);
//3c
	int s = Cau3c(n);
	if(s == 1)
		printf("\n%d la so hoan thien",n);
	else
		printf("\n%d khong phai so hoan thien",n);
	return 0;
}
