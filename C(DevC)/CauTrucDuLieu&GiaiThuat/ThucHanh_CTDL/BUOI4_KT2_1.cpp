#include <stdio.h>
//DINH NGHIA CAU TRUC
typedef struct infotype{
	char mabd[10];
	char tenbd[25];
	float tl;
}BK;
typedef struct node{
    int key;
    BK info;
    struct node* left;
    struct node* right;
}Node;
typedef Node* NODEPTR;
//KHOI DONG
void init(Node* &root)
{ 
    root = NULL;
}
//KT RONG
int isEmpty(Node* root)
{
	return(root == NULL);
}
//TAO NUT
Node* createNode (infotype x)
{
    Node* p = new Node;
    if(p != NULL)
	{
        p->left = NULL;
        p->right = NULL;
		p->info = x;
   	}
    return p;
}
//NHAP 1 BK
void nhap1bk(BK x)
{
	printf("\nMa buu kien: ");	scanf("%s",&x.mabd);
	printf("Ten buu kien: ");	fflush(stdin);	gets(x.tenbd);
	printf("Trong luong: ");	scanf("%f",&x.tl);
}
//XUAT 1 BK
void xuat1bk(BK x)
{
	printf("%-11s%-25s%.2f",x.mabd,x.tenbd,x.tl);
}
//NHAP DSBK
void nhapdsbk(BK a[],int n)
{
	for(int i=0; i<n; i++)
	{
		printf("BK thu %d: ",i+1);
		nhap1bk(a[i]);
	}
}
//XUAT DSBK
void xuatdsbk(BK a[], int n)
{
	for(int i=0; i<n; i++)
		xuat1bk(a[i]);
}

//TAO CAY
void createTree(NODEPTR &proot, BK a[], int begin, int end)
{
	if(begin>end)	return;
	int i = (begin+end)/2;
	proot = createNode(a[i]);
	createTree(proot->left,a,begin,i-1);
	createTree(proot->right,a,i+1,end);
}
//DUYET THEO THU TU TRUOC NLR
void LRN(Node* root){
    if (root!=NULL){
        LRN(root->left);
        LRN(root->right);
        printf("%d \t",root->info);
    }
}



int main(){
    Node* root;
    BK a[100];
    int n;
    do{
    	printf ("NHAP SO LUONG BK: "); 
		scanf("%d",&n);
	}while(n<0);
    nhapdsbk(a,n);
    int begin=0, end=n-1;
    createTree(root,a,begin,end);
    printf("\nCAY DUYET THEO TIEN THU TU: ");
    LRN(root);
}
