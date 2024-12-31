#include <stdio.h>
//DINH NGHIA STACK
typedef int datatype;
typedef struct node
{
	datatype info;
	struct node *next;
}Node;
typedef Node* NODEPTR;
typedef NODEPTR STACK;
//STACK s;
//KHOI TAO
void init(STACK &s)
{
	s = NULL;
}
//KT RONG
int isEmpty(STACK s)
{
	return(s == NULL);
}
//TAO NODE
NODEPTR createNode(int x){
	NODEPTR p = new node;
	if( p == NULL){
		printf("Khong du bo nho!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
//THEM PT 
int push(STACK &s, datatype x)
{
	NODEPTR p = new Node;
	if(p == NULL)
		return 0;
	p->info = x;
	p->next = s;
	s = p;
	return 1;
}
//lAY PT
int pop(STACK &s, datatype &x)
{
	if(isEmpty(s))
		return 0;
	NODEPTR p = s;
	x = p->info;
	s = s->next;
	delete p;
	return 1;
}

void input(STACK &s, int n){
	for(int i = 0; i< n; i++){
		int x;
		printf("Nhap phan tu vao stack: ");
		scanf("%d", &x);
		node *p;
		p = createNode(x);
		pop(s, x);
	}
}
//void output(STACK q){
	//for(node *p = q.; p!= NULL; p=p->next){
		//printf("%d\t", p->data);
	//}
//}


//DOI THAP PHAN n SANG NHI PHAN
void convert(int n, STACK &s)
{
	int sodu;			//bien sodu khi chia n cho 2
	while(n != 0){
		sodu = n%2;		//n%2: 2(8,16...) la co so can chuyen doi
		//NODEPTR p = Node(sodu);
		push(s,sodu);	//OR pop(s,sodu);	p
		n = n/2;
	}
}
//XUAT DANG NHI PHAN	!!!
void output(STACK s)
{
	datatype x;
	while(s != NULL){
		pop(s,x);
		printf("%d",x);
	}
}




int main()
{
	//KHAI BAO CAC BIEN QUAN LY STACK
	STACK s;
	init(s);	//KHOI TAO STACK BAN DAU CHUA CO DATA
//ISEMPTY
	if(s == NULL)
		printf("\nEmpty stack");
	else
		printf("\nNot empty stack");
//PUSH
//	datatype x1,x2;
//	printf("\nNhap pt muon them vao STACK: ");	scanf("%d",&x1);
//	push(s,x1);
////POP
//	printf("\nNhap pt muon lay ra STACK: ");	scanf("%d",&x2);
//	pop(s,x2);
//CONVERT
	//NHAP SO NGUYEN CAN CHUYEN DOI
	datatype n;
	printf("\nNhap so o he thap phan: ");	scanf("%d",&n);
	convert(n,s);	//GOI HAM CHUYEN DOI
//OUTPUT
	output(s);		//XUAT SO NHI PHAN 
	return 0;
}
