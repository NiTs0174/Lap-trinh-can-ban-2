//CAY NHI PHAN TIM KIEM
#include <stdio.h>
//DN CAU TRUC
struct Node
{
    int data;
    Node* left;
    Node* right;
};
typedef struct Node* NODEPTR;
//KHOI DONG
void init (NODEPTR &root)
{
    root = NULL;
}
//KT RONG
int isEmpty(NODEPTR a)
{
	return(a == NULL);
}
//TAO NUT
Node* createNode (int x)
{
    Node* p = new Node;
    if (p != NULL)
	{
        p->left = NULL;
        p->right = NULL;
        p->data = x;
    }
    return p;
}
//THEM NODE
int insertNode(NODEPTR &root, Node*p)
{
    if (root != NULL)
	{
        if (root->data == p->data)
            return 0;
        if (root->data > p->data)
            return insertNode(root->left, p);
        else
            return insertNode(root->right,p);
    }
	else
        root = p;
}
//NHAP CAY
void input(NODEPTR &root){
    int n;
    do{
    	printf ("Nhap so luong NODE cua cay: "); 
    	scanf("%d",&n);
	}while(n < 0);
    for(int i=1; i<=n; i++)
	{
        int x;
        printf ("Nhap data cua NODE %d: ",i); 
        scanf("%d",&x);
        Node* p = createNode(x);
        insertNode(root,p);
    }
}
//DUYET CAY
void NLR(NODEPTR root)
{
    if (root != NULL)
	{
        printf("%d\t",root->data);
        NLR(root->left);
        NLR(root->right);
    }
}
//TIM KIEM
NODEPTR search(NODEPTR proot, int x)
{
	NODEPTR p = proot;
	if(p != NULL){
		if(x < proot->data)
			p = search(proot->left,x);
		else
			if(x > proot->data)
				p = search(proot->right,x);
	}
	return p;
}
//CHEN
void insert(NODEPTR &proot, int x)
{
	if(isEmpty(proot))
		proot = createNode(x);
	else
	{
		if(x == proot->data)
			return;
		if(x < proot->data)
			insert(proot->left,x);
		else 
			insert(proot->right,x);
	}
}
//XOA
int remove(NODEPTR &proot, int x)
{
	if(proot == NULL)
		return false;
	if(proot->data > x)
		return remove(proot->left,x);
	if(proot->data <x)
		return remove(proot->right,x);
	NODEPTR p,f,rp;
	p = proot;
	if(proot->left == NULL)
		proot = proot->right;
	else if(proot->right == NULL)
		proot = proot->left;
	else
	{
		f = p;
		rp = p->right;
		while(rp->left != NULL)
		{
			f = rp;
			rp = rp->left;
		}
		p->data = rp->data;
		if(f == p)
			f->right = rp->right;
		else
			f->left =rp->right;
		p = rp;
	}
	delete p;
	return true;
}
//XOA
//void FindReplNode(NODEPTR &p, NODEPTR &q)
//{
//    if(q->left)
//	{
//        FindReplNode(p,q->left);
//    }
//	else
//	{
//        p->data = q->data;
//        p = q;
//        q = q->right;
//    }
//}
//void DeleteNode(NODEPTR &root, int X)
//{
//    if(root== NULL)
//	{
//        return;
//    }
//    if(root->data > X)
//	{
//        return DeleteNode(root->left, X);
//    }
//    if (root->data < X)
//	{
//        return DeleteNode(root->right, X);
//    }
//    Node* p = root;
//    if(root->left == NULL)
//	{
//        root = root->right;
//    }else if(root->right == NULL)
//	{
//        root = root->left;
//    }
//	else
//	{
//        FindReplNode (p, root->right);
//    }
//    delete p;
//}



int main(){
    NODEPTR root;
    init(root);
//INPUT
	input(root);
//DUYET NLR
    printf("CAY DUYET THEO THU TU NLR:\n");
    NLR(root);
//SEARCH
	int x;
	printf("\nNhap gia tri can tim: ");	scanf("%d",&x);
	NODEPTR p = search(root,x);
	if(p == NULL)
		printf("\nKhong tim thay!!");
	else
		printf("\nTim thay gia tri");
//INSERT
	int x2;
	printf("\nNhap gia tri can them: ");	scanf("%d",&x2);
	printf("\nCAY SAU KHI THEM: ");
	insert(root,x2);
	NLR(root);
//REMOVE
	int x3;
	printf("\nNhap gia tri can xoa: ");	scanf("%d",&x3);
	remove(root,x3);
	printf("\nCAY SAU KHI XOA: ");
	NLR(root);
	return 0;
}
