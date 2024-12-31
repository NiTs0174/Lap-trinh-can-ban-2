//LIBRARY
#include <stdio.h>
//DN CAU TRUC
typedef struct SinhVien
{
	int mssv;
	char hoten[25];
	float toan,ly,hoa;
}SV;
typedef struct node
{
    SV data;
    node* left;
    node* right;
}Node;
typedef Node *ptree;
//1. KHOI DONG
void init(ptree &proot)
{ 
    proot = NULL;
}
//3. KT RONG
bool isEmpty(ptree proot)
{
	if(proot == NULL)
		return 0;
	return 1;
}
//2.TAO NUT
ptree createNode (SV x)
{
    ptree p = new Node;
    if (p != NULL)
	{
        p->left = NULL;
        p->right = NULL;
        p->data = x;
    }
    return p;
}
//4. NHAP 1 SV
void input1SV(SV &x)
{
	printf("\nMSSV: ");	scanf("%d",&x.mssv);
	printf("Ho ten: ");	fflush(stdin);	scanf("%s",&x.hoten);
	printf("Toan: ");	scanf("%f",&x.toan);
	printf("Ly: ");	scanf("%f",&x.ly);
	printf("Hoa: ");	scanf("%f",&x.hoa);
}
//XUAT 1 SV
void output1SV(SV x)
{
	printf("\n%-12d%-21s%4.1f%4.1f%4.1f",x.mssv,x.hoten,x.toan,x.ly,x.hoa);
}
//5. TAO NODE CAY BT
void insertBT(ptree &proot, SV x)
{
	if(proot == NULL)
		proot = createNode(x);
	else
		if(proot->right != NULL)
			printf("\nDa co nut ben trai");
		else 
			proot->right = createNode(x);
}
//7. TAO MANG SV CAY 1
void array2Tree1(ptree &proot, SV arr[], int n)
{
    printf ("\nNHAP SO LUONG SV CAY 1: "); 
    scanf("%d",&n);
    for(int i=0; i<n;i++)
	{
        printf ("\tNhap SV thu %d: ",i+1);
        input1SV(arr[i]);
        Node* p = createNode(arr[i]);
        insertBT(proot,arr[i]);
    }
}
//6. NHAP MANG SV
void inputArr(SV arr[],int &n)
{
    printf ("\nNhap so luong SV CAY 2: ");	
	scanf("%d",&n);
    for(int i=0; i<n; i++)
	{
        printf ("\tNhap SV thu %d: ",i+1); 
        input1SV(arr[i]);
    }
}
//8. TAO MANG SV CAY 2
void array2Tree2(ptree &proot, SV arr[], int begin, int end)
{
    if(begin > end)	return;
    int i = (begin+end)/2;
    proot = createNode(arr[i]);
    array2Tree2(proot->left,arr,begin,i-1);
    array2Tree2(proot->right,arr,i+1,end);
}
//9. DUYET NLR
void preorder(ptree proot)
{
    if (proot!=NULL)
	{
        output1SV(proot->data);
        preorder(proot->left);
        preorder(proot->right);
    }
}
//10. DUYET LNR
void inorder(ptree proot)
{
    if (proot!=NULL)
	{
        inorder(proot->left);
        output1SV(proot->data);
        inorder(proot->right);
    }
}
//11. DUYET LRN
void posorder(ptree proot)
{
    if (proot!=NULL)
	{
        posorder(proot->left);
        posorder(proot->right);
        output1SV(proot->data);
    }
}
//12. DEM NODE
int countNode(ptree proot) 
{
   if(proot == NULL)	return 0;
   else					return 1+countNode(proot->left)+countNode(proot->right);
}
//13. DEM LA
//Kiem tra  nut la
char isLeaf(ptree proot){
   return (proot->left == NULL) && (proot->right == NULL);
}
//Dem nut la
int countLeafNode(ptree proot) 
{
   if(proot == NULL)	return 0;
   else{
       if(isLeaf(proot))	return 1;	
	   else					return countLeafNode(proot->left)+countLeafNode(proot->right);
   }
}
//14. CHEN BST
void insertBST(ptree &proot, SV x)
{
    if(isEmpty(proot))
    	proot = createNode(x);
    else 
    	if(x.mssv == proot->data.mssv)
    		return;
    	if(x.mssv < proot->data.mssv)
    		insertBST(proot->left,x);
    	else
    		insertBST(proot->right,x);    		
}
//15. TAO CAY 3
void createBST(ptree &proot, SV a[], int n)
{
    printf ("\nNHAP SO LUONG SV CAY 3: "); 
    scanf("%d",&n);
    for(int i=0; i<n;i++)
	{
        printf ("\tNhap SV thu %d: ",i+1);
        input1SV(a[i]);
        Node* p = createNode(a[i]);
        insertBST(proot,a[i]);
    }
}


int main(){
    ptree proot,q,q2;
	SV x,x2;
    SV arr[100];
    SV a[100];
    SV a2[100];
	int n,m,m2;
//1. INIT
	init(proot);
	init(q);
//2. CREATENODE
	createNode(x);
	//createNode(x2);
//3. ISEMPTY
	if(isEmpty(proot))
		printf("\nEmpty");
	else
		printf("\nNot Empty");
//4. INPUT1SV
	input1SV(x);
	printf("\nSINH VIEN VUA NHAP:");
	output1SV(x);
//5. INSERTBT CAY 1
	insertBT(q,x);
//7. ARRAY2TREE1
	array2Tree1(q,a,m);
    printf("\nDANH SACH SINH VIEN CAY 1:");
    inorder(q);
//6. INPUTARR CAY 2
    inputArr(arr,n);
//8. ARRAY2TREE2
    int begin=0, end=n-1;
    array2Tree2(proot,arr,begin,end);
//9. PREORDER
	printf("\nDANH SACH SINH VIEN CAY 2:");
    printf("\nDANH SACH SINH VIEN(PREODER):");
    preorder(proot);
//10. INODRER
    printf("\nDANH SACH SINH VIEN(INORDER):");
    inorder(proot);
//11. POSORDER
    printf("\nDANH SACH SINH VIEN(POSORDER):");
    posorder(proot);
//12. COUNTNODE
	printf("\nSo NODE tren cay 2: %d",countNode(proot));
//13. COUNTLEAF
	printf("\nSo NODE la tren cay 2: %d",countLeafNode(proot));
//14. CREATEBST
//	input1SV(x2);
//	insertBST(q2,x2);
//15. createBST
//	createBST(q2,a2,m2);
//	printf("\nDANH SACH SINH VIEN CAY 3:");
//	inorder(q2);
	return 0;
}
