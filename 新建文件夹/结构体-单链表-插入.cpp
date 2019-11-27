#include<stdio.h>
#include<stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

void insertNode(struct Node **head,int value)// 在单链表中，按照从小到大顺序，插入值为value的点， 
{
	struct Node *previous;
	struct Node *current;
	struct Node *newnode;//声明结构体指针  
	
	current=*head;
	previous=NULL;
	
	while(current!=NULL&&current->value<value)//确定插入位置 
	{
		previous=current;
		current=current->next;//current指向插入点之后，previous指向插入点之前 
	}
	
	newnode=(struct Node *)malloc(sizeof(struct Node));//新结点分配空间 
	if(newnode==NULL)
	{
		printf("内存分配失败\n");
		exit(1);
	}
	newnode->value=value;//新节点赋值 
	newnode->next=current;//新节点的后继 
	if(previous==NULL)//当前为空链表时 （注意这个函数里一开始一定是空链表） 
	{
		*head=newnode;
	 } 
	 else
	 {
	 	previous->next=newnode;//确定新节点的前驱 
	 }
	
 } 
 
 void deleteNode(struct Node **head,int value)//单链表中删除值为value的结点 
 {
 	struct Node *previous;
 	struct Node *current;
	 
	current=*head;
	previous=NULL;
	
	while(current!=NULL&&current->value!=value)//寻找待删除结点 
	{
		previous=current;
		current=current->next;
	} 
	if(current==NULL)
	{
		printf("找不到\n");
		return;
	 } 
	 else
	 {
	 	if(previous==NULL)//找到的是第一个结点 
	 	{
	 		*head=current->next; 
		 }
		 else
		 {
		 	previous->next=current->next;
		 }
		 free(current);
	 }
 }
  
 void printfNode(struct Node *head)
 {
 	struct Node *current;
 	current=head;
 	while(current!=NULL)
 	{
 		printf("%d ",current->value);
 		current=current->next;
	 }
	 putchar('\n');
 }

int main(void)
{
	struct Node *head=NULL;
	int input;
	printf("测试将整数插入单链表......\n");
	while(1)
	{
		printf("输入整数（输入-1表示结束）:");
		scanf("%d",&input);
		if(input==-1)
		{
			break;
		}
		insertNode(&head,input);
		printfNode(head);
	}
	putchar('\n');
	printf("测试将整数从单链表中删除......\n");
	while(1)
	{
		printf("输入整数（输入-1表示结束）:");
		scanf("%d",&input);
		if(input==-1)
		{
			break;
		}
		deleteNode(&head,input);
		printfNode(head);
	}
 } 
