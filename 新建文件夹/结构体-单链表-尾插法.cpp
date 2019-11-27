#include<stdio.h>
#include<stdlib.h>

void getinput(struct Book *book);
void addbook(struct Book **library);
void printflibrary(struct Book *library);
void releselibrary(struct Book **library);

struct Book {
	char title[128];
	char author[48];
	struct Book *next;
};//单链表

void getinput(struct Book *book)//传递的参数是结构体指针 
{
	printf("输入书名：");
	scanf("%s",book->title); 
	printf("输入作者：");
	scanf("%s",book->author);
}

void addbook(struct Book **library)//传递头指针head的地址 
{
	struct Book *book;//定义结构体指针 ，局部变量 
	static struct Book *tail;//定义静态的指针，使之指向单链表的尾部  
	
	book=(struct Book *)malloc(sizeof(struct Book));//分配空间 ，注意类型转换 
	if(book==NULL)//分配失败 
	{
		printf("内存分配失败\n");
		exit(1);
	}
	
	getinput(book);
	
	
	//尾插法 
	if(*library==NULL)//空链表 ，只有头指针，library是头指针，*library是第一个元素的地址 
	{
		*library=book;//注意book是指针，这里是传递地址 
		book->next=NULL; 
	}
	else//非空链表 
	{
		tail->next=book;
		book->next=NULL; 	
	}
	tail=book; 
 } 
 

void printflibrary(struct Book *library)//注意这里传递的不是library的地址，而是library本身 
{
	struct Book *book;
	int count=1;
	
	book=library;
	while(book!=NULL) //不是空指针
	{
		printf("book %d:\n",count);
		printf("书名：%s",book->title);
		printf("作者：%s\n",book->author);
		book=book->next;
		count++;
	 } 
} 


void releselibrary(struct Book **library)
{
	struct Book *temp;
	 
	while(*library!=NULL)
	{
		temp=*library;
		*library=(*library)->next;
		free(temp);;
	}
}


int main(void)
{
	struct Book *library=NULL;//定义为头指针空指针 
	char ch;
	
	while(1)
	{
		printf("是否输入书籍（Y/N）:");
		do
		{
			ch=getchar();
		}while(ch!='Y'&&ch!='N');
		if(ch=='Y')
		{
			addbook(&library);//传递头指针自身的地址 
		}
		else
		{
			break;
		}
	}
	
	printf("是否打印（Y/N）\n");
	do
		{
			ch=getchar();
		}while(ch!='Y'&&ch!='N');
		
		if(ch=='Y')
		{
			printflibrary(library);
		}
	releselibrary(&library);
	
	
 } 
