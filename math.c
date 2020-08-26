#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int data;//数据域
	struct Node *PNext;//指针域
}Node,*PNode;
PNode  create_list(void);
void traverse_list(PNode pHead);
bool is_empty(PNode pHead);
int length_list(PNode pHead);
void sort_list(PNode);
int main(void){
	PNode pHead=NULL;
	pHead=create_list();
	traverse_list(pHead);
	int len=length_list(pHead);
	printf("链表的长度是%d",len);

	return 0;
}
PNode  create_list(void){
	int count;
	int value;
	PNode PHead=(PNode)malloc(sizeof(Node));//分配了一个不存放有效数据的头结点
	PNode PTail=PHead;//Tail和PHead都指向头结点
	PTail->PNext=NULL;//把头结点指针域清空
	
	if(NULL==PHead){
		printf("分配失败，程序终止！");

	}
	printf("请输入要创建的节点数:count=");
	scanf("%d",&count);
	for(int i=0;i<count;i++){
		printf("输入第%d节点的值:",i+1);
		scanf("%d",&value);
		PNode PNew=(PNode)malloc(sizeof(Node));
		if(NULL==PNew){
		printf("分配失败，程序终止！");
	
	}
		PNew->data=value;
		PTail->PNext=PNew;
		PNew->PNext=NULL;
		PTail=PNew;

	}
	return PHead;

}
void traverse_list(PNode pHead){
	PNode p=pHead->PNext;//p指向第一个有效节点
	while(p!=NULL){
		printf("%d",p->data);
		p=p->PNext;

	}
	printf("\n");
}
bool is_empty(PNode pHead){
	if(pHead->PNext==NULL)
		return true;
	else
		return false;
}
int length_list(PNode pHead){
	int len=0;
	PNode p=pHead->PNext;
	while(p!=NULL){
		++len;
		p=p->PNext;
	}
	return len;
}
void sort_list(PNode){

}
