//CAY NHI PHAN TONG QUAT
#include <stdio.h>
typedef int datatype;
typedef struct nodetype
{
	datatype info;
	struct nodetype *left;
	struct nodetype *right;
}Node;
typedef Node *NODEPTR; 
//KHOI DONG
void init(NODEPTR &a)
{
	a = NULL;
}
//KT RONG
int isEmpty(NODEPTR a)
{
	if(a == NULL)
		return 1;
	return 0;
}
//TAO NUT
NODEPTR createNode(datatype x)
{
	NODEPTR p = new Node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
//NHAP CAY
void input(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Nhap so can them vao danh sach: ");
		scanf("%d",&a[i]);
	}
}
//TAO CAY
void createTree(NODEPTR &proot, int a[], int begin, int end)
{
	if(begin > end)
		return;
	int i = (begin+end)/2;
	proot = createNode(a[i]);
	createTree(proot->left,a,begin,i-1);
	createTree(proot->right,a,i+1,end);
}
//DUYET THEO NLR
void preOder(NODEPTR proot)
{
	if(proot != NULL)
	{
		printf("%4d",proot->info);
		preOder(proot->left);
		preOder(proot->right);
	}
}
//DUYET THEO LNR
void inOder(NODEPTR proot)
{
	if(proot != NULL)
	{
		inOder(proot->left);
		printf("%4d",proot->info);
		inOder(proot->right);
	}
}
//DUYET THEO LRN
void postOder(NODEPTR proot)
{
	if(proot != NULL)
	{
		postOder(proot->left);
		postOder(proot->right);
		printf("%4d",proot->info);
	}
}
//TIM KIEM
NODEPTR search(NODEPTR proot,datatype x)
{
//	NODEPTR p;
//	if(proot->info==x)	return proot;
//	if(proot == NULL)	return NULL;
//	p = search(proot->left,x);
//	if(p == NULL)
//		p = search(proot->right,x);
//	return p;
	if(proot != NULL)
	{
        if(proot->info == x)
            return proot;
        if(proot->info > x)
            return search(proot->left, x);
		else
            return search(proot->right, x);
    }
    return NULL;	
}
//THEM TRAI
void insertLeft(NODEPTR &p,datatype x)
{
	if(p == NULL)
		printf("\nNut khong ton tai");
	else
	{
		if(p->left != NULL)
			printf("\nNut p da co con ben trai");
		else
			p->left = createNode(x);
	}	
}
//THEM PHAI
void insertRight(NODEPTR &p,datatype x)
{
	if(p == NULL)
		printf("\nNut khong ton tai");
	else
	{
		if(p->right != NULL)
			printf("\nNut da co con ben phai");
		else
		p->right = createNode(x);	
	}
}
//XOA TRAI
int deleteLeft(NODEPTR p)
{
	NODEPTR q;
	int x;
	if(p == NULL)
		printf("\n Nut khong ton tai");
	else
	{
		q = p->left;
		x = q->info;
		if(q == NULL)
			if("\n Nut khong co con ben trai ");
		else
		{
			if(q->left != NULL || q->right != NULL)
				printf("\n Nut khong phai la");
			else
			{
				p->left = NULL;
				delete q;
			}
		}
	}
	return x;
}
//XOA PHAI
int deleteRight(NODEPTR p)
{
	NODEPTR q;
	int x;
	if(p == NULL)
		printf("\n Nut khong ton tai");
	else
	{
		q = p->right;
		x = q->info;
		if(q = NULL)
			printf("\nNut khong co con ben phai ");
		else
		{
			if(q->left != NULL || q->right != NULL)
				printf("\nNut khong phai la la");
			else
			{
				p->right = NULL;
				delete q;
			}
		}
	}
	return x;
}
//XOA CAY
void clearTree(NODEPTR &proot)
{
	if(proot != NULL)
	{
		clearTree(proot->left);
		clearTree(proot->right);
		delete proot;
	}
}



int main()
{
	NODEPTR proot;
	int a[100];
//Input
	int n;
	do{	
		printf("\nNhap so luong phan tu: ");
		scanf("%d",&n);
	}while(n < 0);
	input(a,n);
	int begin = 0, end = n-1;
	createTree(proot,a,begin,end);
//NLR
	printf("\nDuyet cay theo NLR: ");
	preOder(proot);
//LNR
	printf("\nDuyet cay theo LNR: ");
	inOder(proot);
//LRN
	printf("\nDuyet cay theo LRN: ");
	postOder(proot);
//SEARCH
	datatype x;
	printf("\nNhap gia tri can tim: ");	scanf("%d", &x);
	NODEPTR p = search(proot,x);
    if(p != NULL) 
		printf("\nTim thay gia tri trong cay");
    else
		printf("\nKhong tim thay ket qua!!");
//INSERT LEFT
	datatype x1;
	printf("\nNhap gia tri can them: ");	scanf("%d", &x1);
	insertLeft(proot,x1);
	printf("\nDS cay sau khi them: ");
	preOder(proot);
//INSERT RIGHT
	datatype x2;
	printf("\nNhap gia tri can them: ");	scanf("%d", &x2);
	insertRight(proot,x2);
	printf("\nDS cay sau khi them: ");
	preOder(proot);
//DELETE LEFT
	printf("\nXoa trai: %d",deleteLeft(proot));
//DELETE RIGHT
	printf("\nXoa phai: %d",deleteRight(proot));
//CLEAR TREE
	//clearTree(proot);
	//printf("\nDa xoa cay!!");
	return 0;
}
