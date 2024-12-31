//CAY
#include <stdio.h>
//DINH NGHIA CAU TRUC
typedef struct node
{
    int info;
    node* left;
    node* right;
}Node;
typedef Node* Tree;
Tree root;
//KHOI DONG
void init (Tree &root)
{ 
    root = NULL;
}
//KT RONG
int isEmpty(Tree root)
{
	return(root == NULL);
}
//TAO NUT
Node* createNode (int x){
    Node* p = new Node;
    if (p != NULL)
	{
        p->left = NULL;
        p->right = NULL;
        p->info = x;
    }
    return p;
}
//THEM NODE
int insertNode(Tree &root, Node*p)
{
    if (root != NULL){
        if (root->info==p->info)
            return 0;
        if (root->info > p->info)
            return insertNode(root->left, p);
        else
            return insertNode(root->right,p);
    }
	else
        root = p;
}
//NHAP NUT
void input(Tree &root){
    int n;
    printf ("NHAP SO LUONG NODE CUA CAY: "); 
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        int x;
        printf ("a[%d]: ",i+1); 
        scanf("%d",&x);
        Node* p = createNode(x);
        insertNode(root, p);
    }
}
//2. DUYET THEO NLR
void NLR(Tree root){
    if (root!=NULL){
        printf("%d \t",root->info);
        NLR(root->left);
        NLR(root->right);
    }
}
//3. TIM KIEM
Node* search(Tree root, int x)
{
//    Tree p;
//    if(root->info == x)	return root;
//    if(root == NULL)	return NULL;
//    p = search(root->left,x);
//    if(p == NULL)
//    	p = search(root->right,x);
//    return p;
	if(root!=NULL){
        if(root->info == x)
            return root;
        if(root->info > x)
            return search(root->left, x);
		else
            return search(root->right, x);
    }
    return NULL;
}
//4. CHEN
void insert(Node* &root, int x)
{
    if (root==NULL)
    	printf("\nNut khong ton tai");
    else
	{
        if (root->left != NULL)
        	printf("\nNut p da co con tro ben trai");
        else 
        	root->left = createNode(x);
    }	
}
//5. XOA
int deleteRight(Node* p)
{
	Node* q;
	int x;
	if(p == NULL)
		printf("\nNut khong ton tai");
	else{
		q=p->right;
		x = q->info;
		if(q == NULL)
			printf("\nNut p da co con tro ben phai");
		else{
			if(q->left!=NULL || q->right!=NULL)
				printf("\nNut khong phai la la");
			else{
				p->right = NULL;
				delete q;
			}
		}
	}
	return x;
}



int main(){
    Tree root;
    init(root);
    input(root);
//2. NLR
    printf("\nCAY DUYET THEO TIEN THU TU NLR:\n");
    NLR(root);
//3. SEARCH		VTsai
	int x1;
	printf("\nNhap node muon tim: ");	scanf("%d",&x1);
	Node* kt = search(root,x1);
	if(kt == NULL)
		printf("\nKhong tim thay!!");
	else
		printf("\nVi tri cua %d tai %d",x1,kt);
//4. INSERT
	int x;
	printf ("\nNHAP PT MUON CHEN: "); scanf("%d",&x);
	insert(root,x);
	printf("\nCAY DUYET THEO TIEN THU TU NLR sau khi CHEN TRAI: ");
	NLR(root);
//5. DELETE		!!!
	printf("\nCAY DUYET THEO TIEN THU TU NLR sau khi XOA PHAI: %d\n",deleteRight(root));
//NLR(root);
	return 0;
}
