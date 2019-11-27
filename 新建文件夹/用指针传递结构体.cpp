#include<stdio.h>
struct Date
	{
		int year;
		int month;
		int day;
	};
	struct Book 
	{
		char title[128];
		char author[48];
		float price;
		struct Date date;
		char publisher[48];
	};//声明结构体框架 
	
	void *getinput(struct Book *book) //参数为结构体指针，即结构体的地址 
	{
		printf("输入书名：");
		scanf("%s",book->title);
		printf("输入作者:");
		scanf("%s",book->author);
		printf("输入售价:");
		scanf("%f",&book->price); 
		//getchar();
		printf("输入日期：");
		scanf("%d %d %d",&book->date.year,&book->date.month,&book->date.day);
		//getchar();
		printf("输入出版社：");
		scanf("%s",book->publisher);
	
		return book;
	}
	
	void printfbook(struct Book *book)//注意函数类型是void,参数类型是Book结构体 
	{
		printf("书名：%s\n",book->title);
		printf("作者：%s\n",book->author);
		printf("售价：%.2f\n",book->price);
		printf("日期：%d-%d-%d\n",book->date.year,book->date.month,book->date.day);
		printf("出版社：%s\n",book->publisher);
	}


int main(void)
{
	struct Book b1,b2;//定义结构体 
	
	printf("输入第一本:\n");
	getinput(&b1);//将结构体b1的地址作为参数传递  
	putchar('\n');
	printf("输入第二本:\n");
	getinput(&b2);
	putchar('\n'); 
	
	printf("输入完毕，开始打印.......\n");
	putchar('\n');
	printf("第一本：\n");
	printfbook(&b1);
	putchar('\n');
	putchar('\n');
	printf("第二本：\n");
	printfbook(&b2);
	
 } 
