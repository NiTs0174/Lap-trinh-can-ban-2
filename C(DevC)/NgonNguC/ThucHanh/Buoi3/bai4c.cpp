//4c
#include<stdio.h>
int main()
{
	int n;
	int s = 0;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	} while(n<=0 || n>=100);
    for(int i=1; i<=n/2; i++){
        if(n%i==0){
            s+=i;
    	}
    }
    if(s == n){
	printf("%d la so hoan hao.",n);
	}
    else{
        printf("%d khong phai so hoan hao.",n);
	}
	return 0;
}
