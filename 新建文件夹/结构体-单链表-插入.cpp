#include<stdio.h>
#include<stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

void insertNode(struct Node **head,int value)// �ڵ������У����մ�С����˳�򣬲���ֵΪvalue�ĵ㣬 
{
	struct Node *previous;
	struct Node *current;
	struct Node *newnode;//�����ṹ��ָ��  
	
	current=*head;
	previous=NULL;
	
	while(current!=NULL&&current->value<value)//ȷ������λ�� 
	{
		previous=current;
		current=current->next;//currentָ������֮��previousָ������֮ǰ 
	}
	
	newnode=(struct Node *)malloc(sizeof(struct Node));//�½�����ռ� 
	if(newnode==NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	newnode->value=value;//�½ڵ㸳ֵ 
	newnode->next=current;//�½ڵ�ĺ�� 
	if(previous==NULL)//��ǰΪ������ʱ ��ע�����������һ��ʼһ���ǿ����� 
	{
		*head=newnode;
	 } 
	 else
	 {
	 	previous->next=newnode;//ȷ���½ڵ��ǰ�� 
	 }
	
 } 
 
 void deleteNode(struct Node **head,int value)//��������ɾ��ֵΪvalue�Ľ�� 
 {
 	struct Node *previous;
 	struct Node *current;
	 
	current=*head;
	previous=NULL;
	
	while(current!=NULL&&current->value!=value)//Ѱ�Ҵ�ɾ����� 
	{
		previous=current;
		current=current->next;
	} 
	if(current==NULL)
	{
		printf("�Ҳ���\n");
		return;
	 } 
	 else
	 {
	 	if(previous==NULL)//�ҵ����ǵ�һ����� 
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
	printf("���Խ��������뵥����......\n");
	while(1)
	{
		printf("��������������-1��ʾ������:");
		scanf("%d",&input);
		if(input==-1)
		{
			break;
		}
		insertNode(&head,input);
		printfNode(head);
	}
	putchar('\n');
	printf("���Խ������ӵ�������ɾ��......\n");
	while(1)
	{
		printf("��������������-1��ʾ������:");
		scanf("%d",&input);
		if(input==-1)
		{
			break;
		}
		deleteNode(&head,input);
		printfNode(head);
	}
 } 
