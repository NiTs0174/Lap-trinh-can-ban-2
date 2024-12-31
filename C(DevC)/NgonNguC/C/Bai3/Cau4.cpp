#include<stdio.h>
void SoDong(int &n){
	do{
		printf("Nhap so dong: ");
		scanf("%d",&n);
		if(n<=0 || n>10)
			printf("Nhap sai, nhap lai");
	} while(n<=0 || n>10);
}
//4a
void Cau4a(int n){
	int k;
	printf("Nhap so *: ");
	scanf("%d",&k);
	for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            printf("*");
        }
		printf("\n");
	}
}
//4b
void Cau4b(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
        	printf("*");
    	}
    	printf("\n");
	}
}

int main()
{
	int n,k;
//4a
	SoDong(n);
	Cau4a(n);
//4b
	SoDong(n);
	Cau4b(n);
	return 0;
}
