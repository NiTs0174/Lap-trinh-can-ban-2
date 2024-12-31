//2d2
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	long s=0, t=-1;
	do{
		printf("Nhap n: ");
		scanf("%d",&n); 
	} while(n<=0);
	for(int i=1; i<=n; i++){
		s=s+t*i;
		t=t*(-1);
	}
	printf("s = %ld",s);
	return 0;
}
