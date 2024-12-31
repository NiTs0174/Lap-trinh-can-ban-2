#include <stdio.h>
//DN CAU TRUC
typedef int infotype;
typedef struct node
{
    infotype data;
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
	return(proot == NULL);
}
//2.TAO NUT
ptree createNode (infotype x)
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
//THEM NODE
int insertNode(ptree &proot, Node* p)
{
    if (proot != NULL)
	{
        if (proot->data == p->data)	return 0;
        if (proot->data > p->data)	return insertNode(proot->left,p);
        else						return insertNode(proot->right,p);
    }
	else	proot = p;
}
//5. TAO CAY TU MANG NGUYEN
void array2Tree1(ptree &proot, int arr[], int n)
{
    printf ("\nNHAP SO LUONG NODE CUA CAY 2: "); 
    scanf("%d",&n);
    for(int i=0; i<n;i++)
	{
        printf ("Nhap Node thu %d: ",i+1);
        scanf("%d",&arr[i]);
        Node* p = createNode(arr[i]);
        insertNode(proot,p);
    }
}
//4. NHAP MANG NGUYEN KICH THUOC n
void inputArr(int arr[],int &n)
{
    printf ("Nhap so luong NODE cua cay 1: ");	
	scanf("%d",&n);
    for(int i=0; i<n; i++)
	{
        printf ("Nhap Node thu %d: ",i+1); 
        scanf("%d",&arr[i]);
    }
}
//6. TAO CAY TU MANG NGUYEN VOI...
void array2Tree2(ptree &proot, int arr[], int begin, int end)
{
    if(begin > end)	return;
    int i = (begin+end)/2;
    proot = createNode(arr[i]);
    array2Tree2(proot->left,arr,begin,i-1);
    array2Tree2(proot->right,arr,i+1,end);
}
//7. DUYET NLR
void preorder(ptree proot)
{
    if (proot!=NULL)
	{
        printf("%4d",proot->data);
        preorder(proot->left);
        preorder(proot->right);
    }
}
//8. DUYET LNR
void inorder(ptree proot)
{
    if (proot!=NULL)
	{
        inorder(proot->left);
        printf("%4d",proot->data);
        inorder(proot->right);
    }
}
//9. DUYET LRN
void posorder(ptree proot)
{
    if (proot!=NULL)
	{
        posorder(proot->left);
        posorder(proot->right);
        printf("%4d",proot->data);
    }
}
//10. DEM NODE
int countNode(ptree proot) 
{
   if(proot == NULL)	return 0;
   else					return 1+countNode(proot->left)+countNode(proot->right);
}
//11. DEM LA
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
//12. CHEN
int insertBST(ptree proot, infotype x)
{
    if (proot == NULL)
    	printf("\nNut khong ton tai");
    else
	{
        if (proot->left != NULL)
        	printf("\nNut p da co con tro ben trai");
        else 
        	proot->left = createNode(x);
    }	
}



int main(){
    ptree proot,q;
    int arr[100];
	int n;
	init(proot);
////4-6. TAO CAY 1
    inputArr(arr,n);
    int begin = 0, end = n-1;
    array2Tree2(proot,arr,begin,end);
//7. PREODER
    printf("\nCAY 1 DUYET THEO TIEN THU TU NLR:\n");
    preorder(proot);
//8. INORDER
    printf("\nCAY 1 DUYET THEO TIEN THU TU LNR:\n");
    inorder(proot);
//9. POSORDER
    printf("\nCAY 1 DUYET THEO TIEN THU TU LRN:\n");
    posorder(proot);
//5. TAO CAY 2
	int m;
	array2Tree1(q,arr,m);
//7. PREODER
    printf("\nCAY 2 DUYET THEO TIEN THU TU NLR:\n");
    preorder(proot);
//8. INORDER
    printf("\nCAY 2 DUYET THEO TIEN THU TU LNR:\n");
    inorder(proot);
//9. POSORDER
    printf("\nCAY 2 DUYET THEO TIEN THU TU LRN:\n");
    posorder(proot);
//10. DEM NODE
	printf("\nSo NODE tren cay 1: %d",countNode(proot));
//11. DEM LA
	printf("\nSo NODE la tren cay 1: %d",countLeafNode(proot));
//12. THEM NODE
	infotype x;
	printf("\nNhap node can them vao cay 2: ");	scanf("%d",&x);
	insertBST(q,x);
	preorder(q);
	return 0;
}
